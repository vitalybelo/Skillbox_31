#include <iostream>
#include <memory>
#include "Toy.h"
#include "shared_ptr_toy.h"
using namespace std;

void solution_1() {

    Toy* pt1 = new Toy("ball");

    auto p0 = shared_ptr_toy::make_shared_toy("bulk");
    shared_ptr_toy p1(pt1);
    shared_ptr_toy p2("bone");
    shared_ptr_toy p3(p1);
    shared_ptr_toy p4(p1);

    cout << endl;
    p0->print("p0: ");
    p1->print("p1: ");
    p2->print("p2: ");
    p3->print("p3: ");
    p4->print("p4: ");
    cout << endl;

    p4 = p1; // = ball
    p4 = p2; // = bone
    p4 = p3; // = ball
    p4 = p4; // = ball = ball

    p0.print_count("p0: count =");
    p1.print_count("p1: count =");
    p2.print_count("p2: count =");
    p3.print_count("p3: count =");
    p4.print_count("p4: count =");
    cout << endl;

}
