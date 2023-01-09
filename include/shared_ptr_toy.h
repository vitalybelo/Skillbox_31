#pragma once
#include "Toy.h"
#include <iostream>

class shared_ptr_toy {
private:
    Toy* object;
    size_t* count;

public:
    shared_ptr_toy();
    explicit shared_ptr_toy(const std::string & name);
    explicit shared_ptr_toy(Toy* toy = nullptr);
    shared_ptr_toy(const shared_ptr_toy & other);

    shared_ptr_toy& operator=(const shared_ptr_toy& other);
    Toy* operator->();
    Toy& operator*();

    virtual ~shared_ptr_toy();

    [[nodiscard]] unsigned int use_count() const;
    void print_count(const std::string &text) const;
    static shared_ptr_toy make_shared_toy(const std::string & name);

};
