#pragma once
#include "Toy.h"
#include <iostream>


class shared_ptr_toy {
private:
    Toy* object;
    int count = 0;

public:
    shared_ptr_toy();
    explicit shared_ptr_toy(const std::string & name);
    explicit shared_ptr_toy(Toy* toy = nullptr);
    shared_ptr_toy(const shared_ptr_toy & new_one);

    shared_ptr_toy& operator=(const shared_ptr_toy& toy);
    Toy* operator->();
    Toy& operator*();

    virtual ~shared_ptr_toy();

    [[nodiscard]] int use_count() const;
    shared_ptr_toy make_shared_toy(const std::string & name);

};
