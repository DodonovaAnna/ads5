// Copyright 2025 NNTU-CS
#include <iostream>
#include <string>
#include <sstream>
#include "tstack.h"

int priority(char oper) {
    switch (oper) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return 0;
    }
}

std::string infx2pstfx(const std::string& inf) {
  std::string outS;
  TStack<char, 100> stack;
  for (size_t j = 0; j < inf.length(); j++) {
    char symb = inf[j];
    if (symb == ' ') {
        continue;
    }


int eval(const std::string& pref) {
  // добавьте код
  return 0;
}
