/* This is a console executable, that makes use of the BullCow class. This acts as the view in an MVC pattern 
and is responsible for all user interaction. For game logic see FBullCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//FText is used in the unreal engine so we are using that here
using FText = std::string;
using int32 = int;

void Printintro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game from the class FBullCowGame

int main()
{
	do {
		Printintro();
		PlayGame();
	} 
	while (AskToPlayAgain());

	return 0; //exit the application
}

void Printintro()
{
	// introduce the game to the user
	constexpr int32 WORD_LENGTH = 5;
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
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();

		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess() 
{
	//get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << std::endl;
	std::cout <<"Enter your guess: " << std::endl;
	FText Guess = "";
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');	
}
