#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

//syntax made to be unreal friendly
using FString = std::string;
using int32 = int;

//these are the getter methods - we use const at the end so that they can't be changed
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bHasWon; }

int32 FBullCowGame::GetMaxTries() const 
{
	//changes the number of turns the player has based on the length of the isogram
	//so for a 3 letter isogram, they have 4 turns etc.
	TMap <int32, int32> WordLengthToMaxTries{ {3,4}, {4,5}, {5,6}, {6,7} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	bHasWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) { //not an isogram
		return EGuessStatus::Not_an_isogram;
	}
	else if (!IsLowerCase(Guess)) { // not all lowercase
		return EGuessStatus::Not_lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) { // not the right amount of letters
		return EGuessStatus::Wrong_length;
	}
	else {
		return EGuessStatus::ok;
	}
}

// receives VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 Word_length = MyHiddenWord.length(); //should only reach this point if it's a valid guess

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < Word_length; MHWChar++) {
		//compare the letters against the guess
		for (int32 GChar = 0; GChar < Word_length; GChar++) {
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
	if (BullCowCount.Bulls == Word_length)
	{
		bHasWon = true;
	}
	else {
		bHasWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap <char, bool> LetterSeen; //set up our map
	for (auto Letter : Word) { //auto decides the data type and : means 'in' so letter in word
		Letter = tolower(Letter); //make everything lowercase
		if (LetterSeen[Letter]) {//if the letter is in the map
			return false; //we don't have an isogram
		}
		else {
			LetterSeen[Letter] = true; //add the letter to the map
		}
		// if we havent seen it before add it to our new list and move on to the next letter
		// if we have seen it before return false and exit this function
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
		else {
			return true;
		}
	}
}

