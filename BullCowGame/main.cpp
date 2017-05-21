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
FText GetValidGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
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
		FText Guess = GetValidGuess();

		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows << "\n\n";
	}
}

FText GetValidGuess() //TODO change to make GetValidGuess
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::invalid_status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << std::endl;
		std::cout <<"Enter your guess: " << std::endl;
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
	
		switch (Status) // switch statement to give player info based on errors made
		{
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_an_isogram:
			std::cout << "Please enter a valid isogram - this is a word with no repeating letters.\n";
			break;
		case EGuessStatus::Not_lowercase:
			std::cout << "Please enter a word in lowercase only.\n";
			break;
		default:
			//assume the input is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::ok); //keep looping until we get no errors
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
