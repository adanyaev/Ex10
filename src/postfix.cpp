// Copyright 2021 Artem Danyaev

#include "postfix.h"
#include "MyStack.h"

int getPriority(char c) {
  if (c == '(') {
    return 0;
  } else if (c == ')') {
    return 1;
  } else if (c == '+' || c == '-') {
    return 2;
  } else if (c == '*' || c == '/') {
    return 3;
  }
}

std::string infix2postfix(std::string s) {
  int i = 0;
  std::string output;

  MyStack<char> ops(5);
  while (i < s.length()) {
    if (s[i] >= 48 && s[i] <= 57) {
      std::string num;
      num.push_back(s[i]);
      i++;
      while ((s[i] >= 48 && s[i] <= 57) || s[i] == '.') {
        num.push_back(s[i]);
        i++;
      }
      output += num + ' ';
      continue;
    } else if (s[i] == ' ' || s[i] == '\n') {
      i++;
      continue;
    } else {
      int pr = getPriority(s[i]);
      if (ops.isEmpty() || pr == 0 || pr > getPriority(ops.get())) {
        ops.push(s[i]);
      } else {
        while (!ops.isEmpty() && getPriority(ops.get()) >= pr) {
          output.push_back(ops.pop());
          output.push_back(' ');
        }
        if (s[i] == ')') {
          ops.pop();
        } else {
          ops.push(s[i]);
        }
      }
      i++;
      continue;
    }
  }
  while (!ops.isEmpty()) {
    output.push_back(ops.pop());
    output.push_back(' ');
  }
  output.pop_back();
  return output;
}
