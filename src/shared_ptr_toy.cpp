#include "shared_ptr_toy.h"
#include <iostream>

// конструкторы с перегрузкой
shared_ptr_toy::shared_ptr_toy() : object(nullptr), count(nullptr) {}
shared_ptr_toy::shared_ptr_toy(Toy* toy) : count(new size_t(1)), object(toy) {}
shared_ptr_toy::shared_ptr_toy(const std::string & name) : count(new size_t(1)), object(new Toy(name)) {}

// конструктор копирования
shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy & other) : count(other.count), object(other.object) {
    object = other.object;
    count = other.count;
    (*count)++; // количество копий копируемого объекта + еще одна
}

// оператор присваивания
shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy & other) {
    if (this != &other) {
        // модифицируем текущий объект перед присваиванием
        if (count) {
            if (*count == 1) {
                delete object;  // удаляем объект
                delete count;
            } else (*count)--;  // станет на одну копию меньше
        }
        // присваивание с учетом уже имеющегося количества копий
        object = other.object;
        count = other.count;
        (*count)++;
    }
    return *this;
}

// деструктор
shared_ptr_toy::~shared_ptr_toy() {
    if (count == nullptr) return;
    if (*count == 1) {
        std::cout << object->getName() << " :: object destroyed" << std::endl;
        delete object;
        delete count;
    } else {
        std::cout << object->getName() << " :: object copy destroyed" << std::endl;
        (*count)--;
    }
}

Toy* shared_ptr_toy::operator->() {
    return object;
}
Toy& shared_ptr_toy::operator*() {
    return *object;
}

unsigned shared_ptr_toy::use_count() const {
    return (count) ?  *count : 0;
}

void shared_ptr_toy::print_count(const std::string &text) const {
    std::cout << text << " :: " << object->getName() << " :: " << use_count() << std::endl;
}

shared_ptr_toy shared_ptr_toy::make_shared_toy(const std::string & name) {
    shared_ptr_toy ptr(name);
    return ptr;
}

