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

  for (auto v : data) {
    if (v[0] == 'L') {
      buffer = buffer - std::stoi(v.substr(1));
    }
    if (v[0] == 'R') {
      buffer += std::stoi(v.substr(1));
    }
    while (buffer < 0) {
      buffer += 100;
    }
    while (buffer > 99) {
      buffer -= 100;
    }
    if (buffer == 0) {
      password++;
    }
  }
  std::cout << password;
}
