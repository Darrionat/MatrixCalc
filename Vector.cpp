//
// Created by Darrion on 4/5/2021.
//

#include "Vector.h"

Vector Vector::removeRow(int row) {
    Vector v(dim - 1);
    for (int i = 0; i < dim; i++) {
        if (i == row) continue;
        if (i > row)
            v.setCoord(i, coords[i]);
        else
            v.setCoord(i + 1, coords[i]);
    }
    return v;
}

int Vector::getCoord(int coord) {
    return coords[coord - 1];
}

void Vector::setCoord(int coord, int value) {
    this->coords[coord - 1] = value;
}

void Vector::scale(int scalar) {
    for (int i = 1; i <= dim; i++) {
        int currentValue = getCoord(i);
        setCoord(i, currentValue * scalar);
    }
}

void Vector::print() {
    cout << "Printing Vector" << endl;
    for (int i = 0; i < dim; i++) {
        cout << coords[i] << endl;
    }
}