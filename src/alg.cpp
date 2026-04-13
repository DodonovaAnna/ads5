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

 if (std::isdigit(symb)) {
        while (j < inf.length() && std::isdigit(inf[j])) {
            outS.push_back(inf[j]);
            j++;
        }
        j--;
        outS.push_back(' ');
    } else if (symb == '(') {
        stack.push(symb);
    } else if (symb == ')') {
        while (!stack.isEmpty() && stack.top() != '(') {
            outS.push_back(stack.top());
            outS.push_back(' ');
            stack.pop();
        }
        if (!stack.isEmpty() && stack.top() == '(') {
            stack.pop();
        } else {
            throw std::runtime_error("Err");
        }
    } else if (symb == '+' || symb == '-' || symb == '*' || symb == '/') {
        while (!stack.isEmpty() && priority(stack.top()) >=
            priority(symb)) {
            outS.push_back(stack.top());
            outS.push_back(' ');
            stack.pop();
        }
        stack.push(symb);
    } else {
        throw std::runtime_error(std::string("Err") + symb);
    }
  }
  while (!stack.isEmpty()) {
    if (stack.top() == '(' || stack.top() == ')') {
        throw std::runtime_error("Err");
    }
    outS.push_back(stack.top());
    outS.push_back(' ');
    stack.pop();
  }
  if (!outS.empty() && outS.back() == ' ') {
    outS.pop_back();
  }
  return outS;
}


int eval(const std::string& pref) {
  // добавьте код
  return 0;
}
