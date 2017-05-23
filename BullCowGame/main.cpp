/* This is a console executable, that makes use of the BullCow class. This acts as the view in an MVC pattern 
and is responsible for all user interaction. For game logic see FBullCowGame class
*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

//function prototypes as outside class
void Printintro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game from the class FBullCowGame
void PrintGameSummary();

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
	std::cout << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << R"(

                          /|                        /|
                          | \           __ _ _     / ;
                    ___    \ \   _.-"-" `~"\  `"--' /
                _.-'   ""-._\ ""   ._,"  ; "\"--._./
            _.-'       \./    "-""", )  ~"  |
           / ,- .'          ,     '  `o.  ;  )
           \ ;/       '                 ;   /
            |/        '      |      \   '   |
            /        |             J."\  ,  |
           "         :       \   .'  : | ,. _)
           |         |     /     f |  |`--"--'
            \_        \    \    / _/  |
             \ "-._  _.|   (   j/; -'/
              \  | "/  (   |   /,    |
               | \  |  /\  |\_///   /
               \ /   \ | \  \  /   /
                ||    \ \|  |  |  |
                ||     \ \  |  | /
                |\      |_|/   ||
                L \       ||   ||
                `"'       |\   |\
	                    ( \. \ `.
                          |_ _\|_ _\
                            "    "        
)" << '\n';
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

	// loop asking for guess while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::invalid_status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << "." << std::endl;
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
	
		switch (Status) // switch statement to give player info based on errors made
		{
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_an_isogram:
			std::cout << "Please enter a valid isogram - this is a word with no repeating letters.\n\n";
			break;
		case EGuessStatus::Not_lowercase:
			std::cout << "Please enter a word in lowercase only.\n\n";
			break;
		default:
			//assume the input is valid
			break;
		}
	} while (Status != EGuessStatus::ok); //keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');	
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "Well Done! You guessed the Isogram!\n\n";
	}
	else
	{
		std::cout << "Unlucky! Better Luck next time!\n\n";
	}
}
