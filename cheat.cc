//
// Created by 31838 on 8/8/2019.
//

#include <iostream>
#include <chrono>
#include <random>

using std::cout, std::cin, std::endl;
using std::chrono::system_clock, std::uniform_int_distribution, std::default_random_engine;

auto main() -> int {
  auto now = system_clock::now();
  auto dist = uniform_int_distribution<int>();
  auto engine = default_random_engine(now.time_since_epoch().count());
  
  for (int i = 0; i < 10; i++) {
    int unexpected = dist(engine) % 100;
    cout << "Please enter a number other than " << unexpected << ": ";
    int entered = 0;
    cin >> entered;
    if (entered == unexpected) {
      cout << "Hey! you weren't supposed to enter " << unexpected << " !" << endl;
      return EXIT_FAILURE;
    }
  }
  cout << "Wow, you're more patient then I am, you win." << endl;
  return EXIT_SUCCESS;
}