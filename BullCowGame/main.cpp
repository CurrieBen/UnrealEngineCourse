#include <iostream>
#include <string>
#include "FBullCowGame.h"

// was using this: using namespace std; but it is too easy to be dangerous so removing from all file - also never user this in a header file!
// using "using" can be dangerous as you can get namespace clashes, the best thing to do to avoid this is just use the name of the namespace then :: and then the method - for example std::std::cout

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game from the class FBullCowGame

int main()
{
	do {
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());

	return 0; //exit the application
}

void PrintIntro()
{
	// introduce the game to the user
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "You guessed " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() 
{
	//get a guess from the player
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << std::endl;
	std::cout <<"Enter your guess: " << std::endl;
	std::string Guess = "";
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');	
}
