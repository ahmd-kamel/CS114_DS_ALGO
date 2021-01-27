#include <iostream>
#include <set>
using namespace std;
#include "arrays.h"

int main()
{
    Array x(3);

    x.insert(5);
    x.insert(2);
    x.insert(3);
    x.insert(10);
    x.insert(6);

    Array y(3);
    y.insert(2);
    y.insert(3);
    y.insert(2);
    y.insert(3);
    y.insert(2);

    Array z = x.intersectAt(y);

    z.print();


    x.removeArr();
    y.removeArr();
    z.removeArr();

    return 0;
}