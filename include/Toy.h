#pragma once
#include <iostream>

class Toy {

private:
    std::string name;
public:
    explicit Toy(std::string _name);
    Toy();

    [[nodiscard]] const std::string &getName() const;
    void print(const std::string& text);

};
