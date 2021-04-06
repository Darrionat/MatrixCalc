//
// Created by Darrion on 4/5/2021.
//
#include "Matrix.h"
#include "KeyValue.h"

int Matrix::det() {
    if (rows != cols) {
        cout << "ERROR: The determinant cannot be calculated for non-square matrices." << endl;
        return 0;
    }
    // Single matrix, determinant == the value
    if (rows == 1) return getValue(0, 0);

    int mostZerosCol = getMostZerosCol();
    // The sum in the cofactor expansion process
    int sum = 0;
    for (int row = 0; row < rows; row++) {
        // Zero does not matter in multiplication
        int scalar = getValue(row, mostZerosCol);
        if (scalar == 0)
            continue;
        // The value to multiply the remaining matrix by
        scalar *= pow(-1, mostZerosCol + row);

        Matrix matrix = createIJMinorMatrix(mostZerosCol, row);
        //matrix.print();
        sum += scalar * matrix.det();
    }
    return sum;
}

int Matrix::det2() {
    if (rows != cols) {
        cout << "ERROR: The determinant cannot be calculated for non-square matrices." << endl;
        return 0;
    }
    // The sum in the cofactor expansion process
    int sum = 0;
    stack<KeyValue<int, Matrix>> stack;

    stack.push(KeyValue<int, Matrix>(1, *this));
    while (!stack.empty()) {
        int detScalar = stack.top().getKey();

        Matrix matrix = stack.top().getValue();

        if (matrix.rows == 1) {
            clog << "popped stack in row==1" << endl;
            sum += detScalar * matrix.getValue(0, 0);
            stack.pop();
            continue;
        }
        int mostZerosCol = matrix.getMostZerosCol();
        stack.pop();

        for (int row = 0; row < matrix.rows; row++) {
            // Zero does not matter in multiplication
            int scalar = matrix.getValue(row, mostZerosCol);
            if (scalar == 0)
                continue;
            // The value to multiply the remaining matrix by
            scalar *= pow(-1, mostZerosCol + row);

            Matrix minorMatrix = matrix.createIJMinorMatrix(mostZerosCol, row);
            //free(matrix.colVectors);
            KeyValue<int, Matrix> minorKV(detScalar * scalar, minorMatrix);
            stack.push(minorKV);
        }
    }

    return sum;
}

Matrix Matrix::createIJMinorMatrix(int skipCol, int skipRow) {
    Matrix matrix(rows - 1, cols - 1);

    for (int col = 0; col < cols; col++) {
        if (col == skipCol) continue;
        Vector colVector = getColVector(col);
        Vector removedRowVec = colVector.removeRow(skipRow);
        if (col < skipCol)
            matrix.setColVector(col, removedRowVec);
        else
            matrix.setColVector(col - 1, removedRowVec);
    }
    return matrix;
}

int Matrix::getMostZerosCol() {
    int mostZerosCol = 0;
    int maxZeros = 0;
    for (int col = 0; col < cols; col++) {
        Vector vec = colVectors[col];
        int zeros = 0;
        for (int i = 0; i < vec.getDimension(); i++) {
            if (vec.getCoord(i + 1) == 0)
                zeros++;
        }
        if (zeros > maxZeros) {
            mostZerosCol = col;
            maxZeros = zeros;
        }
    }
    return mostZerosCol;
}

void Matrix::scale(int scalar) {
    for (int col = 0; col < cols; col++) {
        Vector v = getColVector(col);
        v.scale(scalar);
    }
}

void Matrix::print() {
    cout << rows << "x" << cols << " Matrix" << endl;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (col == 0)
                cout << getValue(row, col);
            else
                cout << "\t" << getValue(row, col);
        }
        cout << endl;
    }
}