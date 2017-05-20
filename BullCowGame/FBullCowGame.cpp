#include "FBullCowGame.h"

//these are the getter methods - we use const at the end so that they can't be changed
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

//this also has const at the end as it should only be returning one of two options and shouldn't be changing anything else in the game
bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

