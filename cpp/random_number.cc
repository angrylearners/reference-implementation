//
// Created by 31838 on 8/9/2019.
//

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int RandomNumberInRange(int from, int to) {
  assert(from < to);
  return from + rand() % (to - from);
}

int main() {
  for (int i = 0; i < 10; i++)
    cout << rand() << endl;
  
  //限制这个随机数在0-99
  for (int i = 0; i < 10; i++)
    cout << rand() % 100 << endl;
  
  //生成一定范围内的随机数
  //注意from一定要小于to
  cout << RandomNumberInRange(-32, -123) << endl;
}

