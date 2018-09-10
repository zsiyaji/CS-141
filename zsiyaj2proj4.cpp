#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <array>

using namespace std;
/* ------------------------------------------------
zsiyaj2Proj4.cpp

Program #4: Twisted Hangman
Program delays choosing which word is chosen,
making the game as difficult as possible.

Class: CS 141
Author: Zakariah Siyaji
Lab: Tues 2pm
System:  C++ Mac Xcode

Grading Rubric:

50 Execution points
2 Displays header info and instructions on screen when run
5 Correctly counts and displays the number of initial dictionary words, for any dictionary
10 Correctly extracts words of the selected length and displays count for those words, < 5 seconds
3 Move number is displayed and updates correctly.  Move number starts at 15.
2 Handles upper and lower-case user input for the letters that are guessed
3 Displays letters guessed so far, in alphabetical order
10 Updates number of words left after each guess
5 Input of '~' displays all possible words remaining
10 Correctly displays letters once all words remaining have that letter, eliminating non-match words
5 Displays appropriate message when word is guessed, or when it is not guessed and guesses run out

45 Programming Style (Given only if program runs substantially correctly)
5 Program naming convention is followed
10 Meaningful identifier names
10 Comments: Has header and this rubric.  Has comments on each block of code
10 Appropriate data and control structures
10 Code Layout: Appropriate indentation and blank lines
------------------------------------------------
*/

class Word
{
private:
  string wordInput;
  int length;
public:
  Word(string word)
  {
    wordInput = word;
  }
  string getWord() //This will return the word
  //of the desired location
  {
    return wordInput;
  }

  bool contains(char letterInput)
  { //checks to see if the char parameter is in the string
    for(int i = 0; i < wordInput.size(); i++){
      for(int j = 0; j < 26; j++)
      {
        if(wordInput[i] == letterInput)
        return true;
      }
    }
    return false;
  }

  int getLength()
  {
    return getWord().length();
  }
};

int charPos(int i, string word, char letter)
{ //checks to see the position of a character in a string
  for(; i < word.length(); i++)
  {
    if(word[i] == letter)
    {
      break;
    }
  }
  return i;
}

bool getDone(vector<char> guessed)
{//proves that all the position in the vector are filled with valid characters
//that are not spaces.
  int count = 0;
  for(int i = 0; i < guessed.size(); i++)
  {
    if(guessed[i] != '_')
    {
      count++;
    }
  }
  if(count == guessed.size())
  {
    return true;
  }
  return false;
}

void Hangman_Game()
{//The entire game is in this function
  ifstream file;
  file.open("dictionary.txt"); //opens the file
  vector<Word> dictionary; //dictionary of all the initial words
  vector<string> newList; //after taking in the desired length, the dictionary
  //is narrowed down and added to the newList.
  vector<char> guessed; //This is a vector filled with guessed characters
  vector<char> guessedLetter;
  bool hasWon = false;
  string answer, myWord; //stores the random string in the answer string
  int iRand, length, index;
  int count = 0;
  bool found;
  int j = 15; //counts down from 15 as the number of chances
  char letterInput; //character input
  while(file >> myWord)
  {
    for (int i = 0, len = myWord.size(); i < len; i++){
      //using inbuilt function to check each character of the word,
      //if it is punctuation character then remove it and update the word length
      if (ispunct(myWord[i])){
        myWord.erase(i--, 1);
        len = myWord.size();
      }
    }
    //if words is not empty, then push into wordList vector
    if ( myWord.size() != 0 ){
      //convert all the letter of the word into upper case
      transform(myWord.begin(), myWord.end(), myWord.begin(), ::toupper);

      dictionary.push_back(Word(myWord));
    }
  }
  /* If I want something to be random
  iRand = rand() % dictionary.size();
  srand(static_cast<int>(time(0)));
  */
  //answer = dictionary[iRand].getWord();

  cout << "Starting with "<< dictionary.size() << " words." << endl;
  cout << "What length word do you want? "; //initiation of the User Interface
  cin >> length; //taking in input
  string word;
  for(int i = 0; i < dictionary.size(); i++)
  {
    if(dictionary.at(i).getLength() == length)
    {
      newList.push_back(dictionary.at(i).getWord()); //gets all the words of the desired length and puts it into a new vector
      count++;
    }
  }
  //rand
  //Im going to create a second vector
  //thatll hold all the words with the length provided
  //then ill chose a word at random. User will guess the words

  srand(static_cast<int>(time(0))); //method to writing randomazation function
  iRand = rand() % newList.size(); //choses a word at random from 0 to the size of the array list

  answer = newList[iRand]; //choses a random word and stores it in the string: answer
  cout << iRand << " and " << answer << endl; //more UI
  cout << "Now we have " << count << " words of length " << length << endl << endl; //UI
  for(int a = 0; a < length; a++)
  {
    guessed.push_back('_'); //this line will position spaces into the array as part of aesthetics for the UI
  }

  while(hasWon == false) //Actual logic of the game component
  {
    cout << j << ". Letters used so far: " ; //main UI
    sort(guessedLetter.begin(), guessedLetter.end());
    for(int a = 0; a < guessedLetter.size(); a++)
    {
      cout << guessedLetter[a] << " ";
    }

    cout << endl << "Letters found: "; //displays the letters found
    for(int a = 0; a < guessed.size(); a++)
    {
      cout << guessed[a] << " ";
    }

    j--;

    cout << endl;
    cout << "Guess a letter: "; //takes user input
    cin >> letterInput;
    if(letterInput == '~')
    {
      for(int d = 0; d < newList.size(); d++) // provides a list of words left
      {
        cout << newList[d] << ", ";
      }
      cout << endl;
    }
    else
    {
      found = false;
      letterInput = toupper(letterInput); //accounts for either uppper or lower case input
      index = -1;
      while(index < (int) guessed.size()){
        index = charPos(index+1, answer, letterInput);
        if ( index < (int)guessed.size()){
          guessed[index] = letterInput;
          found = true;
        }
      }
      if (found == false){
        guessedLetter.push_back(letterInput);
        for (int i = newList.size()-1; i >= 0 ; i--){
          index  = charPos(0, newList[i], letterInput);
          if (index > 0 && index < (int) guessed.size()){
            //cout << index << "N:" << newList[i] << endl;
            newList.erase(newList.begin() + i);
          }
        }
      }
      else{
        cout << "You found letter " << letterInput << endl; //more UI
        vector<int> indexList;
        index  = charPos(0, answer, letterInput);
        while(index < (int) guessed.size()){
          indexList.push_back(index);
          index = charPos(index+1, answer, letterInput);
        }
        for (int i = newList.size()-1; i >= 0 ; i--){
          index = -1;
          bool present = true;
          for(int j=0; j< indexList.size(); j++) {
            index  = charPos(index+1, newList[i], letterInput);
            if (indexList[j] != index )
            present = false;
          }
          if (present == false){
            //cout << index << "F:" << newList[i] << endl;
            newList.erase(newList.begin() + i);
          }
        }
      }
    }
    if(getDone(guessed) == true)
    {
      newList.erase(newList.begin());
      cout << "Now we have " << newList.size() << " words." << endl;
      for(int a = 0; a < guessed.size(); a++){
        cout << guessed[a] << " ";
      }
      cout << endl <<  "***Congratulations, you did it! ***" << endl; //completion code accounting for winning
      hasWon = true;
      break;
    }
    else{
      cout << "Now we have " << newList.size() << " words." << endl << endl;
    }
  }
}


int main()
{
  Hangman_Game(); //runs the entire game
  return 0;
}
