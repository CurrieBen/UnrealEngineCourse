#include "FBullCowGame.h"
#include <map>
#define TMap std::map

//FString is used in unreal engine as well as FText and int32 rather than int
using FString = std::string;
using int32 = int;

//these are the getter methods - we use const at the end so that they can't be changed
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bHasWon; }

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
	bHasWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) { //not an isogram
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

