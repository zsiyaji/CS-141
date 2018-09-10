/*-------------------------------------------------------------------------------------
   RicoRobotsClasses.cpp
        Play the game of Ricochet Robots, similar
        to that seen online at: http://www.braunston.com/kevin/rrobot/rrobot.html
        This version uses a class to store the board.

   Class: CS 142, Spring 2018
   Lab: Englebert Humberdink, Mon. 5:00 AM
   System: Xcode on an iMac

   @author  Dale Reed
   @version April 14, 2018

   There are a few tricky aspects to keep track of:
   1. A robot cannot move ontop of another robot.
   2. A robot (numbered 1..4) that is not the goal robot can move on top of the destination
      letter.  If it does, then the letter disappears.  Once non-goal-robot moves off,
      then the goal letter must reappear.

  Sample run of the program:
        Author: Dale Reed
        Program 4: RicoRobots in C++
        TA: Billie Joe Armstrong, T 6:00 AM
        March 22, 2018
        Welcome to Ricochet Robots
        ('Ricochet Robot' is a registered trademark of Hans im Glück
        Munich, Germany, 1999. The game was created by Alex Randolph.)

        The object of the game is to get the designated numbered robot
        to the indicated letter position.
        The numbered squares are all robots.  They unfortunately have
        no brakes, and so will continue in whatever direction they are
        moving until they encountar an obstacle.
        For each move enter the robot number and the desired direction.
        For instance entering
           1 U
        would move the #1 robot up as far as it can go.
        The first letter of input is the robot number (1 - 4),
        and the second letter is the direction:
          (L=left, U=up, R=right, D=down)
        Enter x to exit.  Have fun!

        Enter 'r' for random robot and goal, 'd' for default or 's' to select: d
        Move robot 2 to square M
          ----------------------------------------------------------------
         | .   .   .   .   . | .   .   .   .   .   . | .   .   .   .   .  |
         |                                                                |
         | .   .   . | .   .   .   .   .   . | .   .   .   .   .   .   .  |
         |        ---                         ---                 ---     |
         | .   .   .   .   .   .   .   .   .   .   .   .   .   .   . | .  |
         |                                                                |
         | . | .   .   .   .   .   .   .   .   .   .   .   .   .   .   .  |
         |    ---                 ---                                     |
         | .   .   .   .   .   . | .   .   .   .   . | .   .   .   .   .  |
         |---                                     ---                 --- |
         | .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   4  |
         |                    ---                         ---             |
         | .   .   .   .   .   . | .   .   .   .   .   . | .   .   .   .  |
         |                            --- ---                             |
         | .   .   .   . | .   .   . | .   . | .   .   .   .   .   .   .  |
         |            ---                                                 |
         | .   .   .   .   .   .   . | .   . | .   .   .   .   .   .   .  |
         |    ---             ---     --- ---                             |
         | .   . | .   .   . | .   .   .   .   .   .   .   .   .   .   .  |
         |                                                            --- |
         | .   .   .   .   .   .   .   .   . | .   .   .   .   .   .   .  |
         |---                             ---                 ---         |
         | .   .   .   .   .   .   .   .   .   .   .   .   . | 3   .   .  |
         |                                                                |
         | .   .   .   .   .   .   M | .   .   .   .   .   .   .   .   .  |
         |                        ---                                     |
         | .   .   .   .   .   .   .   .   . | .   .   .   .   .   .   .  |
         |                                    ---                 ---     |
         | .   . | .   .   .   .   .   .   .   .   .   .   .   .   1 | .  |
         |        ---                                                     |
         | .   .   .   .   .   . | .   .   .   .   .   . | .   .   .   2  |
          ----------------------------------------------------------------

        1. Please enter the robot to move and the direction (e.g. 2 r): 2u

        Move robot 2 to square M
          ----------------------------------------------------------------
         | .   .   .   .   . | .   .   .   .   .   . | .   .   .   .   .  |
         |                                                                |
         | .   .   . | .   .   .   .   .   . | .   .   .   .   .   .   .  |
         |        ---                         ---                 ---     |
         | .   .   .   .   .   .   .   .   .   .   .   .   .   .   . | .  |
         |                                                                |
         | . | .   .   .   .   .   .   .   .   .   .   .   .   .   .   .  |
         |    ---                 ---                                     |
         | .   .   .   .   .   . | .   .   .   .   . | .   .   .   .   .  |
         |---                                     ---                 --- |
         | .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   4  |
         |                    ---                         ---             |
         | .   .   .   .   .   . | .   .   .   .   .   . | .   .   .   .  |
         |                            --- ---                             |
         | .   .   .   . | .   .   . | .   . | .   .   .   .   .   .   .  |
         |            ---                                                 |
         | .   .   .   .   .   .   . | .   . | .   .   .   .   .   .   .  |
         |    ---             ---     --- ---                             |
         | .   . | .   .   . | .   .   .   .   .   .   .   .   .   .   .  |
         |                                                            --- |
         | .   .   .   .   .   .   .   .   . | .   .   .   .   .   .   2  |
         |---                             ---                 ---         |
         | .   .   .   .   .   .   .   .   .   .   .   .   . | 3   .   .  |
         |                                                                |
         | .   .   .   .   .   .   M | .   .   .   .   .   .   .   .   .  |
         |                        ---                                     |
         | .   .   .   .   .   .   .   .   . | .   .   .   .   .   .   .  |
         |                                    ---                 ---     |
         | .   . | .   .   .   .   .   .   .   .   .   .   .   .   1 | .  |
         |        ---                                                     |
         | .   .   .   .   .   . | .   .   .   .   .   . | .   .   .   .  |
          ----------------------------------------------------------------

        2. Please enter the robot to move and the direction (e.g. 2 r):
  -------------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstring>      // for getline
#include <cstdlib>      // for the system command
#include <cctype>       // For the letter checking functions, e.g. toupper( )
#include <fstream>      // For file input and output
#include <ctime>        // For time()
using namespace std;

// Global data structure for board
const int Bedge = 16;
const int Bsize = Bedge * Bedge;
const int Nrobots = 4;
// declare constants to later use instead of numbers to select values from board
const int Nelems = 5;   // Number of elements for each Player, enumerated below
const int Player = 0;    // to reference the character, such as in: board[ i][ Player]
const int LEFT = 1;     // to reference the left wall character, such as in: board[ i][ LEFT]
const int ABOVE = 2;    // to reference the above wall character, such as in: board[ i][ ABOVE]
const int RIGHT = 3;    // to reference the right wall character, such as in: board[ i][ RIGHT]
const int BELOW = 4;    // to reference the below wall character, such as in: board[ i][ BELOW]

class Board
{
    public:
        // Constructors
        Board() {
            // Create the default board values, and walls around the borders.
            int i = 0;
            while(i<Bsize)
            {
              board[ i][ Player]= '.';    // Set each playing Player default
              // set the default wall values to be blank
              board[ i][ LEFT]= ' ';
              board[ i][ ABOVE]= ' ';
              board[ i][ RIGHT]= ' ';
              board[ i][ BELOW]=  ' ';

              // reset the edge Players
              // reset the left wall if Player is on left edge
              if( (i % Bedge) == 0) {
                  board[ i][ LEFT]= '|';
              }
              // reset the above wall if Player is on top edge
              if( i < Bedge) {
                  board[ i][ ABOVE]= '-';
              }
              // reset the right wall if Player is on right edge
              if( ((i+1) % Bedge) == 0) {
                  board[ i][ RIGHT]= '|';
              }
              // reset the below wall if Player is on bottom edge
              if( i >= (Bsize - Bedge) ) {
                  board[ i][ BELOW]= '-';
              }
              i++;
            }
        }//end Board()

        // Getters / Setters
        void setPlayerAt( int index, char c) { board[ index][ Player] = c; }
        void setBorderAt( int index, int direction, char c) { board[ index][ direction] = c; }
        void setRobotAt( int index, int value) { thePlayers[ index] = value; }
        void setkeyPlayer( int robotValue) { keyPlayer = robotValue; }
        void setgoalletter( char c) { goalletter = c; }
        void setdestination( int thePosition) { destination = thePosition; }
        void setnumPlayers( int theNumber) { numPlayers = theNumber; }

        char getPlayerAt( int index) { return board[ index][ Player]; }
        char getBorderAt( int index, int direction) { return board[ index][ direction]; }
        int  getRobotAt( int index) { return thePlayers[ index]; }
        int  getkeyPlayer() { return keyPlayer; }
        int  getkeyPlayerIndex() { return thePlayers[ keyPlayer]; }
        char getgoalletter() { return goalletter; }
        int  getdestination() { return destination; }
        int  getnumPlayers() { return numPlayers; }

        // Utility functions
        void readFromFileAndModifyBoard();
        void display();
        void finddestination();   // Get the index of the letter for the winning position

    private:
        // board itself is represented by a one-dimensional array.
        // The other entries are used to keep track of walls.  Each row
        // in board array will contain the character to be displayed,
        // followed by any "walls" to be displayed around the displayed
        // character.  For instance the first couple of entries are be:
        //
        //       Player   LEFT ABOVE RIGHT BELOW
        //      ---0---  --1-  --2-  --3-  --4-
        //    0    .       |     _
        //    1    .             _
        //   ...
        //   255   .                   |     _
        //
        char board[ Bsize][ Nelems];
        // Declare the 4 robots, which will store the board position of where they are found
        // Robots are displayed using values 1-4.  We declare 5 robots, though we will never use
        // the 0th robot in the array, so that we can use the robot digit itself as the index.
        int thePlayers[ Nrobots + 1] = {0,0,0,0,0};
        int keyPlayer;                  // the robot that needs to reach the goal
        char goalletter;         // the goal letter
        int destination;               // Index position of the goal letter
        int numPlayers;  // Number of destination Players.  Value comes from the data file.
};


//-------------------------------------------------------------------------------------
// readFromFileAndModifyBoard() - Read from data file, updating board accordingly
//
void Board::readFromFileAndModifyBoard()
{
    int numberOfSpecialSquares;  // Read from file, denotes number of Players with some kind of wall
    string inputLine;            // Input line from file
    int PlayerNumber;             // PlayerNumber for each square defined in data file
    char c;

    ifstream inStream;           // declare an input file stream
    inStream.open("board.txt");  // Open input file, associating the actual file name with "inStream"
    if ( inStream.fail() ) {
        cout << "Input file opening failed.  Exiting...\n\n";
        exit(-1);
    }

    // Read from file one line at a time.  First read the top three data file lines which are documentation.
    getline( inStream, inputLine);
    getline( inStream, inputLine);
    getline( inStream, inputLine);

    inStream >> numPlayers;      // read how many destination Players there are
    inStream >> numberOfSpecialSquares;         // number of square with walls around them somewhere
    inStream.get( c);                           // Get rid of return character at end of current line
                                                // to get ready for reading a line at a time below

    // process the special squares, updating the board
    int i = 0;
    while(i<numberOfSpecialSquares)
    {
      getline( inStream, inputLine);
      char *pInputLine = &inputLine[0];
      // Extract the Player number from the input line array
      sscanf( pInputLine, "%d", &PlayerNumber);
      // Advance the inputLine pointer to the space after the number
      pInputLine = strchr( pInputLine, ' ');

      // Read the information on whether or not there is each of the potential 4 walls.
      // The four values read correspond in order to the Players on all four sides,
      // which are defined as global constants for the values LEFT=1, ABOVE=2, RIGHT=3, BELOW=4
      int position = 1;
      while(position<=4)
      {
        pInputLine++;   // advance to next character to be read
        sscanf( pInputLine, " %c", &c);         // Read the next potential wall character
        // Convert it to a blank if it was '0'.  '0' was left in input file to make it easier to read.
        if( c=='0') {
            c = ' ';
        }
        board[ PlayerNumber][ position] = c;
        position++;
      }

      pInputLine++;

      // See if there is a Player letter still to be read on this input line.
      // Do this by finding the end of the line, and seeing the length of the string
      // after that.
      // An inputline sample for Player 18 would be:
      // 18 00|- A
      if( strlen( pInputLine) > 0) {
          sscanf( pInputLine, " %c", &board[ PlayerNumber][ Player]);
      }
      i++;
    }

    // At the end of the data file read the information on the location of the robots, updating the board.
    char junk[80];           // used to read and discard input file information
    // Loop starts counting from 1 (rather than 0), since we ignore the 0th position
    // of the robots array, so that robot numbers correspond to what is shown
    // on the board.
    i = 1;
    while(i<=Nrobots)
    {
      inStream >> thePlayers[ i];
      inStream.getline( junk, '\n');    // discard rest of line, which is color information, if using graphics
      // set robot on board, converting the integer value to a character
      board[ thePlayers[ i]][ Player] = (char)('0'+i);     // record the robot number in place on board
      i++;
    }

    inStream.close();         // close the input file stream
}//end Board::readFromFileAndModifyBoard()


//-------------------------------------------------------------------------------------
// Display the Board
//
void Board::display( )
{
    // display the top edge
    cout << "  ---------------------------------------------------------------- " << endl;

    // display the "body" of the board
    int i =0;
    while(i<Bsize)
    {
      // Figure out what character should be displayed to the left.  It will
      // be a wall if the current spot has a left wall, or if the spot to the
      // left has a right wall.

      char leftCharacter = board[ i][ LEFT];   // set left display char
      // See if the Player to the left has a right wall.  Don't do this for the
      // first Player on the board, since it has no left neighbor.
      if ( (i>0) && (board[ i-1][ RIGHT] != ' ')) {
          leftCharacter = board[ i-1][ RIGHT];
      }
      cout << " " << leftCharacter << " " << board[ i][ Player];
      // see if we're at the end of a row
      if( ((i+1) % Bedge) == 0) {
          // we are at the end of a row, so display right wall and go to next line
          cout << "  " << board[ i][ RIGHT] << endl;
          // Now display any walls immediately below the line of Players just displayed
          // Backup our index counter j to the beginning of this line again, to find any
          // walls displayed below this line.  Don't do it for the bottom row though.
          if( i < Bsize - Bedge) {

              cout << " |";       // display the left boundary
              int j =1;
              while(j<(i+1))
              {
                // Set the character to be displayed.  This is a wall if the
                // current spot has a wall below, or if the spot below has a wall
                // above.
                char belowCharacter = board[ j][ BELOW];
                // Only check the square below if we're NOT on the bottom row

                if ( (j<(Bsize - Bedge)) &&      // verify not on bottom row
                    (board[ j+16][ ABOVE] != ' ')) {    // Player below has wall above
                    belowCharacter = board[ j+16][ ABOVE];
                }
                int k = 0;
                while(k<3)
                {
                  cout << belowCharacter;
                  k++;
                }
                // display extra spaces, if we're not at the end of a row
                if( ((j+1) % Bedge) != 0) {
                    cout << " ";
                }
                j++;
              }.
              cout << " |" << endl;       // display the right boundary
          }//end if( i< Bsize...

      }//end if( ((i+1...
      i++;
    }

    // display the bottom edge
    cout << "  ---------------------------------------------------------------- " << endl;
    cout << endl;
}//end Board::display()


//-------------------------------------------------------------------------------------
// finddestination()
//       Find the index of the goal letter.  This is used to mark the position where the
//       goal letter must be redisplayed in the case (probably rare) where a non-goal
//       robot passes over the goal letter, blanking it out.
//
void Board::finddestination()
{
  int i =0;
  while(i<Bsize)
  {
    if( board[ i][ Player] == goalletter) {
        // found the position where the destination letter is, so return it
        destination = i;
        return;
    }
    i++;
  }

    // Should never have gotten here, so display error message
    cout << "*** Error, destination letter position not found.  Exiting program...";
    exit( -1);   // exit program
}//end Board::finddestination()


//-------------------------------------------------------------------------------------
void displayIdentifyingInformationAndInstructions()
{
    // Display identifying information
    cout << "Author: Dale Reed                    " << endl
         << "Program 4: RicoRobots in C++         " << endl
         << "TA: Billie Joe Armstrong, T 6:00 AM  " << endl
         << "March 22, 2018                       " << endl;

    // Display Instructions
    cout << "Welcome to Ricochet Robots                                     " << endl
         << "(\'Ricochet Robot\' is a registered trademark of Hans im Glück " << endl
         << "Munich, Germany, 1999. The game was created by Alex Randolph.) " << endl
         << endl
         << "The object of the game is to get the designated numbered robot " << endl
         << "to the indicated letter position.                              " << endl
         << "The numbered squares are all robots.  They unfortunately have  " << endl
         << "no brakes, and so will continue in whatever direction they are " << endl
         << "moving until they encountar an obstacle.                       " << endl
         << "For each move enter the robot number and the desired direction." << endl
         << "For instance entering                                          " << endl
         << "   1 U " << endl
         << "would move the #1 robot up as far as it can go.                " << endl
         << "The first letter of input is the robot number (1 - 4),         " << endl
         << "and the second letter is the direction:                        " << endl
         << "  (L=left, U=up, R=right, D=down)                              " << endl
         << "Enter x to exit.  Have fun!                                    " << endl
         <<  endl;
}//end displayIdentifyingInformationAndInstructions()


//-------------------------------------------------------------------------------------
// chooseRandomRobotAndDestination() - choose a robot at random, and a destination at random
//
void chooseRandomRobotAndDestination( Board &board)
{
    srand( (int)time(0));        // Seed the random number generator with time(), to give varying results.

    int randomNumber = rand()%4;    // get random number from 0 to 3
    board.setkeyPlayer( randomNumber + 1);   // set random robot to be some value between 1 - 4

    // get random number from 0 to numPlayers
    randomNumber = rand() % board.getnumPlayers();
    // add this number to 'A' to set the destination character
    board.setgoalletter( 'A' + randomNumber);
}// end chooseRandomRobotAndDestination()


//-------------------------------------------------------------------------------------
// canMove( )
//      See if the robot can move in the desired direction.
//
bool canMove(
        Board board,           // the board
        char robot,               // the robot to be moved
        int directionOffset,      // Offset value to use in moving robot
        char moveDirection)       // Move direction 'L','U','R' or 'D'for left, up, right, down
{
    // find neighbor location
    int theNeighborIndex = board.getRobotAt( robot-'0') + directionOffset;

    // verify that we're not out-of-bounds before we use robot position to check board array
    if( (theNeighborIndex < 0) || (theNeighborIndex >= Bsize)) {
        return false;     // attempting to move out of bounds, which is invalid
    }

    // See if we can move in the desired direction of travel.  For each direction we must check for
    //      1. a wall in the Player we are moving from
    //      2. a wall in the Player we are moving to
    // If any wall is found, return false.
    int theRobotIndex = board.getRobotAt( robot-'0');
    switch( moveDirection) {
        case 'L':  if( (board.getBorderAt( theRobotIndex, LEFT) != ' ') ||
                       (board.getBorderAt( theNeighborIndex, RIGHT) != ' ')
                     )
                    return false;   // we can't make the move
                    break;
        case 'U':  if( (board.getBorderAt( theRobotIndex, ABOVE) != ' ') ||
                       (board.getBorderAt( theNeighborIndex, BELOW) != ' ')
                     )
                    return false;   // we can't make the move
                    break;
        case 'R':  if( (board.getBorderAt( theRobotIndex, RIGHT) != ' ') ||
                       (board.getBorderAt( theNeighborIndex, LEFT) != ' ')
                     )
                    return false;   // we can't make the move
                    break;
        case 'D':  if( (board.getBorderAt( theRobotIndex, BELOW) != ' ') ||
                       (board.getBorderAt( theNeighborIndex, ABOVE) != ' ')
                     )
                    return false;   // we can't make the move
                    break;
        default: cout << "*** Error, invalid check for neighbor in canMove(). Exiting...\n";
                    exit( -1);      // exit the program
    }

    // Verify that the neighbor in the direction of travel is not also the location of
    // one of the other robots.
    char neighborPlayer = board.getPlayerAt( theNeighborIndex);      // Make copy of neighbor board Player
    // ensure destination doesn't contain a robot character, which is '1'..'4'
    // Convert Nrobots to a char by adding it to char '0'
    if( (neighborPlayer >= '1') && (neighborPlayer <= Nrobots+'0')) {
        return false;  // destination has another robot, so can't move there.
    }

    return true;       // passed all the tests, so move is valid
}//end method canMove()


//-------------------------------------------------------------------------------------
// blankOutSourcePosition( )
//     Put the default character in the square we're moving from.
//     One other check must be made.  If a robot (which shouldn't be the goal robot)
//     is moving OFF of the goal square, we must re-display the goal square letter.
void blankOutSourcePosition(
            Board &board,    // The board
            int robotIndex)     // Board position where robot is
{
    int destination = board.getdestination();                // Board index of winning move position
    char goalletter =  board.getgoalletter();    // Letter for winning move position

    if( robotIndex != destination) {
        board.setPlayerAt( robotIndex, '.');
    }
    else {
        board.setPlayerAt( robotIndex, goalletter);
    }
}


//-------------------------------------------------------------------------------------
// Blank out all letters except the destination letter
void blankOutAllLettersExceptgoalletter( Board &board)
{
  int i = 0;
  while( i<Bsize)
  {
    if( isalpha( board.getPlayerAt( i)) &&
        (board.getPlayerAt( i) != board.getgoalletter() )
      ) {
        board.setPlayerAt( i, '.');      // set Player at position i to the default character
    }
    i++;
  }

}


//-------------------------------------------------------------------------------------
// Given the user input of 'r' for random robot and goal, 'd' for default or 's' to select,
// set the robot to be used and the destination letter.
void setRobotAndGoal( Board &board)
{
    // Prompt for robot and goal letter configuration to be used
    char userResponse;
    cout << "Enter 'r' for random robot and goal, 'd' for default or 's' to select: ";
    cin >> userResponse;
    userResponse = toupper( userResponse);

    if( userResponse == 'R') {
        // choose a random robot and random destination
        chooseRandomRobotAndDestination( board);
    }
    else if( userResponse == 'D') {
        // Use default values for the keyPlayer and destination. This makes the program consistent
        // for the sake of debugging.
        board.setkeyPlayer( 2);
        board.setgoalletter( 'M');
    }
    else {
        board.display();
        cout << "Enter the goal robot number and the destination letter: ";
        int thekeyPlayer;
        char thegoalletter;
        cin >> thekeyPlayer >> thegoalletter;
        board.setkeyPlayer( thekeyPlayer);
        board.setgoalletter( toupper( thegoalletter));
    }

    // Find which square has the goal letter in it. Store this to use in redisplaying the goal letter
    // if a non-goal robot passes over it.
    board.finddestination();

    // Blank out all the letters except the destination letter, to make playing the game more clear
    blankOutAllLettersExceptgoalletter( board);
}//end setRobotAndGoal()


//-------------------------------------------------------------------------------------
// Move the selected robot in the direction indicated, moving as far as it can go until
// it hits some obstacle of a wall or another robot.
//
void moveRobotInIndicatedDirection(
        Board &board,        // the board
        char robot,             // the robot, as a character '1'..'4'
        int directionOffset,    // Number indicating offset to add to index to make move
        char moveDirection)     // Letter for move direction 'L','U','R', or 'D'
{
    while( canMove( board, robot, directionOffset, moveDirection)) {
        // Find position of robot
        int robotIndex = board.getRobotAt( robot-'0');
        // blank out where robot is moving from
        blankOutSourcePosition( board, robotIndex);
        // clear screen
        system("cls");  // "clear" for unix, "cls" for windows.
                        // This only works when running it from the command line.

        // store robot in new location
        board.setPlayerAt( robotIndex + directionOffset, robot);
        // update robot index position.  Must subtract '0' from robot since it's a char
        board.setRobotAt( robot-'0', robotIndex + directionOffset);

        // display board
        cout << "Move robot " << board.getkeyPlayer() << " to square " << board.getgoalletter() << endl;
        board.display();
    }//end while( canMove...

}//end moveRobotInIndicatedDirection()


//-------------------------------------------------------------------------------------
// main() - main part of program, that drives everything else
//
int main()
{
    displayIdentifyingInformationAndInstructions();

    // Create and initialize the board
    Board board;
    board.readFromFileAndModifyBoard(); // read from the datafile, updating board

    // Set the robot and goal to be used, depending on the user's choice
    setRobotAndGoal( board);

    cout << "Move robot " << board.getkeyPlayer() << " to square " << board.getgoalletter() << endl;
    board.display();

    int moveNumber = 1;          // track how many moves have been made
    char robot = ' ';            // user entry for robot to move
    char moveDirection = ' ';    // direction in which to move (L, U, R, or D)
    int directionOffset = 0;     // value to add to current robot position to reflect move direction

    // infinite loop to play the game
    while( true) {
        cout << moveNumber << ". Please enter the robot to move and the direction (e.g. 2 r): ";
        cin >> robot;
        if( toupper( robot) == 'X') {
            break;       // exit program
        }
        cin >> moveDirection;
        moveDirection = toupper( moveDirection);   // fold into upper-case
        // ensure robot values were in range
        if( (robot < '1') || (robot > Nrobots+'0')) {
            cout << "Invalid robot value, please retry." << endl;
            continue;  // continue up to the user input loop again
        }

        // Find the directionOffset for robot change in position
        switch( moveDirection) {
            case 'L': directionOffset = -1; break;
            case 'U': directionOffset = -Bedge; break;
            case 'R': directionOffset = 1; break;
            case 'D': directionOffset = Bedge; break;
            default: cout << "*** Error, invalid direction.  Retry Input. \n" << endl;
                continue;  // continue up to the user input loop again
        }

        // Make the move for this particular robot and direction
        moveRobotInIndicatedDirection( board, robot, directionOffset, moveDirection);

        // Update number of moves
        moveNumber++;

        // See if we've arrived at destination.  We've arrived if the robot just moved
        // was the goal robot, and it's location is the goal position
        if( ((robot-'0') == board.getkeyPlayer() ) &&
            (board.getRobotAt( robot-'0') == board.getdestination() )
          ) {
            cout << "Great Job!  You did it in only " << moveNumber << " moves." << endl;
            break;         // break from endless loop making moves
        }

    }//end while( true...

    cout << "Exiting program..." << endl;
}//end main()
