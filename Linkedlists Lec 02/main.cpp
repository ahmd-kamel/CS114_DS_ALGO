#include <iostream>

using namespace std;

#include "linkedlist.h"

int main(){
    LinkedList list;
    list.addLast(100);
    list.addLast(20);
    list.addLast(30);
    list.print();
    
    list.freeList();

    return 0;
}