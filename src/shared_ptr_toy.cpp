#include "shared_ptr_toy.h"
#include <iostream>

[[maybe_unused]] shared_ptr_toy::shared_ptr_toy(const std::string & name) {
    object = new Toy(name);
    count = 0;
}

shared_ptr_toy::shared_ptr_toy(Toy *toy) {
    object = toy;
    count = 0;
}

shared_ptr_toy::shared_ptr_toy()  {
    object = new Toy("noname");
    count = 0;
}

// конструктор копирования
shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy & toy) {
    object = toy.object;
    count++;
}

// оператор присваивания
shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy & toy) {
    if (this != &toy) {
        object = toy.object;
        count++;
    }
    return *this;
}

// деструктор
shared_ptr_toy::~shared_ptr_toy() {
    if (object != nullptr && count == 0) {
        std::cout << object->getName() << " :: object destroyed" << std::endl;
        delete object;              // проверка не нужна, delete nullptr безопасна
    } else {
        if (count > 0) count--;     // если еще есть копии - объект не удаляем
        std::cout << object->getName() << " :: object copy destroyed" << std::endl;
    }
}
//
Toy* shared_ptr_toy::operator->() {
    return object;
}

Toy& shared_ptr_toy::operator*() {
    return *object;
}

shared_ptr_toy shared_ptr_toy::make_shared_toy(const std::string & name) {
    object = new Toy(name);
    count = 0;
    return *this;
}

int shared_ptr_toy::use_count() const {
    return count;
}





