//
// Created by Darrion on 4/5/2021.
//

#ifndef MATRIXCALC_VECTOR_H
#define MATRIXCALC_VECTOR_H

#include <iostream>

using namespace std;

class Vector {
public:
    int dim;
    int *coords;

    Vector() {}

    Vector(int dim) : dim(dim) {
        this->coords = new int[dim];
    }

    int getDimension() {
        return dim;
    }

    /**
     * Gets a new Vector that does not contain the particular row
     * @param row The row to remove
     */
    Vector removeRow(int row);

    /**
    * Gets the coordinate of a certain dimension of a vector.
    * @param coord The dimension of the coordinate, starting at 1.
    * @return Return the value for that dimension.
    */
    int getCoord(int dim);

    /**
     * Sets the coordinate of a vector
     * @param coord The dimension of the coordinate to set, starting at 1
     * @param value The value of the coordinate
     */
    void setCoord(int coord, int value);

    /**
     * Scales a vector by a constant
     * @param scalar The constant to scale by
     */
    void scale(int scalar);

    void print();
};

#endif //MATRIXCALC_VECTOR_H