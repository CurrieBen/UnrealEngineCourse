#include "FBullCowGame.h"

//FString is used in unreal engine as well as FText and int32 rather than int
using FString = std::string;
using int32 = int;

//these are the getter methods - we use const at the end so that they can't be changed
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) { //not an isogram
		return EGuessStatus::Not_an_isogram;
	}
	else if (false) { // not all lowercase
		return EGuessStatus::Not_lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) { // not the right amount of letters
		return EGuessStatus::Wrong_length;
	}
	else {
		return EGuessStatus::ok;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		//compare the letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { //if they are in the same place add bulls
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

