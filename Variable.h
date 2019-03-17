//
// Created by Yoan GARROT on 2019-03-17.
//

#ifndef ABSTRACT_VM_VALUE_H
#define ABSTRACT_VM_VALUE_H

#include <cstdint>

class Value {
private:
    std::variant<int8_t, int16_t, int32_t, float, double> myVariant;
};


#endif //ABSTRACT_VM_VALUE_H
