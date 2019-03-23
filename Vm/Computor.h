//
// Created by Yoan GARROT on 2019-03-17.
//

#ifndef ABSTRACT_VM_COMPUTOR_H
#define ABSTRACT_VM_COMPUTOR_H


class Computor {
public:

   int  push();
   int  pop();
   int  dump();
   int  assert();
   int  addr();
   int  sub();
   int  mul();
   int  div();
   int  mod();
   int  print();
   int  exit();
private:
    int test;
};


#endif //ABSTRACT_VM_COMPUTOR_H
