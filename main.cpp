#include <iostream>
#include <random>
#include <string>

int main() {
	std::random_device rd{};
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ ss };
	std::uniform_int_distribution random{ 1, 100 };
	int guess;
	int num;
	int currentGuess;
	std::string again;

	while (true) {
		guess = 1;
		num = random(mt);
		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
		while (guess <= 7) {
			std::cout << "Guess #" << guess << ": ";
			std::cin >> currentGuess;
			++guess;
			if (currentGuess == num) {
				std::cout << "Correct! You win!\n";
				break;
			}
			if (currentGuess > num) {
				std::cout << "Your guess is too high.\n";
				continue;
			}
			std::cout << "Your guess is too low.\n";
		}
		while (true) {
			std::cout << "Would you like to play again (y/n)? ";
			std::cin >> again;
			if (again == "n" || again == "N") {
				goto end;
			}
			if (again == "y" || again == "Y") {
				break;
			}
		}
	}
end:
	return 0;
};
