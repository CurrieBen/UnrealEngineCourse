#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//this data type allows more than one integer to be stored inside it
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	invalid_status,
	ok,
	Not_an_isogram,
	Wrong_length,
	Not_lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); //this is a constructor function - take the name of a class and define it as a function
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString) const; //TODO make a more rich return value

	void Reset(); //TODO make a more rich return value
	// checks bulls & cows and increases number, assuming it's a valid guess
	FBullCowCount SubmitGuess(FString Guess);

private:
	// these values can be overwritten with the constructor function as these are complie time values
	// and the constructor is a runtime value. So there is no point setting them at both. Instead we 
	// will just set them at the constructor function so check there for values
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};