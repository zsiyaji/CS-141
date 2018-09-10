#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*
------------------------------------------------
    prog2memory.cpp
------------------------------------------------

    Program #2: Memory game of guessing which X or O changed.
    Class: CS 141
    Author: Zakariah Siyaji
    Lab: Tuesday 2pm
    System:  C++ Mac Xcode

------------------------------------------------
    Grading Rubric:
------------------------------------------------

    50 Execution points
    5 Displays header info on screen when run
    5 Displays instructions
    5 Output is formatted as shown in sample output
    3 Handles both upper and lower case input
    2 Input of 'X' in first prompt exits program
    5 Input can be adjacent or have spaces between them
    15 Displayed boards all have odd parity in rows and columns
    5 Repeated input of 'r' gives new valid random board each time
    5 Gives appropriate end of program messages

    45 Programming Style (Given only if program runs substantially correctly)
    5 Program naming convention is followed
    10 Meaningful identifier names
    10 Comments: Has header.  Comments on each block of code
    10 Appropriate data and control structures (-20 if using arrays or strings)
    10 Code Layout: Appropriate indentation and blank lines
------------------------------------------------
*/
char p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35;

void initializeBoard(){
  int row1CountX = 0;
  int row2CountX = 0;
  int row3CountX = 0;
  int row4CountX = 0;
  int row5CountX = 0;
  int row6CountX = 0;
  int column1CountX = 0;
  int column2CountX = 0;
  int column3CountX = 0;
  int column4CountX = 0;
  int column5CountX = 0;
  int column6CountX = 0;

  //assiging the random 'X' or 'O'
  srand(time(NULL));
  if (rand() % 2 == 0 ){
    p0 = 'O';
  }else{
    p0 = 'X';
    row1CountX++;
    column1CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p1 = 'O';
  }else{
    p1 = 'X';
    row1CountX++;
    column2CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p2 = 'O';
  }else{
    p2 = 'X';
    row1CountX++;
    column3CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p3 = 'O';
  }else{
    p3 = 'X';
    row1CountX++;
    column4CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p4 = 'O';
  }else{
    p4 = 'X';
    row1CountX++;
    column5CountX++;
  }
  
  if (row1CountX %2 == 1){
    p5 = 'O';
  }else{
    p5 = 'X';
    column6CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p6 = 'O';
  }else{
    p6 = 'X';
    row2CountX++;
    column1CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p7 = 'O';
  }else{
    p7 = 'X';
    row2CountX++;
    column2CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p8 = 'O';
  }else{
    p8 = 'X';
    row2CountX++;
    column3CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p9 = 'O';
  }else{
    p9 = 'X';
    row2CountX++;
    column4CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p10 = 'O';
  }else{
    p10 = 'X';
    row2CountX++;
    column5CountX++;
  }
  
  if (row2CountX %2 == 1){
    p11 = 'O';
  }else{
    p11 = 'X';
    column6CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p12 = 'O';
  }else{
    p12 = 'X';
    row3CountX++;
    column1CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p13 = 'O';
  }else{
    p13 = 'X';
    row3CountX++;
    column2CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p14 = 'O';
  }else{
    p14 = 'X';
    row3CountX++;
    column3CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p15 = 'O';
  }else{
    p15 = 'X';
    row3CountX++;
    column4CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p16 = 'O';
  }else{
    p16 = 'X';
    row3CountX++;
    column5CountX++;
  }
  
  if (row3CountX %2 == 1){
    p17 = 'O';
  }else{
    p17 = 'X';
    column6CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p18 = 'O';
  }else{
    p18 = 'X';
    row4CountX++;
    column1CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p19 = 'O';
  }else{
    p19 = 'X';
    row4CountX++;
    column2CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p20 = 'O';
  }else{
    p20 = 'X';
    row4CountX++;
    column3CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p21 = 'O';
  }else{
    p21 = 'X';
    row4CountX++;
    column4CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p22 = 'O';
  }else{
    p22 = 'X';
    row4CountX++;
    column5CountX++;
  }
  
  if (row4CountX %2 == 1){
    p23 = 'O';
  }else{
    p23 = 'X';
    column6CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p24 = 'O';
  }else{
    p24 = 'X';
    row5CountX++;
    column1CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p25 = 'O';
  }else{
    p25 = 'X';
    row5CountX++;
    column2CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p26 = 'O';
  }else{
    p26 = 'X';
    row5CountX++;
    column3CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p27 = 'O';
  }else{
    p27 = 'X';
    row5CountX++;
    column4CountX++;
  }
  
  if (rand() % 2 == 0 ){
    p28 = 'O';
  }else{
    p28 = 'X';
    row5CountX++;
    column5CountX++;
  }
  
  if (row5CountX %2 == 1){
    p29 = 'O';
  }else{
    p29 = 'X';
    column6CountX++;
  }
  
  if (column1CountX  % 2 == 1 ){
    p30 = 'O';
  }else{
    p30 = 'X';
  }
  
  if (column2CountX  % 2 == 1 ){
    p31 = 'O';
  }else{
    p31 = 'X';
  }
  
  if (column3CountX  % 2 == 1 ){
    p32 = 'O';
  }else{
    p32 = 'X';
  }
  
  if (column4CountX  % 2 == 1 ){
    p33 = 'O';
  }else{
    p33 = 'X';
  }
  
  if (column5CountX  % 2 == 1 ){
    p34 = 'O';
  }else{
    p34 = 'X';
  }
  
  if (column6CountX  % 2 == 1 ){
    p35 = 'O';
  }else{
    p35 = 'X';
  }
}

void flipChar(char ch1, int value){
  if (ch1 == 'a' || ch1 == 'A'){
      if (value == 1){
        if (p0 == 'X')
          p0 = 'O';
        else 
          p0 = 'X';
      }
      else if (value == 2){
        if (p1 == 'X')
          p1 = 'O';
        else 
          p1 = 'X';
      }
      else if (value == 3){
        if (p2 == 'X')
          p2 = 'O';
        else 
          p2 = 'X';
      }
      else if (value == 4){
        if (p3 == 'X')
          p3 = 'O';
        else 
          p3 = 'X';
      }
      else if (value == 5){
        if (p4 == 'X')
          p4 = 'O';
        else 
          p4 = 'X';
      }
      else if (value == 6){
        if (p5 == 'X')
          p5 = 'O';
        else 
          p5 = 'X';
      }
  }else if (ch1 == 'b' || ch1 == 'B'){
      if (value == 1){
        if (p6 == 'X')
          p6 = 'O';
        else 
          p6 = 'X';
      }
      else if (value == 2){
        if (p7 == 'X')
          p7 = 'O';
        else 
          p7 = 'X';
      }
      else if (value == 3){
        if (p8 == 'X')
          p8 = 'O';
        else 
          p8 = 'X';
      }
      else if (value == 4){
        if (p9 == 'X')
          p9 = 'O';
        else 
          p9 = 'X';
      }
      else if (value == 5){
        if (p10 == 'X')
          p10 = 'O';
        else 
          p10 = 'X';
      }
      else if (value == 6){
        if (p11 == 'X')
          p11 = 'O';
        else 
          p11 = 'X';
      }
  }else if (ch1 == 'c' || ch1 == 'C'){
      if (value == 1){
        if (p12 == 'X')
          p12 = 'O';
        else 
          p12 = 'X';
      }
      else if (value == 2){
        if (p13 == 'X')
          p13 = 'O';
        else 
          p13 = 'X';
      }
      else if (value == 3){
        if (p14 == 'X')
          p14 = 'O';
        else 
          p14 = 'X';
      }
      else if (value == 4){
        if (p15 == 'X')
          p15 = 'O';
        else 
          p15 = 'X';
      }
      else if (value == 5){
        if (p16 == 'X')
          p16 = 'O';
        else 
          p16 = 'X';
      }
      else if (value == 6){
        if (p17 == 'X')
          p17 = 'O';
        else 
          p17 = 'X';
      }
  }else if (ch1 == 'd' || ch1 == 'D'){
      if (value == 1){
        if (p18 == 'X')
          p18 = 'O';
        else 
          p18 = 'X';
      }
      else if (value == 2){
        if (p19 == 'X')
          p19 = 'O';
        else 
          p19 = 'X';
      }
      else if (value == 3){
        if (p20 == 'X')
          p20 = 'O';
        else 
          p20 = 'X';
      }
      else if (value == 4){
        if (p21 == 'X')
          p21 = 'O';
        else 
          p21 = 'X';
      }
      else if (value == 5){
        if (p22 == 'X')
          p22 = 'O';
        else 
          p22 = 'X';
      }
      else if (value == 6){
        if (p23 == 'X')
          p23 = 'O';
        else 
          p23 = 'X';
      }
  }else if (ch1 == 'e' || ch1 == 'E'){
      if (value == 1){
        if (p24 == 'X')
          p24 = 'O';
        else 
          p24 = 'X';
      }
      else if (value == 2){
        if (p25 == 'X')
          p25 = 'O';
        else 
          p25 = 'X';
      }
      else if (value == 3){
        if (p26 == 'X')
          p26 = 'O';
        else 
          p26 = 'X';
      }
      else if (value == 4){
        if (p27 == 'X')
          p27 = 'O';
        else 
          p27 = 'X';
      }
      else if (value == 5){
        if (p28 == 'X')
          p28 = 'O';
        else 
          p28 = 'X';
      }
      else if (value == 6){
        if (p29 == 'X')
          p29 = 'O';
        else 
          p29 = 'X';
      }
  }else if (ch1 == 'f' || ch1 == 'F'){
      if (value == 1){
        if (p30 == 'X')
          p30 = 'O';
        else 
          p30 = 'X';
      }
      else if (value == 2){
        if (p31 == 'X')
          p31 = 'O';
        else 
          p31 = 'X';
      }
      else if (value == 3){
        if (p32 == 'X')
          p32 = 'O';
        else 
          p32 = 'X';
      }
      else if (value == 4){
        if (p33 == 'X')
          p33 = 'O';
        else 
          p33 = 'X';
      }
      else if (value == 5){
        if (p34 == 'X')
          p34 = 'O';
        else 
          p34 = 'X';
      }
      else if (value == 6){
        if (p35 == 'X')
          p35 = 'O';
        else 
          p35 = 'X';
      }
  }
}
void printSymbol(int index){
  if (index / 6 == 0) 
    cout << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5   << " ";
  else if (index / 6 == 1)
    cout << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " ";
  else if (index / 6 == 2)
    cout << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " ";
  else if (index / 6 == 3)
    cout << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " ";
  else if (index / 6 == 4)
    cout << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " ";
  else if (index / 6 == 5)
    cout << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " ";
}

void printBoard(){
    //This function print the board on the console
    // printing the index of the columns
    cout << endl << endl;
    cout << "    1 2 3 4 5 6     " << endl;
    //one headerline for printing the symbols
    cout << "  - - - - - - - -   " << endl;
    for(int index=0;index<36; index = index + 6){
      if (index /6 == 0)
          cout << "A | ";
      else if (index /6 == 1)
          cout << "B | ";
      else if (index /6 == 2)
          cout << "C | ";
      else if (index /6 == 3)
          cout << "D | ";
      else if (index /6 == 4)
          cout << "E | ";
      else if (index /6 == 5)
          cout << "F | ";

      printSymbol(index);
      
      // printing the ending column for each for their respecitve row index 0 as A, 1 as B ....
      if (index % 6 == 0  && index /6 == 0)
        cout << "| A" << endl;
      else if (index % 6 == 0  && index /6 == 1)
        cout << "| B" << endl;
      else if (index % 6 == 0  && index /6 == 2)
        cout << "| C" << endl;
      else if (index % 6 == 0  && index /6 == 3)
        cout << "| D" << endl;
      else if (index % 6 == 0  && index /6 == 4)
        cout << "| E" << endl;
      else if (index % 6 == 0  && index /6 == 5)
        cout << "| F" << endl;
    }
    //printing the headerline
    cout << "  - - - - - - - -   " << endl << endl;
}
void gameBoard(){
    //setting the flag for continue to the loop if user enter 'r' or 'R'
    bool flag = true;
    //checking character input
    char ch1,ch3;
    int ch2,ch4;
    int i;
    while(flag == true){
      initializeBoard();
      printBoard();
      cout << "Enter r to randomize to board, or row and column to change a value -> " ;
      cin >> ch1;
      if (ch1 == 'r' || ch1 == 'R')
        continue; 
      else if (ch1 == 'x' || ch1 == 'X')
        break; 
      else{
        //getting another character except whitespace or null character
        cin >> ch2;
        //flip the O to X and X to O for give char ch1 and column ch2
        printBoard();
        
        flipChar(ch1,ch2);
        //ending the loop by setting flag as false
        flag = false;
        //printing the board
        for ( i=0;i < 25;i++)
          cout << endl;

        //print the mask board
        printBoard();
        cout << endl;
        cout << "What piece do you think it was? ";
        cin >> ch3 >> ch4;
        if (ch1 == ch3 && ch2 == ch4 )
          cout << "*** Congratulations, you did it! *** " << endl;
        else
          cout << " Sorry, it was " << ch1 << ch2 << ". Better luck next time. " << endl;
        cout << "Thank you for playing.  Exiting... " << endl;
      }
    }
}

int main(){
  cout << "Author:  Zakariah Siyaji" << endl;
  cout << "Class:   CS 141, Spring 2018"<< endl;
  cout << "Lab:     Tuesday 2pm" << endl;
  cout << "Program: #2, Memory Game"<< endl;
  cout << endl;
  cout << "Welcome to the memory game!" << endl;
  cout << endl;
  cout << "Look away from the board and have a helper enter r" << endl <<
    "to randomize the board until they have a random board" << endl <<
    "that they like. Then you glance at it and try to" << endl <<
    "imprint it in your mind and look away.  Your helper" << endl <<
    "will then select a single piece to be flipped by" << endl <<
    "choosing its row and column.  The changed board is then" << endl <<
    "displayed. You then must try to guess which one it was." << endl <<
    "Enter x to exit the program. " << endl;
  cout << endl;
  gameBoard();
  return 0;
}
