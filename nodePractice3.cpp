// hangman.cpp
// Hangman game illustrates string library functions,
// character arrays, arrays of pointers, etc.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;


int processGuess(char* word, const char* targetWord, char guess);
const char* wordBank[] = {"computer", "president", "trojan", "program",
"coffee", "library", "football", "popcorn",
"science", "engineer"};
const int numWords = 10;

int main()
{
  //hangman();
  srand(time(0)); //randomazation function
  char guess; //the guess that the user makes
  bool wordGuessed = false;
  int numTurns = 10;
  // Pick a random word from the wordBank

  const char* targetWord = wordBank[rand() % numWords]; //step 1

  char word[80]; //the hidden word that the user is trying to solve
  int size = strlen(targetWord); //this is how we get the length of the random word
  char RealWord[size]; //we have to create a new variable with the size of our word
  strcpy(RealWord, targetWord); //using strcpy we can compare our two arrays to see if they are compatible
  for(int i =0;i < size; i++)
  {
    RealWord[i] = '*'; //using this loop we will fill our game with astericks to denote unguessed positions
  }

  int j = 10; //iteration
  while (j > 0)
  {
    cout << "Current Word " << RealWord  << " " << targetWord << endl;
    cout << j << " remain...Enter a letter to guess:" << endl;
    cin >> guess;
    if(processGuess(RealWord, targetWord, guess) == 0)
    {
      j--; //only decrease the value of j when a user incorrectly guesses a letter
    }
    if(strcmp(targetWord, RealWord) == 0)
    {
      j = -1; //this condition checks to see if the two arrays are compatible, if so, then youve won the game
    }         //Also, we then change j to -1 so that the while loop does not continue and the game effectively ends.
  }
  if(j == -1)
  {
    cout << "The word was: " << targetWord << ". You Win!" << endl; //winning condition
  }
  else
  {
    cout << "Too many turns...You Lose!" << endl; //losing condition
  }

}


int processGuess(char* word, const char* targetWord, char guess) //the function checks to see how many times a guess occurs in the array
{
  int size = strlen(targetWord);
  int occur = 0;
  for(int i =0;i<size;i++)
  {
    if(guess == targetWord[i]) //if the user correctly guesses a position, then add it the occurence count and then replace the asterick with the proper letter
    {
      word[i] = targetWord[i];
      occur++;
    }
  }
  return occur; //return an interger number
}
