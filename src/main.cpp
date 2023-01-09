#include <iostream>
#include "solutions.h"
using namespace std;

int main() {
    std::setlocale(LC_ALL, "Rus");

    /**
     * реализация умного указателя приблизительно похожего на умный указатель
     * инициализация через конструкторы или через статическую функцию make_shared_toy
     */
    //solution_1();

    /**
     * Сохраняет ориентированный граф в виде массива списков смежности
     */
    //solution_2_list();

    solution_2_matrix();

    return 0;
}
