#include <iostream>
#include <string>
#include <locale>
using namespace std;
/* ------------------------------------------------
zsiyaj2Prog3.cpp

Program #3: Newton game to get 5 in a row.
Players alternate placing a piece or
rotating a column.

Class: CS 141
Author: Zakariah Siyaji
Lab: Tues 2pm
System:  C++ Mac Xcode

Grading Rubric:

50 Execution points
2 Displays header info and instructions on screen when run
5 Move number and character-to-move update correctly
3 Handles upper and lower-case user input, spaces between inputs, and 'X' to exit
5 Does error checking of user input for valid input and space in column
10 Handles 'R' to rotate a column
10 Correctly places pieces on board
15 Detects a win of 5 in a row, and gives the corresponding ending message

45 Programming Style (Given only if program runs substantially correctly)
5 Program naming convention is followed
10 Meaningful identifier names
10 Comments: Has header and this rubric.  Has comments on each block of code
10 Appropriate data and control structures
10 Code Layout: Appropriate indentation and blank lines
------------------------------------------------
*/


//                  1   2   3   4   5
//                 --- --- --- --- ---
// 0,0 is equal to  X   .   .   .   .

//                  1   2   3   4   5
//                 --- --- --- --- ---
// 0,1 is equal to  .   X   .   .   .

//                  1   2   3   4   5
//                 --- --- --- --- ---
// 0,2 is equal to  .   .   X   .   .

//                  1   2   3   4   5
//                 --- --- --- --- ---
// 0,3 is equal to  .   .   .   X   .


//                  1   2   3   4   5
//                 --- --- --- --- ---
// 0,4 is equal to  .   .   .   .   X

//Bottom Row

// 7,4 is equal to  .   .   .   .   X
//                 --- --- --- --- ---
//                  1   2   3   4   5

// 7,3 is equal to  .   .   .   X   .
//                 --- --- --- --- ---
//                  1   2   3   4   5

// 7,2 is equal to  .   .   X   .   .
//                 --- --- --- --- ---
//                  1   2   3   4   5

// 7,1 is equal to  .   X   .   .   .
//                 --- --- --- --- ---
//                  1   2   3   4   5

// 7,0 is equal to  X   .   .   .   .
//                 --- --- --- --- ---
//                  1   2   3   4   5

char updates[8][5] = {
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'}
};


void displayBoard(){
  cout << endl << endl;
  cout << "  1   2   3   4   5" << endl;
  cout << " --- --- --- --- ---";
  //We now have 8 columns
  for(int i = 0; i < 8; i++){
    //By adding a space every time we loop
    cout << endl;
    //we can add a new row, as intended
    for(int j = 0; j < 5; j++){
      //This gives us the 5 rows
      cout << "  " << updates[i][j] << " ";
    }
  }
  cout << endl;
  cout << " --- --- --- --- ---" << endl;
  cout << "  1   2   3   4   5" << endl;
}
bool O_hasWon(){
  if ((updates[0][0] == 'O')&&(updates[0][1] == 'O')&&(updates[0][2] == 'O')&&(updates[0][3] == 'O')&&(updates[0][4] == 'O')){
    return true;
  }

  else if ((updates[1][0] == 'O')&&(updates[1][1] == 'O')&&(updates[1][2] == 'O')&&(updates[1][3] == 'O')&&(updates[1][4] == 'O')){
    return true;
  }

  else if ((updates[2][0] == 'O')&&(updates[2][1] == 'O')&&(updates[2][2] == 'O')&&(updates[2][3] == 'O')&&(updates[2][4] == 'O')){
    return true;
  }

  else if ((updates[3][0] == 'O')&&(updates[3][1] == 'O')&&(updates[3][2] == 'O')&&(updates[3][3] == 'O')&&(updates[3][4] == 'O')){
    return true;
  }

  else if ((updates[4][0] == 'O')&&(updates[4][1] == 'O')&&(updates[4][2] == 'O')&&(updates[4][3] == 'O')&&(updates[4][4] == 'O')){
    return true;
  }

  else if ((updates[5][0] == 'O')&&(updates[5][1] == 'O')&&(updates[5][2] == 'O')&&(updates[5][3] == 'O')&&(updates[5][4] == 'O')){
    return true;
  }

  else if ((updates[6][0] == 'O')&&(updates[6][1] == 'O')&&(updates[6][2] == 'O')&&(updates[6][3] == 'O')&&(updates[6][4] == 'O')){
    return true;
  }

  else if ((updates[7][0] == 'O')&&(updates[7][1] == 'O')&&(updates[7][2] == 'O')&&(updates[7][3] == 'O')&&(updates[7][4] == 'O')){
    return true;
  }

  /*--------------------------------------------------------------------------------------------------------------------------*/
  //diagnal from top left to bottom right
  else if ((updates[0][0] == 'O')&&(updates[1][1] == 'O')&&(updates[2][2] == 'O')&&(updates[3][3] == 'O')&&(updates[4][4] == 'O')){
    return true;
  }

  else if ((updates[1][0] == 'O')&&(updates[2][1] == 'O')&&(updates[3][2] == 'O')&&(updates[4][3] == 'O')&&(updates[5][4] == 'O')){
    return true;
  }

  else if ((updates[2][0] == 'O')&&(updates[3][1] == 'O')&&(updates[4][2] == 'O')&&(updates[5][3] == 'O')&&(updates[6][4] == 'O')){
    return true;
  }

  else if ((updates[3][0] == 'O')&&(updates[4][1] == 'O')&&(updates[5][2] == 'O')&&(updates[6][3] == 'O')&&(updates[7][4] == 'O')){
    return true;
  }
  /*--------------------------------------------------------------------------------------------------------------------------*/
  //diagnal from top right to bottom left

  else if ((updates[0][4] == 'O')&&(updates[1][3] == 'O')&&(updates[2][2] == 'O')&&(updates[3][1] == 'O')&&(updates[4][0] == 'O')){
    return true;
  }

  else if ((updates[4][1] == 'O')&&(updates[2][3] == 'O')&&(updates[3][2] == 'O')&&(updates[4][1] == 'O')&&(updates[5][0] == 'O')){
    return true;
  }

  else if ((updates[2][4] == 'O')&&(updates[3][3] == 'O')&&(updates[4][2] == 'O')&&(updates[5][1] == 'O')&&(updates[6][0] == 'O')){
    return true;
  }

  else if ((updates[3][4] == 'O')&&(updates[4][3] == 'O')&&(updates[5][2] == 'O')&&(updates[6][1] == 'O')&&(updates[7][0] == 'O')){
    return true;
  }

  /*--------------------------------------------------------------------------------------------------------------------------*/
  //we will now check each column for 4 possible streaks
  // column 1:
  else if ((updates[0][0] == 'O')&&(updates[1][0] == 'O')&&(updates[2][0] == 'O')&&(updates[3][0] == 'O')&&(updates[4][0] == 'O')){
    return true;
  }

  else if ((updates[1][0] == 'O')&&(updates[2][0] == 'O')&&(updates[3][0] == 'O')&&(updates[4][0] == 'O')&&(updates[5][0] == 'O')){
    return true;
  }

  else if ((updates[2][0] == 'O')&&(updates[3][0] == 'O')&&(updates[4][0] == 'O')&&(updates[5][0] == 'O')&&(updates[6][0] == 'O')){
    return true;
  }

  else if ((updates[3][0] == 'O')&&(updates[4][0] == 'O')&&(updates[5][0] == 'O')&&(updates[6][0] == 'O')&&(updates[7][0] == 'O')){
    return true;
  }
  // column 2:
  else if ((updates[0][1] == 'O')&&(updates[1][1] == 'O')&&(updates[2][1] == 'O')&&(updates[3][1] == 'O')&&(updates[4][1] == 'O')){
    return true;
  }

  else if ((updates[1][1] == 'O')&&(updates[2][1] == 'O')&&(updates[3][1] == 'O')&&(updates[4][1] == 'O')&&(updates[5][1] == 'O')){
    return true;
  }

  else if ((updates[2][1] == 'O')&&(updates[3][1] == 'O')&&(updates[4][1] == 'O')&&(updates[5][1] == 'O')&&(updates[6][1] == 'O')){
    return true;
  }

  else if ((updates[3][1] == 'O')&&(updates[4][1] == 'O')&&(updates[5][1] == 'O')&&(updates[6][1] == 'O')&&(updates[7][1] == 'O')){
    return true;
  }
  // column 3:
  else if ((updates[0][2] == 'O')&&(updates[1][2] == 'O')&&(updates[2][2] == 'O')&&(updates[3][2] == 'O')&&(updates[4][2] == 'O')){
    return true;
  }

  else if ((updates[1][2] == 'O')&&(updates[2][2] == 'O')&&(updates[3][2] == 'O')&&(updates[4][2] == 'O')&&(updates[5][2] == 'O')){
    return true;
  }

  else if ((updates[2][2] == 'O')&&(updates[3][2] == 'O')&&(updates[4][2] == 'O')&&(updates[5][2] == 'O')&&(updates[6][2] == 'O')){
    return true;
  }

  else if ((updates[3][2] == 'O')&&(updates[4][2] == 'O')&&(updates[5][2] == 'O')&&(updates[6][2] == 'O')&&(updates[7][2] == 'O')){
    return true;
  }
  //column 4:
  else if ((updates[0][3] == 'O')&&(updates[1][3] == 'O')&&(updates[2][3] == 'O')&&(updates[3][3] == 'O')&&(updates[4][3] == 'O')){
    return true;
  }

  else if ((updates[1][3] == 'O')&&(updates[2][3] == 'O')&&(updates[3][3] == 'O')&&(updates[4][3] == 'O')&&(updates[5][3] == 'O')){
    return true;
  }

  else if ((updates[2][3] == 'O')&&(updates[3][3] == 'O')&&(updates[4][3] == 'O')&&(updates[5][3] == 'O')&&(updates[6][3] == 'O')){
    return true;
  }

  else if ((updates[3][3] == 'O')&&(updates[4][3] == 'O')&&(updates[5][3] == 'O')&&(updates[6][3] == 'O')&&(updates[7][3] == 'O')){
    return true;
  }
  //column 5:
  else if ((updates[0][4] == 'O')&&(updates[1][4] == 'O')&&(updates[2][4] == 'O')&&(updates[3][4] == 'O')&&(updates[4][4] == 'O')){
    return true;
  }

  else if ((updates[1][4] == 'O')&&(updates[2][4] == 'O')&&(updates[3][4] == 'O')&&(updates[4][4] == 'O')&&(updates[5][4] == 'O')){
    return true;
  }

  else if ((updates[2][4] == 'O')&&(updates[3][4] == 'O')&&(updates[4][4] == 'O')&&(updates[5][4] == 'O')&&(updates[6][4] == 'O')){
    return true;
  }

  else if ((updates[3][4] == 'O')&&(updates[4][4] == 'O')&&(updates[5][4] == 'O')&&(updates[6][4] == 'O')&&(updates[7][4] == 'O')){
    return true;
  }
  else{
    return false;
  }
}


bool X_hasWon(){
  if ((updates[0][0] == 'X')&&(updates[0][1] == 'X')&&(updates[0][2] == 'X')&&(updates[0][3] == 'X')&&(updates[0][4] == 'X')){
    return true;
  }

  else if ((updates[1][0] == 'X')&&(updates[1][1] == 'X')&&(updates[1][2] == 'X')&&(updates[1][3] == 'X')&&(updates[1][4] == 'X')){
    return true;
  }

  else if ((updates[2][0] == 'X')&&(updates[2][1] == 'X')&&(updates[2][2] == 'X')&&(updates[2][3] == 'X')&&(updates[2][4] == 'X')){
    return true;
  }

  else if ((updates[3][0] == 'X')&&(updates[3][1] == 'X')&&(updates[3][2] == 'X')&&(updates[3][3] == 'X')&&(updates[3][4] == 'X')){
    return true;
  }

  else if ((updates[4][0] == 'X')&&(updates[4][1] == 'X')&&(updates[4][2] == 'X')&&(updates[4][3] == 'X')&&(updates[4][4] == 'X')){
    return true;
  }

  else if ((updates[5][0] == 'X')&&(updates[5][1] == 'X')&&(updates[5][2] == 'X')&&(updates[5][3] == 'X')&&(updates[5][4] == 'X')){
    return true;
  }

  else if ((updates[6][0] == 'X')&&(updates[6][1] == 'X')&&(updates[6][2] == 'X')&&(updates[6][3] == 'X')&&(updates[6][4] == 'X')){
    return true;
  }

  else if ((updates[7][0] == 'X')&&(updates[7][1] == 'X')&&(updates[7][2] == 'X')&&(updates[7][3] == 'X')&&(updates[7][4] == 'X')){
    return true;
  }

  /*--------------------------------------------------------------------------------------------------------------------------*/
  //diagnal from top left to bottom right
  else if ((updates[0][0] == 'X')&&(updates[1][1] == 'X')&&(updates[2][2] == 'X')&&(updates[3][3] == 'X')&&(updates[4][4] == 'X')){
    return true;
  }

  else if ((updates[1][0] == 'X')&&(updates[2][1] == 'X')&&(updates[3][2] == 'X')&&(updates[4][3] == 'X')&&(updates[5][4] == 'X')){
    return true;
  }

  else if ((updates[2][0] == 'X')&&(updates[3][1] == 'X')&&(updates[4][2] == 'X')&&(updates[5][3] == 'X')&&(updates[6][4] == 'X')){
    return true;
  }

  else if ((updates[3][0] == 'X')&&(updates[4][1] == 'X')&&(updates[5][2] == 'X')&&(updates[6][3] == 'X')&&(updates[7][4] == 'X')){
    return true;
  }
  /*--------------------------------------------------------------------------------------------------------------------------*/
  //diagnal from top right to bottom left

  else if ((updates[0][4] == 'X')&&(updates[1][3] == 'X')&&(updates[2][2] == 'X')&&(updates[3][1] == 'X')&&(updates[4][0] == 'X')){
    return true;
  }

  else if ((updates[4][1] == 'X')&&(updates[2][3] == 'X')&&(updates[3][2] == 'X')&&(updates[4][1] == 'X')&&(updates[5][0] == 'X')){
    return true;
  }

  else if ((updates[2][4] == 'X')&&(updates[3][3] == 'X')&&(updates[4][2] == 'X')&&(updates[5][1] == 'X')&&(updates[6][0] == 'X')){
    return true;
  }

  else if ((updates[3][4] == 'X')&&(updates[4][3] == 'X')&&(updates[5][2] == 'X')&&(updates[6][1] == 'X')&&(updates[7][0] == 'X')){
    return true;
  }

  /*--------------------------------------------------------------------------------------------------------------------------*/
  //we will now check each column for 4 possible streaks
  // column 1:
  else if ((updates[0][0] == 'X')&&(updates[1][0] == 'X')&&(updates[2][0] == 'X')&&(updates[3][0] == 'X')&&(updates[4][0] == 'X')){
    return true;
  }

  else if ((updates[1][0] == 'X')&&(updates[2][0] == 'X')&&(updates[3][0] == 'X')&&(updates[4][0] == 'X')&&(updates[5][0] == 'X')){
    return true;
  }

  else if ((updates[2][0] == 'X')&&(updates[3][0] == 'X')&&(updates[4][0] == 'X')&&(updates[5][0] == 'X')&&(updates[6][0] == 'X')){
    return true;
  }

  else if ((updates[3][0] == 'X')&&(updates[4][0] == 'X')&&(updates[5][0] == 'X')&&(updates[6][0] == 'X')&&(updates[7][0] == 'X')){
    return true;
  }
  // column 2:
  else if ((updates[0][1] == 'X')&&(updates[1][1] == 'X')&&(updates[2][1] == 'X')&&(updates[3][1] == 'X')&&(updates[4][1] == 'X')){
    return true;
  }

  else if ((updates[1][1] == 'X')&&(updates[2][1] == 'X')&&(updates[3][1] == 'X')&&(updates[4][1] == 'X')&&(updates[5][1] == 'X')){
    return true;
  }

  else if ((updates[2][1] == 'X')&&(updates[3][1] == 'X')&&(updates[4][1] == 'X')&&(updates[5][1] == 'X')&&(updates[6][1] == 'X')){
    return true;
  }

  else if ((updates[3][1] == 'X')&&(updates[4][1] == 'X')&&(updates[5][1] == 'X')&&(updates[6][1] == 'X')&&(updates[7][1] == 'X')){
    return true;
  }
  // column 3:
  else if ((updates[0][2] == 'X')&&(updates[1][2] == 'X')&&(updates[2][2] == 'X')&&(updates[3][2] == 'X')&&(updates[4][2] == 'X')){
    return true;
  }

  else if ((updates[1][2] == 'X')&&(updates[2][2] == 'X')&&(updates[3][2] == 'X')&&(updates[4][2] == 'X')&&(updates[5][2] == 'X')){
    return true;
  }

  else if ((updates[2][2] == 'X')&&(updates[3][2] == 'X')&&(updates[4][2] == 'X')&&(updates[5][2] == 'X')&&(updates[6][2] == 'X')){
    return true;
  }

  else if ((updates[3][2] == 'X')&&(updates[4][2] == 'X')&&(updates[5][2] == 'X')&&(updates[6][2] == 'X')&&(updates[7][2] == 'X')){
    return true;
  }
  //column 4:
  else if ((updates[0][3] == 'X')&&(updates[1][3] == 'X')&&(updates[2][3] == 'X')&&(updates[3][3] == 'X')&&(updates[4][3] == 'X')){
    return true;
  }

  else if ((updates[1][3] == 'X')&&(updates[2][3] == 'X')&&(updates[3][3] == 'X')&&(updates[4][3] == 'X')&&(updates[5][3] == 'X')){
    return true;
  }

  else if ((updates[2][3] == 'X')&&(updates[3][3] == 'X')&&(updates[4][3] == 'X')&&(updates[5][3] == 'X')&&(updates[6][3] == 'X')){
    return true;
  }

  else if ((updates[3][3] == 'X')&&(updates[4][3] == 'X')&&(updates[5][3] == 'X')&&(updates[6][3] == 'X')&&(updates[7][3] == 'X')){
    return true;
  }
  //column 5:
  else if ((updates[0][4] == 'X')&&(updates[1][4] == 'X')&&(updates[2][4] == 'X')&&(updates[3][4] == 'X')&&(updates[4][4] == 'X')){
    return true;
  }

  else if ((updates[1][4] == 'X')&&(updates[2][4] == 'X')&&(updates[3][4] == 'X')&&(updates[4][4] == 'X')&&(updates[5][4] == 'X')){
    return true;
  }

  else if ((updates[2][4] == 'X')&&(updates[3][4] == 'X')&&(updates[4][4] == 'X')&&(updates[5][4] == 'X')&&(updates[6][4] == 'X')){
    return true;
  }

  else if ((updates[3][4] == 'X')&&(updates[4][4] == 'X')&&(updates[5][4] == 'X')&&(updates[6][4] == 'X')&&(updates[7][4] == 'X')){
    return true;
  }
  else{
    return false;
  }
}


bool isEmpty(int x, int y) { //identifies positions with a period
  if(updates[x][y] == '.')   //as locations that are empty
  return true;
  else
  return false;
}


void playBoard(){
  //instead of stuffing our main with a ton of code
  //we can just create a board function that we can
  //manipulate time and time again!
  bool flag = true;
  int index = 1;
  int col;
  int i;
  char ch1;
  char ch2;
  while((!O_hasWon()) && (!X_hasWon())){ //As long as neither Player X nor Player O
    if ( flag == true){                  //has won, the code with continue until a player wins
      cout << index << ". Enter column number to place X or 'r' to rotate: ";
    }
    else{
      cout << index << ". Enter column number to place O or 'r' to rotate: ";
    }
    index++;
    cin >> ch1;
    if (ch1 == 'x' || ch1 == 'X'){ //taking into account a player attempting to leave the game
      cout << "You have exited the code" << endl;
      break;
    }
    else if (ch1 == 'r' || ch1 == 'R'){ //taking into account a player attempting to rotate a piece
      cin >> ch2;
      if ( ch2 > '0' && ch2 < '6'){
        col = (int) (ch2 - 49); //saving the character of the rotating column
        ch1 = updates[7][col];
        for(i = 6; i > 0; i--){
          if (isEmpty(i,col))
          break;
          else
          updates[i+1][col] = updates[i][col];
        }
        updates[i+1][col] = ch1;
        if ( flag == true) //method to alternate between users, another possible method
        flag = false;      //would be to create an iterator and set odd numbers to Player X
        else               //and even numbers to Player O, this would also alternate turns
        flag = true;
        displayBoard();   //updating the new board
      }
      else
      cout << "*** Invalid input.  Please retry..." << endl; //accounts for invalid moves
    }
    else if ( ch1 > '0' && ch1 < '6'){
      col = (int) (ch1 - 49);
      for(i = 7; i >= 0; i--){
        if (isEmpty(i,col))
        break;
      }
      if ( i < 0 ){ //we also accout for the index of each column so that it does not go out of bound
        cout << "*** Sorry, that column is already full.  Please choose another." << endl;
      }
      else{
        if ( flag == true){ //alternating between players and their X's and O's
          updates[i][col] = 'X';
          flag = false;
        }
        else{ //alternating between players and their X's and O's
          updates[i][col] = 'O';
          flag = true;
        }
        displayBoard(); //refresh the board after an update is added
      }
    }
    else
    cout << "*** Invalid input.  Please retry..." << endl;
  }
  if (O_hasWon())
  cout << "O has won the game !" << endl; //if Player O has won the game then we congratulate him
  else if (X_hasWon())
  cout << "X has won the game !" << endl; //if Player X has won the game then we congratulate him

}

int main(){
  //Below is the standard practice for all programs
  cout << "Author:  Zakariah Siyaji" << endl <<
  "Class:   CS 141, Spring 2018" << endl <<
  "Lab:     Mon 2pm" << endl <<
  "Program: #3, Newton Game" << endl <<
  "Xcode on a Mac" << endl << endl << endl;

  cout << "Welcome to the game of Newton, where you try to be the first" << endl <<
  "to get 5 in a row either vertically, horizontally or diagonally." << endl <<
  "Two players alternate making moves.  On each turn you may enter" << endl <<
  "the column number where your piece will be placed, where that" << endl <<
  "piece is inserted from the top and slides down as far as it can" << endl <<
  "go in that column.  You may also enter 'r' to rotate a piece out" << endl <<
  "of the bottom of a column to be dropped back in at the top of" << endl <<
  "that column.  Enter 'x' to exit." << endl;
  displayBoard(); //we print out an initial version of the board
  playBoard();    //plays the actual game itself
  return 0;
}
