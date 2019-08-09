//
// Created by 31838 on 8/9/2019.
//

#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::cin, std::vector, std::string, std::pow;

auto Revert(const vector<char> &input) -> vector<char> {
  vector<char> res = input;
  for (size_t i = 0; i < input.size() / 2; i++)
    std::swap(res[i], res[input.size() - i - 1]);
  return res;
}

auto Calculate(const vector<char> &input) -> uint64_t {
  uint64_t res = 0;
  
  for (size_t i = 0; i < input.size(); i++)
    res += pow(10, input.size() - 1 - i) * (input[i] - '0');
  
  return res * 2;
}


auto main() -> int {
  vector<char> input;
  string input_str;
  getline(cin, input_str);
  for (auto ch:input_str)
    input.push_back(ch);
  cout << Calculate(Revert(input)) << endl;
}