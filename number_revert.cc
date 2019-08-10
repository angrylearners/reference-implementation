//
// Created by 31838 on 8/9/2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "big_int/big_int.h"

using std::cout, std::endl, std::cin, std::vector, std::string, std::pow;

auto Revert(const vector<char> &input) -> vector<char> {
  vector<char> res = input;
  for (size_t i = 0; i < input.size() / 2; i++)
    std::swap(res[i], res[input.size() - i - 1]);
  return res;
}

auto Calculate(const vector<char> &input) -> BigInt {
  BigInt big_int(0);
  
  for (size_t i = 0; i < input.size(); i++) {
    big_int += BigInt(input[i] - '0') * pow(BigInt(10), BigInt(input.size() - 1 - i));
  }
  
  return big_int * BigInt(2);
}

auto main() -> int {
  vector<char> input;
  string input_str;
  getline(cin, input_str);
  for (auto ch:input_str)
    input.push_back(ch);
  cout << Calculate(Revert(input)) << endl;
}