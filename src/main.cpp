// Copyright 2021 Artem Danyaev
#include <iostream>
#include "postfix.h"
int main() {
  std::string s1("2 + 6 * 3 / (4 - 2)");
  std::string s2 = infix2postfix(s1);
  std::cout << s2;
  std::cout << std::endl;
  std::cout << infix2postfix("(45 + 534) * (43 / (12 - 2324)) * 32");
  std::cout << std::endl;
  std::cout << infix2postfix("43.53 + (24 - 2423.42) / 234.34 - 23.2");
  std::cout << std::endl;
  std::cout << infix2postfix("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
}
