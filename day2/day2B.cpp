#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
std::vector<std::string> split(std::string s, std::string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }
  res.push_back(s.substr(pos_start));
  return res;
}
int main() {
  std::fstream inputFile("input.txt");
  std::string data;
  if (!inputFile.is_open()) {
    std::cerr << "Error: Unable to open file 'input.txt'.\n";
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::stringstream ss(line);
    ss >> data;
  }

  inputFile.close();

  unsigned long long sum = 0;

  std::vector<std::string> ranges = split(data, ",");
  for (auto v : ranges) {
    std::vector<std::string> range = split(v, "-");
    for (unsigned long long i = std::stoll(range[0]); i <= std::stoll(range[1]);
         i++) {
      std::string s = std::to_string(i);
      int len = s.size();

      for (int j = 1; j <= len / 2; j++) {
        if (len % j == 0) {
          bool isPattern = true;
          for (int k = j; k < len; k += j) {
            if (s.substr(k, j) != s.substr(0, j)) {
              isPattern = false;
              break;
            }
          }
          if (isPattern) {
            sum += i;
            break;
          }
        }
      }
    }
  }
  std::cout << sum;
  return 0;
}