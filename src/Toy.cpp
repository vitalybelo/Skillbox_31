#include "Toy.h"

#include <utility>

Toy::Toy(std::string _name) : name(std::move(_name)) {}
Toy::Toy() : Toy("Noname") {}
Toy::~Toy() {
    std::cout << "\tseparate Toy object destroyed :: " << name << std::endl;
}

const std::string &Toy::getName() const { return name; }

void Toy::print(const std::string& text) {
    std::cout << text << name << std::endl;
}


