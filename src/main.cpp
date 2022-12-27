#include <iostream>
#include "solutions.h"
using namespace std;

int main() {
    std::setlocale(LC_ALL, "Rus");

    /**
     * реализация умного указателя приблизительно похожего
     * инициализация через конструкторы или через статическую функцию make_shared_toy
     */
    std::cout << "\n************* SOLUTION №1 ************\n";
    solution_1();

    return 0;
}
