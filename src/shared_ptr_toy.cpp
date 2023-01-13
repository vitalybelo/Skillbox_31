#include "shared_ptr_toy.h"

// конструкторы с перегрузкой
shared_ptr_toy::shared_ptr_toy() : object(nullptr), count(nullptr) {}
shared_ptr_toy::shared_ptr_toy(Toy* toy) : count(new size_t(1)), object(toy) {}
shared_ptr_toy::shared_ptr_toy(const std::string & name) : count(new size_t(1)), object(new Toy(name)) {}

// конструктор копирования
shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy & other) : count(other.count), object(other.object)
{
    (*count)++; // количество копий копируемого объекта увеличивается на + еще одну
}

void shared_ptr_toy::reduce_count(bool do_echo) {

    if (count == nullptr) return;
    if (*count == 1) {
        if (do_echo)
            std::cout << object->getName() << " :: object destroyed" << std::endl;
        delete object;  // это последняя копия - удаляем объект полностью
        delete count;   // вместе с объектом удаляем счетчик
    } else {
        if (do_echo)
            std::cout << object->getName() << " :: object copy destroyed" << std::endl;
        (*count)--;     // у нас несколько копий - уменьшаем количество копий в счетчике
    }
}

// оператор присваивания
shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy & other) {

    if (this != &other) {
        // уменьшаем количество копий объекта или удаляем объект подлежащий замене
        reduce_count(false);

        // присваиваем текущему объекту значение другого, и увеличиваем счетчик копий
        object = other.object;
        count = other.count;
        (*count)++;
    }
    return *this;
}

// деструктор
shared_ptr_toy::~shared_ptr_toy() {
    reduce_count(true);
}

Toy* shared_ptr_toy::operator->() {
    return object;
}
Toy& shared_ptr_toy::operator*() {
    return *object;
}

unsigned shared_ptr_toy::use_count() const {
    return (count != nullptr) ?  *count : 0;
}

void shared_ptr_toy::print_count(const std::string &text) const {
    std::cout << text << " :: " << object->getName() << " :: " << use_count() << std::endl;
}

shared_ptr_toy shared_ptr_toy::make_shared_toy(const std::string & name) {
    shared_ptr_toy ptr(name);
    return ptr;
}


