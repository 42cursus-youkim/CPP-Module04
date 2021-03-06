#include "Brain.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "util.hpp"

using std::cout;

// clang-format off
const string pool[] = {
  "ð", "ð", "ð", "ð", "ð", "ð", "ð", "ð",
  "ð", "ðĨĄ", "ð", "ð", "ð", "ðĨ­", "ð", "ðĨĨ",
  "ðĨ", "ð", "ð", "ðĨ", "ðĨĶ", "ðĨŽ", "ðĨ", "ðķ",
  "ð―", "ð―", "ðĨ", "ðĨĢ", "ð§", "ð§", "ðĨ", "ðĨ",
  "ðĨŊ", "ð", "ðĨ", "ðĨĻ", "ð§", "ðĨ", "ðģ", "ð§",
  "ðĨ", "ð§", "ðĨ", "ðĨĐ", "ð", "ð", "ðĶī", "ð­",
  "ð", "ð", "ð", "ðī", "ðĨŠ", "ðĨ", "ð§", "ðŪ",
  "ðŊ", "ð§", "ðĨ", "ðĨ", "ðĨŦ", "ð", "ð", "ðđ",
  "ðē", "ð", "ðĢ", "ðą", "ðĨ", "ðĶŠ", "ðĪ", "ð",
  "ð", "ð", "ðĨ", "ðĨ ", "ðĨŪ", "ðĒ", "ðĄ", "ð§",
  "ðĶ", "ðĨ§", "ð§", "ð°", "ð", "ðŪ", "ð­", "ðŽ",
  "ðŦ", "ðŋ", "ðĐ", "ðŠ", "ð°", "ðĨ", "ðŊ", "ðĨ",
  "ðž", "ðū", "ðĨ", "ðĩ", "ð§", "ðĨĪ", "ð§", "ð§",
  "ðķ", "ðš", "ðŧ", "ðĨ", "ð·", "ðļ",
};
// clang-format on

// Constructors
Brain::Brain() {
  LOG_CLASS;
  for (int i = 0; i < BRAIN_SIZE; i++)
    _ideas[i] = pool[rand() % static_cast<int>(sizeof(pool) / sizeof(string))];
  cout << *this << "\n";
}

Brain::Brain(const Brain& other) {
  LOG_CLASS_COPY;
  operator=(other);
  cout << *this << "\n";
}

// Destructor
Brain::~Brain() {
  LOG_CLASS;
}

// Operators
Brain& Brain::operator=(const Brain& assign) {
  if (this != &assign)
    for (int i = 0; i < BRAIN_SIZE; i++)
      _ideas[i] = assign.getIdea(i);

  return *this;
}

// Getters
const string& Brain::getIdea(int index) const {
  if (index < 0 || index >= BRAIN_SIZE)
    throw std::out_of_range("index out of range");
  return _ideas[index];
}

std::ostream& operator<<(std::ostream& os, const Brain& b) {
  for (int i = 0; i < Brain::BRAIN_SIZE / 5; i++)
    os << b.getIdea(i);
  return os;
}
