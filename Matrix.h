//
// Created by Darrion on 4/5/2021.
//

#ifndef MATRIXCALC_MATRIX_H
#define MATRIXCALC_MATRIX_H

#include "Vector.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/**
 * Represents a mxn matrix with column vectors.
 */
class Matrix {
public:
    int rows;
    int cols;

    Vector *colVectors = nullptr;

    /**
     * Creates a new mxn Matrix
     * @param rows The amount of rows
     * @param cols The amount of columns
     */
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        this->colVectors = (Vector *) malloc(sizeof(Vector) * cols);
    }

    /**
     * Gets the Vector at the given column
     * @param col The column of the Vector
     * @return  Returns the Vector within that column
     */
    Vector getColVector(int col) {
        return colVectors[col];
    }

    /**
     * Sets a defined column vector in a particular column
     * @param col The column to set the Vector in
     * @param vector The vector
     */
    void setColVector(int col, Vector vector) {
        colVectors[col] = vector;
    }

    /**
     * Calculates the determinant of the matrix using cofactor expansion.
     * @return Returns the determinant of the matrix.
     */
    int det();

    /**
     * Gets the value at a given coordinate
     * @param row The row of the matrix. Starting at 0
     * @param col The column of the matrix. Starting at 0.
     * @return  The value at the specified row and column
     */
    int getValue(int row, int col) {
        Vector v = colVectors[col];
        return v.getCoord(row);
    }

    void print();

private:
    /**
     * Gets the column vector within the Matrix with the most amount of zeros
     * @return Returns the column that has the most zeros in it
     */
    int getMostZerosCol();

    /**
     * Create an IJ minor matrix
     * @param skipCol The column to not include
     * @param skipRow The row to not include
     * @return Returns an IJ minor matrix excluding a row and column
     */
    Matrix createIJMinorMatrix(int skipCol, int skipRow);
};

#endif //MATRIXCALC_MATRIX_H