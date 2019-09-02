//
// Created by 31838 on 9/2/2019.
//

#include <stdio.h>
#include <stdlib.h>

//#define BUILD

const char *drinks[5] = {"Coke", "Water", "Sprite", "Tea", "Coffee"};

//#define USE_IF
//#define USE_GNU_EXTENSIONS

void __attribute__((noreturn)) ShowUserChoice(const char *drink) {
  printf("You choose %s. Here is your drink.\n", drink);
  exit(EXIT_SUCCESS);
}

void __attribute__((noreturn)) ShowInvalidChoice() {
  printf("Error. Your chooice is invalid, here is your money back.");
  exit(EXIT_FAILURE);
}

#ifndef BUILD
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#endif

int main() {
  printf("Welcome to Cola Machine. Here you can choose:\n");
  
  for (size_t i = 0; i < 5; i++)
    printf("%lu) %s\n", i + 1, drinks[i]);
  
  printf("You want: ");
  fflush(stdout);
  size_t choice = 0;

// Cause scanf() is deprecated in msvc...
#ifdef _MSC_VER
  scanf_s("%d", &choice);
#else
  scanf("%zd", &choice);
#endif

#ifdef USE_IF
  if (1 <= choice && choice <= 5)
    ShowUserChoice(drinks[choice - 1]);
#else
  switch (choice) {
#ifdef USE_GNU_EXTENSIONS
    case 1 ... 5: // GNUC extension. Can be used with MSVC.
      printf("You chose %s\n", drinks[choice - 1]);
      printf("Here is your drink.");
      return EXIT_SUCCESS;
#else
    case 1:
      ShowUserChoice("Coke");
    case 2:
      ShowUserChoice("Water");
    case 3:
      ShowUserChoice("Sprite");
    case 4:
      ShowUserChoice("Tea");
    case 5:
      ShowUserChoice("Coffee");
#endif
  }
#endif
  ShowInvalidChoice();
}

#ifndef BUILD
#pragma clang diagnostic pop
#endif
