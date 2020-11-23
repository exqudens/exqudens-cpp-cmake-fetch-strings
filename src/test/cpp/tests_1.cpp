#include <iostream>
#include <string>

#include "exqudens/strings.hpp"

int main() {
  exqudens::strings strings1;
  std::string string1 = "  ASD ";
  std::string string2 = strings1.trim(string1);

  std::cout << string2 << std::endl;

  return 0;
}
