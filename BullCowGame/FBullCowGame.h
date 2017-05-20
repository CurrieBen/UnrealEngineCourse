#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //this is a constructor function - take the name of a class and define it as a function
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(std::string); //TODO make a more rich return value

private:
	// these values can be overwritten with the constructor function as these are complie time values
	// and the constructor is a runtime value. So there is no point setting them at both. Instead we 
	// will just set them at the constructor function so check there for values
	int MyCurrentTry;
	int MyMaxTries;
};