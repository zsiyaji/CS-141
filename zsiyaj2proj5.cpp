/*-------------------------------------------------------------------------------------
zsiyaj2prog5.cpp

   Program #5: Ricochet Robots: Allow solving the sliding robots puzzle
   Class: CS 141
   Author: Zakariah Siyaji
   Lab: Tues 2pm
   System:  C++ Mac Xcode

   Grading Rubric:

   55 Execution points
        2 Displays header info and instructions on screen when run
        3 Displays the board (Since I'm giving you all the code for this...)
        5 Allows selecting default values (robot 2 to square M), random values, or user-selected values.
       15 Allows making moves, displaying move numbers.  Input can be upper or lower case, and can have spaces or not.
       20 Robots stop at walls and don't run over each other
        5 Game stops and message is given when goal robot makes it to the goal square.
        5 If some robot besides robot 2 goes to the destination square (square M in this case), the destination square should change to show the robot there. When this robot moves away, the square should go back to displaying the letter that was there previously (M in our case.)

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
         5 Meaningful identifier names
         5 Comments: Has header and this rubric.  Has comments on each block of code
        20 Appropriate data and control structures. Is implemented using classes.
        10 Code Layout: Appropriate indentation and blank lines
-------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstring>      // for getline
#include <cstdlib>      // for the system command
#include <cctype>       // For the letter checking functions, e.g. toupper( )
#include <fstream>      // For file input and output
#include <time.h>
using namespace std;

// Global data structure for board
const int BOARD_EDGE = 16;
const int BOARD_SIZE = BOARD_EDGE * BOARD_EDGE;
const int NUMBER_OF_ROBOTS = 4;

// declare constants to later use instead of numbers to select values from theBoard
const int NUMBER_OF_ELEMENTS = 5;   // Number of elements for each piece, enumerated below
const int PIECE = 0;    // to reference the character, such as in: theBoard[ i][ PIECE]
const int LEFT = 1;     // to reference the left wall character, such as in: theBoard[ i][ LEFT]
const int ABOVE = 2;    // to reference the above wall character, such as in: theBoard[ i][ ABOVE]
const int RIGHT = 3;    // to reference the right wall character, such as in: theBoard[ i][ RIGHT]
const int BELOW = 4;    // to reference the below wall character, such as in: theBoard[ i][ BELOW]


class board{
    public:
        board(){
            for( int i=0; i<BOARD_SIZE; i++) {
                theBoard[ i][ PIECE]= '.';    // Set each playing piece default
                // set the default wall values to be blank
                theBoard[ i][ LEFT]= ' ';
                theBoard[ i][ ABOVE]= ' ';
                theBoard[ i][ RIGHT]= ' ';
                theBoard[ i][ BELOW]=  ' ';

                // reset the edge pieces
                // reset the left wall if piece is on left edge
                if( (i % BOARD_EDGE) == 0) {
                    theBoard[ i][ LEFT]= '|';
                }
                // reset the above wall if piece is on top edge
                if( i < BOARD_EDGE) {
                    theBoard[ i][ ABOVE]= '-';
                }
                // reset the right wall if piece is on right edge
                if( ((i+1) % BOARD_EDGE) == 0) {
                    theBoard[ i][ RIGHT]= '|';
                }
                // reset the below wall if piece is on bottom edge
                if( i >= (BOARD_SIZE - BOARD_EDGE) ) {
                    theBoard[ i][ BELOW]= '-';
                }
            }//end for( int i...
            for(int i=0; i <5; i++)
                theRobots[i] = 0;
        }
        ~board(){};
        int getRobot(int goalRobot){
            return theRobots[goalRobot];
        }
        void updateRobot(int goalRobot,int value){
            theRobots[goalRobot] = value;
        }
        void updateBoard(int index, int value,char ch){
            theBoard[index][value] = ch;
        }
        char getLeft(int index){
            return theBoard[index][LEFT];
        }
        char getRight(int index){
            return theBoard[index][RIGHT];
        }
        char getAbove(int index){
            return theBoard[index][ABOVE];
        }
        char getBelow(int index){
            return theBoard[index][BELOW];
        }
        char getPiece(int index){
            return theBoard[index][PIECE];
        }
    private:
        char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS];
        int theRobots[ NUMBER_OF_ROBOTS + 1];
};

//-------------------------------------------------------------------------------------
void displayIdentifyingInformationAndInstructions()
{
    // Display identifying information
    cout << "Author: Zakariah Siyaji" << endl
        << "Program 5: RicoRobots in C++" << endl
        << "LAB: 2:00 PM" << endl
        << "April 10th, 2018" << endl;

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


// readFromFileAndModifyBoard() - Read from data file, updating board accordingly
void readFromFileAndModifyBoard(board &obj, int &numberOfDestinationPieces) {
    int numberOfSpecialSquares;  // Read from file, denotes number of pieces with some kind of wall
    string inputLine;            // Input line from file
    int pieceNumber;             // pieceNumber for each square defined in data file
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

    inStream >> numberOfDestinationPieces;      // read how many destination pieces there are
    inStream >> numberOfSpecialSquares;         // number of square with walls around them somewhere
    inStream.get( c);                           // Get rid of return character at end of current line
    // to get ready for reading a line at a time below

    // process the special squares, updating the board
    for( int i=0; i<numberOfSpecialSquares; i++) {
        getline( inStream, inputLine);
        char *pInputLine = &inputLine[0];
        // Extract the piece number from the input line array
        sscanf( pInputLine, "%d", &pieceNumber);
        // Advance the inputLine pointer to the space after the number
        pInputLine = strchr( pInputLine, ' ');

        // Read the information on whether or not there is each of the potential 4 walls.
        // The four values read correspond in order to the pieces on all four sides,
        // which are defined as global constants for the values LEFT=1, ABOVE=2, RIGHT=3, BELOW=4
        for( int position=1; position<=4; position++) {
            pInputLine++;   // advance to next character to be read
            sscanf(pInputLine, " %c", &c);         // Read the next potential wall character
            // Convert it to a blank if it was '0'.  '0' was left in input file to make it easier to read.
            if( c=='0') {
                c = ' ';
            }
            obj.updateBoard(pieceNumber,position,c);
        }
        pInputLine++;

        // See if there is a piece letter still to be read on this input line.
        // Do this by finding the end of the line, and seeing the length of the string
        // after that.
        // An inputline sample for piece 18 would be:
        // 18 00|- A
        char letter;
        if( strlen( pInputLine) > 0) {
            sscanf( pInputLine, " %c", &letter);
            obj.updateBoard(pieceNumber,PIECE,letter);
        }

    }//end for( int i...

    // At the end of the data file read the information on the location of the robots, updating the board.
    char junk[80];           // used to read and discard input file information
    // Loop starts counting from 1 (rather than 0), since we ignore the 0th position
    // of the robots array, so that robot numbers correspond to what is shown
    // on the board.
    int temp;
    for( int i=1; i<=NUMBER_OF_ROBOTS; i++) {
        inStream >> temp;
        obj.updateRobot(i,temp);
        inStream.getline( junk, '\n');    // discard rest of line, which is color information, if using graphics
        // set robot on board, converting the integer value to a character
        obj.updateBoard(temp,PIECE,(char)('0'+i));
    }

    inStream.close();         // close the input file stream
}//end readFromFileAndModifyBoard()

void displayTheBoard(board &obj)
{
    // display the top edge
    cout << "  ---------------------------------------------------------------- " << endl;

    // display the "body" of the board
    for( int i=0; i<BOARD_SIZE; i++) {
        // Figure out what character should be displayed to the left.  It will
        // be a wall if the current spot has a left wall, or if the spot to the
        // left has a right wall.

        char leftCharacter = obj.getLeft(i);   // set left display char
        // See if the piece to the left has a right wall.  Don't do this for the
        // first piece on the board, since it has no left neighbor.
        if ( (i>0) && (obj.getRight(i-1) != ' ')) {
            leftCharacter = obj.getRight(i-1);
        }
        cout << " " << leftCharacter << " " << obj.getPiece(i);
        // see if we're at the end of a row
        if( ((i+1) % BOARD_EDGE) == 0) {
            // we are at the end of a row, so display right wall and go to next line
            cout << "  " << obj.getRight(i) << endl;
            // Now display any walls immediately below the line of pieces just displayed
            // Backup our index counter j to the beginning of this line again, to find any
            // walls displayed below this line.  Don't do it for the bottom row though.
            if( i < BOARD_SIZE - BOARD_EDGE) {

                cout << " |";       // display the left boundary
                for( int j=i-BOARD_EDGE+1; j<(i+1); j++) {
                    // Set the character to be displayed.  This is a wall if the
                    // current spot has a wall below, or if the spot below has a wall
                    // above.
                    char belowCharacter = obj.getBelow(j);
                    // Only check the square below if we're NOT on the bottom row
                    if ( (j<(BOARD_SIZE - BOARD_EDGE)) &&      // verify not on bottom row
                            (obj.getAbove(j+16) != ' ')) {    // piece below has wall above
                        belowCharacter = obj.getAbove(j+16);
                    }
                    for( int i=0; i<3; i++) {
                        cout << belowCharacter;        // display the character
                    }
                    // display extra spaces, if we're not at the end of a row
                    if( ((j+1) % BOARD_EDGE) != 0) {
                        cout << " ";
                    }
                }//end for( int j...
                cout << " |" << endl;       // display the right boundary
            }//end if( i< BOARD_SIZE...

        }//end if( ((i+1...

    }//end for( int i=0;...

    // display the bottom edge
    cout << "  ---------------------------------------------------------------- " << endl;
    cout << endl;
}//end displayTheBoard()
void playGame(board &obj,int goalRobot, char destinationLetter){
    int moveRobot;
    int count= 0;
    char direction;
    int robotIndex;
    bool gameOver = false;
    // To make moves you selectively change values on the board.  For instance to move robot 2 up 1 square:
    int goalIndex = obj.getRight(goalRobot);
    while (gameOver == false){
        cout<<"Please enter the robot to move and the direction (e.g. 2 r):";
        cin>>moveRobot;
        cin>>direction;
        cout<<endl;
        count++;
        robotIndex = obj.getRobot(moveRobot);
        // blank out where we're coming FROM
        // Get the new stored value reflecting the new position
        // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
        // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
        // character '2'.
        if(direction == 'u'){
            while(obj.getAbove(robotIndex) ==' ' && obj.getBelow(robotIndex -16) ==' ' && (obj.getPiece(robotIndex-16) == '.' || (moveRobot == goalRobot && obj.getPiece(robotIndex-16) == destinationLetter))){
                if (moveRobot == goalRobot && obj.getPiece(robotIndex-16) == destinationLetter)
                   gameOver = true;
                obj.updateBoard(robotIndex,PIECE, '.');
                obj.updateRobot(moveRobot,robotIndex - 16);     // Reset robot position index to the square above
                robotIndex = obj.getRobot(moveRobot);
                obj.updateBoard(robotIndex,PIECE, '0'+moveRobot);
            }
            cout << "After moving robot " << moveRobot << " upwards one square we now have: " << endl;
        }
        else if(direction == 'd'){
            while(obj.getBelow(robotIndex)==' ' && obj.getAbove(robotIndex + 16) ==' ' && (obj.getPiece(robotIndex+16) == '.' || (moveRobot == goalRobot && obj.getPiece(robotIndex+16) == destinationLetter))){
                if (moveRobot == goalRobot &&  obj.getPiece(robotIndex+16) == destinationLetter)
                   gameOver = true;
                obj.updateBoard(robotIndex,PIECE, '.');
                obj.updateRobot(moveRobot,robotIndex + 16);     // Reset robot position index to the square above
                robotIndex = obj.getRobot(moveRobot);
                obj.updateBoard(robotIndex,PIECE, '0'+moveRobot);
            }
            cout << "After moving robot " << moveRobot << " downwards one square we now have: " << endl;
        }
        else if(direction == 'l'){
            while(obj.getLeft(robotIndex) ==' ' && obj.getRight(robotIndex -1) ==' ' && (obj.getPiece(robotIndex-1) == '.' || (moveRobot == goalRobot && obj.getPiece(robotIndex -1) == destinationLetter ))){
                if (moveRobot == goalRobot &&  obj.getPiece(robotIndex-1) == destinationLetter)
                   gameOver = true;
                obj.updateBoard(robotIndex,PIECE, '.');
                obj.updateRobot(moveRobot,robotIndex -1);
                robotIndex = obj.getRobot(moveRobot);
                obj.updateBoard(robotIndex,PIECE, '0'+moveRobot);
            }
            cout << "After moving robot " << moveRobot << " left one square we now have: " << endl;
        }
        else if(direction == 'r'){
            while(obj.getRight(robotIndex) == ' ' && obj.getLeft(robotIndex + 1) ==' ' &&  (obj.getPiece(robotIndex+1) == '.' || (moveRobot == goalRobot &&  obj.getPiece(robotIndex+1) == destinationLetter))){
                if (moveRobot == goalRobot &&  obj.getPiece(robotIndex+1) == destinationLetter)
                   gameOver = true;
                obj.updateBoard(robotIndex,PIECE, '.');
                obj.updateRobot(moveRobot,robotIndex +1);
                robotIndex = obj.getRobot(moveRobot);
                obj.updateBoard(robotIndex,PIECE, '0'+moveRobot);
            }
            cout << "After moving robot " << moveRobot << " right one square we now have: " << endl;
        }
        system("clear");
        cout << "Move robot " << goalRobot << "to square " << destinationLetter  << endl;
        displayTheBoard(obj);
    }
    cout << "The goalRobot to move to destination id it is only " << count << "moves." << endl;
}

void clearTheBoard(board &obj,char destinationLetter){
    for (int i=0; i < BOARD_SIZE; i++){
        if (obj.getPiece(i) != destinationLetter && obj.getPiece(i) != '1' &&  obj.getPiece(i) != '2' &&  obj.getPiece(i)!= '3' && obj.getPiece(i)!= '4' )
            obj.updateBoard(i,PIECE,'.');
    }
}

//-------------------------------------------------------------------------------------
// main() - main part of program, that drives everything else
int main()
{
    int goalRobot;                  // the robot that needs to reach the goal
    char destinationLetter;         // the goal letter
    int numberOfDestinationPieces;  // Number of destination pieces.  Value
    board b = board();
    displayIdentifyingInformationAndInstructions();
    readFromFileAndModifyBoard(b, numberOfDestinationPieces); // read from the datafile, updating board

    char choice;
    string inputString;
    displayTheBoard(b);
    do{
        cout << "Enter 'r' for random robot and goal, 'd' for default or 's' to select: " ;
        cin >> choice;
        if ( choice != 'r' && choice != 'd' && choice != 's' && choice != 'x')
            cout << "Invalid choice, please reenter the choice " << endl;
    }while( choice != 'r' && choice != 'd' && choice != 's' && choice != 'x');

    if ( choice == 'd'){
        // Hard-code the robot to be used and the destination letter and position.
        // Your version will also need to allow selecting the goal robot and destination letter, but then needs
        // to find the goal position.  Your version must also allow for these to be chosen at random.
        goalRobot = 2;
        destinationLetter = 'M';
        clearTheBoard(b,destinationLetter);
        cout << "Move robot " << goalRobot << " to square " << destinationLetter  << endl;
        displayTheBoard(b);
        playGame(b,goalRobot,destinationLetter);
    }
    else if ( choice == 'r'){
        srand(time(NULL));
        goalRobot = 1 + rand() % 3;
        destinationLetter = 'A' + rand() % numberOfDestinationPieces;
        clearTheBoard(b,destinationLetter);
        cout << "Move robot " << goalRobot << " to square " << destinationLetter  << endl;
        displayTheBoard(b);
        playGame(b,goalRobot,destinationLetter);
    }
    else if ( choice == 's'){
        displayTheBoard(b);
        cout << "Enter the goal robot number and the destination letter: ";
        cin.ignore(256,'\n');
        getline(cin,inputString);
        for(size_t i = 0; i < inputString.size(); i++){
            if (inputString[i] == ' '){
                goalRobot = stoi(inputString.substr(0,i));
                destinationLetter = inputString[i+1];
                break;
            }
        }
        clearTheBoard(b,destinationLetter);
        cout << "Move robot " << goalRobot << " to square " << destinationLetter  << endl;
        displayTheBoard(b);
        playGame(b,goalRobot,destinationLetter);
    }
    else if ( choice == 'x'){
        cout << "please enter to exit program ..." << endl ;
        cin.ignore(256,'\n');
        getline(cin,inputString);
        exit(-1);
    }
    cout << "please enter to exit program ..." << endl ;
    cin.ignore(256,'\n');
    getline(cin,inputString);
    exit(-1);
}//end main()
