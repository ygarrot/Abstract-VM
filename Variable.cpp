//
// Created by Yoan GARROT on 2019-03-17.
//

#include "Variable.h"

Variable::Variable()
{

}

Variable::~Variable()
{

}

Variable::Variable(Variable const & src)
{
    *this = src;
}


Variable     &Variable::operator=(Variable const & src)
{
    (void)src;
    return *this;
}

template <A, B>
T Variable::add(A a , B b)
{
    return (a + b)
}

int double_operand()
{
     int a, b;

    if (this.variable_collection.len < 2)
        throw Exception();
    a = this.variable_collection.back();
    this.variable_collection.pop_back();
    b = this.variable_collection.back();
    this.variable_collection.pop_back();
    this.variable_collection.push_back(add(a, b));
}