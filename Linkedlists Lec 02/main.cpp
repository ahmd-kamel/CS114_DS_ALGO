#include <iostream>

using namespace std;

#include "linkedlist.h"

int main(){
    LinkedList list;
    list.addLast(100);
    list.addLast(20);
    list.addLast(30);

    int *arr = list.convertToArray();
    int len = list.sizeList();

    for (int i = 0; i < len; i++)
        cout << arr[i] << endl;

    list.freeList();

    return 0;
}