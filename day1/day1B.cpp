#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::fstream inputFile("input.txt");
  std::vector<std::string> data;

  if (!inputFile.is_open()) {
    std::cerr << "Error: Unable to open file 'input.txt'.\n";
    return 1;
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    std::stringstream ss(line);
    std::string value;

    while (ss >> value) {
      data.push_back(value);
    }
  }

  inputFile.close();

  int buffer = 50;
  int password = 0;
  int counter = 0;

  for (auto v : data) {

    int step = (v[0] == 'R') ? 1 : -1;

    for (int i = 0; i < std::stoi(v.substr(1)); i++) {
      buffer += step;
      if (buffer == -1) {
        buffer = 99;
      }
      if (buffer == 100) {
        buffer = 0;
      }

      if (buffer == 0) {
        password++;
      }
    }
  }
  std::cout << password;
}
