//
// Created by Darrion on 4/5/2021.
//
#include "Matrix.h"

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
            if (vec.getCoord(i) == 0)
                zeros++;
        }
        if (zeros > maxZeros) {
            mostZerosCol = col;
            maxZeros = zeros;
        }
    }
    return mostZerosCol;
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