//
// Created by 31838 on 8/8/2019.
//

#include <iostream>
#include <array>


using std::cin, std::cout, std::endl, std::array, std::swap;

struct person {
  uint num;
  uint id;
  
  bool operator<(const person &p) {
    return num < p.num;
  }
  
  bool operator>(const person &p) {
    return num > p.num;
  }
};

const uint num_person = 5;

auto main() -> int {
  if (num_person < 2) {
    cout << "number of people should bigger or equal to 2" << endl;
    return EXIT_FAILURE;
  }
  
  array<person, num_person> people = {};
  
  for (int i = 0; i < num_person; i++) {
    cout << "Person" << i + 1 << " eat: ";
    cin >> people[i].num;
    people[i].id = i;
  }
  
  person max = people[0], min = people[0];
  
  for (int i = 0; i < num_person; i++) {
    max = people[i] > max ? people[i] : max;
    min = people[i] < min ? people[i] : min;
  }
  
  cout << endl;
  cout << "Person" << max.id + 1 << " ate the most pancakes, the number is " << max.num << endl;
  cout << "Person" << min.id + 1 << " ate the least pancakes, the number is " << min.num << endl;
  cout << endl;
  
  for (int i = 0; i < num_person; i++)
    for (int j = 0; j < num_person - 1; j++)
      if (people[j] < people[j + 1])
        swap(people[j], people[j + 1]);
  
  for (int i = 0; i < num_person; i++)
    cout << "Person" << people[i].id + 1 << " ate " << people[i].num << " pancake(s)" << endl;
  
  return EXIT_SUCCESS;
}

