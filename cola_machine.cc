#include <iostream>
#include <array>
#include <string>

using std::array, std::cout, std::endl, std::cin, std::string, std::getline, std::stoi;

const size_t num_drinks = 5;

array<string, num_drinks> all_drinks;

template<size_t arr_len = num_drinks>
auto ShowDrinks(array<string, arr_len> drinks) -> void {
  cout << "There are " << arr_len << " drinks, which one do you like?" << endl;
  for (size_t i = 0; i < arr_len; i++)
    cout << " " << i + 1 << ") " << drinks[i] << endl;
}

auto Init() -> void {
  all_drinks = {"Cola", "Water", "Sprite", "Juice", "Tea"};
}

auto main() -> int {
  Init();
  ShowDrinks(all_drinks);
  string choice_str;
  int choice = 0;
  getline(cin, choice_str);
  if (choice_str.size() != 1)goto invalid_choice;
  choice = stoi(choice_str);
  if (choice >= 1 && choice <= num_drinks) {
    cout << "OK, your choice is " << all_drinks[choice - 1] << "." << endl;
    exit(EXIT_SUCCESS);
  }
  invalid_choice:
  cout << "Error, your choice was invalid. Here is your money back." << endl;
  exit(EXIT_FAILURE);
}