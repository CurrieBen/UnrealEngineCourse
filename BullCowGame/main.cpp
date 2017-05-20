#include <iostream>
#include <string>

using namespace std;
// using "using" can be dangerous as you can get namespace clashes, the best thing to do to avoid this is just use the name of the namespace then :: and then the method - for example std::cout

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main()
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();

	return 0; //exit the application
}

void PrintIntro()
{
	// introduce the game to the user
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game!" << endl;
	cout << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;
}

void PlayGame()
{
	constexpr int MAX_TURNS = 5;
	for (int count = 1; count <= MAX_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "You guessed " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() 
{
	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << endl;
	return Guess;
}

bool AskToPlayAgain()
{

}