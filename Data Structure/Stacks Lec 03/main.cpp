#include <iostream>
#include <string>
using namespace std;

typedef int stackType;
//const int maxLength = 100;

#include "stack.h"

int main(){

    Stack stack;
    stack.push(100);
    stack.printStack();

    return 0;

}