//
// Created by 31838 on 8/9/2019.
//

#include <iostream>
#include <random>
#include <chrono>
#include <cassert>

using std::cout, std::endl, std::cin, std::getline, std::getchar, std::string;

struct Range {
  int from, to;
  
  bool Validate() {
    return to >= from;
  }
};

auto ClearScreen() -> void {
  cout << "\033[2J\033[1;1H";
}

auto Random() -> int {
  using std::chrono::system_clock, std::uniform_int_distribution, std::default_random_engine;
  auto now = system_clock::now();
  auto dist = uniform_int_distribution<int>();
  auto engine = default_random_engine(now.time_since_epoch().count());
  return dist(engine);
}

auto Random(Range rng) -> int {
  assert(rng.Validate());
  if (rng.to == rng.from)
    return rng.to;
  return Random() % (rng.to - rng.from) + rng.from;
}

auto Random(int to) -> int {
  assert(to >= 0);
  return Random(Range{0, to});
}

enum class GameOverFlag {
  kSuccess,
  kFail,
  kNotOver
};

class Game {
private:
  int secretNumber_{}, entered_{};
  size_t guessTimes_{};
public:
  Game() : secretNumber_(Random(101)) { cout << "The random number will be generated in range [0,100]" << endl; }
  
  ~Game() { ClearScreen(); }
  
  auto GetSecretNumber() -> int { return secretNumber_; }

private:
  auto IsGameOver() -> GameOverFlag {
    if (entered_ != secretNumber_) {
      cout << "That's wrong! ";
      if (entered_ > secretNumber_)
        cout << "Too big!";
      else
        cout << "Too small!";
      cout << endl;
      return GameOverFlag::kNotOver;
    }
    cout << "Yes! " << secretNumber_ << " is exactly the secret number" << endl;
    return GameOverFlag::kSuccess;
  }
  
  auto reset() -> void {
    secretNumber_ = Random(101);
  }

public:
  auto Play() -> void {
    do {
      cout << "You think the secret number is: ";
      cin >> entered_;
    } while (IsGameOver() == GameOverFlag::kNotOver);
  }
};

auto main() -> int {
  cout << R"(
Welcome to dungeon number guessing game.
Ready to go? Press ENTER to move on!
)" << std::flush;
  getchar();
  play:
  ClearScreen();
  auto game = Game();
  game.Play();
  ask:
  {
    cout << "Would you like to play again? [y/n] ";
    string str;
    cin >> str;
    if (str == "y")
      goto play;
    else if (str == "n") {
      ClearScreen();
      cout << "Bye Bye." << endl;
      return EXIT_SUCCESS;
    } else {
      cout << "Please enter y or n." << endl;
      goto ask;
    }
  }
}

