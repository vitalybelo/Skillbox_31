#include <iostream>
#include <memory>
#include "Toy.h"
#include "shared_ptr_toy.h"
using namespace std;

int main() {

    Toy* pt1 = new Toy("ball");

    shared_ptr_toy p1(pt1);
    shared_ptr_toy p2("bone");
    shared_ptr_toy p3(p1);
    shared_ptr_toy p4 = p2;

    p1->print("p1: ");
    p2->print("p2: ");
    p3->print("p3: ");
    p4->print("p4: ");
    cout << endl;

    p4 = p1;

    return 0;
}
