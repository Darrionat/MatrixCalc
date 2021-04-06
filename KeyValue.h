//
// Created by Darrion on 4/6/2021.
//

#ifndef MATRIXCALC_KEYVALUE_H
#define MATRIXCALC_KEYVALUE_H

#include "Matrix.h"

template<class K, class V>
class KeyValue {
private:
    K key;
    V value;
public:
    KeyValue(K key, V value) : key(key), value(value) {}

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
};

#endif //MATRIXCALC_KEYVALUE_H
