#include "Animal.hpp"
#include <iostream>

using std::cout;

// Constructors
Animal::Animal() : _type("random animal") {
  announce("is born");
}

Animal::Animal(string type) : _type(type) {
  announce("is born");
}

Animal::Animal(const Animal& copy) {
  *this = copy;
  announce("is copied");
}

// Destructor
Animal::~Animal() {
  announce("dies");
}

// Operators
Animal& Animal::operator=(const Animal& assign) {
  announce("is assigned");
  _type = assign.getType();
  return *this;
}

// Getters / Setters
const string& Animal::getType() const {
  return _type;
}

void Animal::announce(const string& msg) const {
  cout << _type << " " << msg << std::endl;
}
