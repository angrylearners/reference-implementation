//
// Created by 31838 on 8/9/2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "big_int/big_int.h"

using std::cout, std::endl, std::cin, std::vector, std::string, std::pow, std::stringstream;

auto Revert(const vector<char> &input) -> vector<char> {
  vector<char> res = input;
  for (auto iter = input.rbegin(); iter != input.rend(); iter++)
    res.push_back(*iter);
  return res;
}

auto Calculate(const vector<char> &input) -> BigInt {
  BigInt big_int(0);
  
  for (size_t i = 0; i < input.size(); i++) {
    big_int += BigInt(input[i] - '0') * Pow(BigInt(10), BigInt(input.size() - 1 - i));
  }
  
  return big_int * BigInt(2);
}

auto main() -> int {
  vector<char> input;
//  string input_str="3246235462367542357423564523654632564236423554623553255723565327423564326463255432574326453254623546532764563254237547236432742354235472342376452375472346236745236546234234236723654623";
  string input_str;
  getline(cin, input_str);
  
  for (auto ch:input_str)
    input.push_back(ch);
  cout << Calculate(Revert(input)) << endl;
}