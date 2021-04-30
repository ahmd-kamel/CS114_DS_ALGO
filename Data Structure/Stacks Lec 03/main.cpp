#include <iostream>
#include <string>
using namespace std;

typedef int stackType;
const int maxLength = 100;

#include "stack.h"

int main(){

    Stack stack;
    stack.push(100);
    stack.push(90);
    stack.push(80);

    stack.printStack();
    for (int i = 0; i < 3; i++)
        cout << stack.pop() << endl;



    stack.destroyStack();
    return 0;
}