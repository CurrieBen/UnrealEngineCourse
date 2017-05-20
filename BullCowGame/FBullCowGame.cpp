#include "FBullCowGame.h"

//FString is used in unreal engine as well as FText and int32 rather than int
using FString = std::string;
using int32 = int;

//these are the getter methods - we use const at the end so that they can't be changed
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

//this also has const at the end as it should only be returning one of two options and shouldn't be changing
//anything else in the game
bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		//compare the letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			//if they match then
			if (Guess[i] == MyHiddenWord[i]) {
				if (i == j) { //if they are in the same place add bulls
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}

