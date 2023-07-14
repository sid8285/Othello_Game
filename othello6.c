// Othello project (part 5) - Siddhant Srivastava 10/2/22
// these include the header libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "othello.h"


//These are the macros that will be used as global constants for the game. They replace values with text for ease of programming. 
#define TRUE 1
#define FALSE 0
#define NAME 20
#define ROW 8
#define COL 8
#define SPACE ' '
#define PLAYER_X 1
#define PLAYER_O 2
#define ZERO 0
#define ONE 1
#define TWO 2
#define FOUR 4
#define INVALID -1
#define THREE 3
#define MIN 0
#define MAX 7
#define EIGHT 8


// //defining a structure to replace certain existing functions
// struct Player{
//     int PlayerNum; 
//     char playerName[NAME];
//     int discCount; 
//     char playChar;   
// };


//creating prototype or signature for the welcome screen of the game
 void welcomeScreen();

//creating prototype or signature for the clear-screen function after the welcome screen
void clearScreen();

//creating protoype or signature for the othello game board
void displayExplicitBoard();

//creating prototype or signature for the game function
void playGame();

//creating prototype or signature for the initialize board sequence
void initializeBoard(char board[ROW][COL]);

//creating prototype or signature for displaying the board
void displayBoard(char board[ROW][COL]);

//creating the prototype or signature for the make move function
void makeMove(struct Player *player, char board[ROW][COL]);

//creating the prototype or signature for the isValid function
int isValid(char move[THREE],char board[ROW][COL], struct Player *player);

//creating the prototype or signature for the getMoveRow function
int getMoveRow(char move[THREE]);

//creating the prototype or signature for the getMoveCol function
int getMoveCol(char move[THREE]);

//creating the prototype or signature for the isOpen function
int isOpen(char move[THREE], char board[ROW][COL]);

//creating the prototype or signature for the displayStats function
void displayStats();

//creating the prototype or signature for the isOutFlank function
int isOutFlank(char move[THREE], char board[ROW][COL], char playChar);

//creating the prototype or signature for the checkHorizontal function 
int checkHorizontal(int row, int col, char board[ROW][COL], char playerChar);

//creating the prototype or signature for the checkVertical function 
int checkVertical(int row, int col, char board[ROW][COL], char playerChar);

//creating the prototype or signature for the checkDiagonal function 
int checkDiagonal(int row, int col, char board[ROW][COL], char playerChar);

//creating the prototype or signature for the updateBoard function 
void updateBoard(char move[TWO], char board[ROW][COL], struct Player *player);

//creating the prototype or signature for the updateHorizontal function
void updateHorizontal(int row, int col, char board[ROW][COL], struct Player *player);

//creating the prototype or signature for the updateVeritcal function
void updateVertical(int row, int col, char board[ROW][COL], struct Player *player);

//creating the prototype or signature for the updateDiagonal function 
void updateDiagonal(int row, int col, char board[ROW][COL], struct Player *player);

//creating the prototype or signature for the updateDiscCount function
void updateDiscCount(char board[ROW][COL], struct Player *player);

int main(void) {
  
  //calling welcomeScreen function to display the game logo as well as the rules.
  welcomeScreen();

  //calling clearScreen function to clear the screen when the user hits enter/return.
  clearScreen();

  // //calling the displayExplicitBoard function to display the othello game board once the screen has been cleared. 
  // this has been commented out for this assigment
  // displayExplicitBoard();

  //calling the playGame function which will initiate the start of the Othello game.
  playGame();
  
  return 0;
}

//this function displays the othello welcome screen as well as the game rules
void welcomeScreen() {
  //this is the game logo
  printf("\n");
  printf("\n");
  printf("\t\t  OOOO   TTTTTT  HH  HH  EEEEEE  LL      LL       OOOO\n");
  printf("\t\t OO  OO    TT    HH  HH  EE      LL      LL      OO  OO\n");
  printf("\t\t OO  OO    TT    HHHHHH  EEEE    LL      LL      OO  OO\n");
  printf("\t\t OO  OO    TT    HH  HH  EE      LL      LL      OO  OO\n");
  printf("\t\t  OOOO     TT    HH  HH  EEEEEE  LLLLLL  LLLLLL   OOOO\n");
  printf("\n");
  printf("\n");

  //these are the game rules.
  printf("Othello Game Rules:\n");
  printf("\t 1. A square 8 x 8 board \n");
  printf("\t 2. 64 discs colored black (X) on one side and white (O) on the other side.\n");
  printf("\t 3. The board will start with 2 black discs (X) and 2 white discs (O) at the center of the board.\n");
  printf("\t 4.They are arranged with the black pieces in the Northeast and Southwest direction, and the white pieces in the Northwest and Southeast position. \n");
  printf("\t 5. The goal is to have the most pieces of a single color by the end of the game. \n");
  printf("\t 6. Each player gets 32 discs and black (X) always starts the game. \n");
  printf("\t 7. The game alternates between white (O) and black (X) until one player cannot make a valid move to outflank the other, or both players have no valid moves left.  \n");
  printf("\t 8. When a player has no valid moves, they pass their turn and the opponent continues. \n");
  printf("\t 9. A player cannnot voluntarily forfeit their turn.\n");
  printf("\t 10. When both players cannot make a valid move, the game ends. \n");
  printf("\n");
  printf("\n");
  
  //user Input for Windows OS
  //printf("\t\t\t Hit <Enter> to continue!");

  //user Input for Mac/Unix OS
  printf("\t\t\t Hit <Return> to continue!");
};

//this function clears the screen when instructed by the user.
void clearScreen(){

  //defining a variable called enter with the character data type
  char enter;

  //this stores the user action when enter is pressed.
  scanf("%c", &enter);

  //this command clears the screen, specifically for Windows OS. It is commented out because I use Mac/UNIX  OS
  //system("cls");

  //this command clears the screen, but catered towards MacOS.
  system("clear");

};

//this function displays the othello game board
void displayExplicitBoard(){

  //this is the othello game board in its inital position
  printf("|-----------------------------------------------------|\n");
  printf("|     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  1  |     |     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  2  |     |     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  3  |     |     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  4  |     |     |     |  O  |  X  |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  5  |     |     |     |  X  |  O  |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  6  |     |     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  7  |     |     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");
  printf("|  8  |     |     |     |     |     |     |     |     |\n");
  printf("|-----------------------------------------------------|\n");

};

//this fuction begins the game process of Othello.
void playGame(){

  // these variables are initialized with the macro value
  struct Player playerX;
  struct Player playerO;
  int currentPlayer = PLAYER_X;
  int loop = ZERO;
  char board[ROW][COL];
  int endGame = FALSE;

  //these statemets prompt the players to enter their names
  printf("Player X, please enter your name:\n");
  scanf("%s", playerX.playerName);
  printf("Player O, please enter your name:\n");
  scanf("%s", playerO.playerName);

  //setting the struct value for each player equal to the player macros
  playerX.PlayerNum = PLAYER_X;
  playerO.PlayerNum = PLAYER_O;

  //setting the discCount value for each player equal to 2
  playerX.discCount = 2;
  playerO.discCount = 2;

  //setting the PlayChar value to each corresponding player character
  playerX.playChar = 'X';
  playerO.playChar = 'O';


  //this prompts both players to begin the game.
  printf("%s and %s, lets play Othello!\n", playerX.playerName, playerO.playerName);

  //calling function to initialize board
  initializeBoard(board);

  //this loops the game through the players turns
  while(endGame == FALSE){

    //calling function to determine if the game is over
    endGame = isEndGame(board);

    //using function to exit the game once the game has been determined to be over.
    if(endGame == TRUE){

      //calling function gameOver to end the game
      gameOver(board, playerX, playerO);

      break;

    }

    //calling function to display board
    displayBoard(board);

    //determines whose turn it is
    //prompts playerX to play if it is their turn
    if (currentPlayer == PLAYER_X){

      //creating another if block to see if the move made was valid
      if(validMoveExists(board, playerX.playChar) == TRUE){
        //calling makeMove function to determine who is the player
        makeMove(&playerX, board);

        //removed as per instruction from assignment 3
        // printf("%s, it is your turn.\n", playerX);
        // printf("Please press enter to continue...\n");
        currentPlayer = PLAYER_O;
      }
      else{
        currentPlayer = PLAYER_O;
      }
    }
    
    //prompts playerO to play if it is their turn
    else{

      //creating another if block to see if the move made was valid
      if(validMoveExists(board, playerO.playChar) == TRUE){
      //calling makeMove function to determine who is the player
        makeMove(&playerO, board);

        //removed as per instruction from assignment 3
        // printf("%s, it is your turn.\n", playerO);
        // printf("Please press enter to continue...\n");
        currentPlayer = PLAYER_X;
      }
      else{
        currentPlayer = PLAYER_X;
      }
    }

    //this pauses the game between each turn
    //this is an alterative to the pause statement below.
    //function commented out as per innstruction from assignment 3
    // system("read");
    //this (pause) is for Windows only, please uncomment the line below and comment the system("read"); line if using Windows OS.
    //system("pause");

    //calling function to update the amount of discs the player has on the board 
    updateDiscCount(board, &playerX);
    updateDiscCount(board, &playerO);

    //calling function to display the stats for each player
    displayStats(playerX);
    displayStats(playerO);

    //this icrements the loop by one
    //loop = loop + 1;
  }

    //calling these functions again after the turns for each player are over
    // displayBoard(board);
    // updateDiscCount(board, &playerX);
    // updateDiscCount(board, &playerO);
    // displayStats(playerX);
    // displayStats(playerO);

}

//initializes the board sequence
void initializeBoard(char board[ROW][COL]){

//creating a for loop to print the Othello rows
for(int i = 0; i < ROW; i++){

  // //initializing column for every row 
  // j = 0;

  //creating a nested for loop to print the columns for each row
  for(int j = 0; j < COL; j++){

    //creating if statement to generatre Othello starting position
    if(i == 3 && j == 3){
      board[i][j] = 'O';
    }
    else if(i == 3 && j == 4){
      board[i][j] = 'X';
    }
    else if(i == 4 && j == 3){
      board[i][j] = 'X';
    }
    else if(i == 4 && j == 4){
      board[i][j] = 'O';
    }
    else{
      board[i][j] = SPACE;
    }

  }

}


}

//displays the board sequence
void displayBoard(char board[ROW][COL]){

//this statement hard-codes the top half of the board
printf("|-----------------------------------------------------|\n");
printf("|     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |\n");

//creating a for loop to print the Othello rows
for(int i = 0; i < ROW; i++){

  //prints the 
  printf("|-----------------------------------------------------|\n");
  printf("|  %d  |", (i + 1));
  
  
  //creating a nested for loop to print the columns for each row
  for(int j = 0; j < COL; j++){

    //printing the Othello board after every input
    printf("  %c  |", board[i][j]);

  }
  printf("\n");
}
//this statement ends the Othello board
 printf("|-----------------------------------------------------|\n");

}

//creating function which alternates the player move
void makeMove(struct Player *player, char board[ROW][COL]){

  //these are being defined to use in the while loop
  char move[THREE];
  int valid = FALSE;
  int length = 0;
  
  //this loop determines if the input the user has give is correct
  while(valid == FALSE){
    printf("%s", player->playerName);
    printf(", enter your move location (e.g. C3)\n");
    scanf("%s", move);

    printf("%s", player->playerName);
    printf(", you entered %s\n", move);
    length = (int)strlen(move);

    //this statement tells the user whether or not their input was the correct length
    if(length == 2){
      valid = TRUE;
      valid = isValid(move, board, player);

      //this statement evaluates whether or not the statement was valid
      if(valid == TRUE){
        printf("Selected move is valid!\n\n");
      }
      else{
        printf("Invalid move, try again.\n\n");
      }

    }
    else{
      printf("Invalid move, try again.\n\n");
    }
    
  };
  
}

//creating a function that determines whether or not the players move is valid
int isValid(char move[THREE],char board[ROW][COL], struct Player *player){

  //local variable used in this function
  int valid = FALSE;

  //checking to see if the space is open
  if (isOpen(move, board) == TRUE) {
    valid = isOutFlank(move, board, player->playChar);
   }

  //updating the board if the value is valid 
  if(valid == TRUE){
    updateBoard(move, board, player);
  }

  return valid;

}

//creating a fucntion that determines whether or not a spot on the Othello board is open
int isOpen(char move[THREE], char board[ROW][COL]){

  //local variables used in this function
  int open = FALSE;
  int rowInt = getMoveRow(move);
  int colInt = getMoveCol(move);

  if(rowInt != INVALID && colInt != INVALID && board[rowInt][colInt] == SPACE){
  open = TRUE;
  }

  return open;

}

//creating a function that sees if the row is open
int getMoveRow(char move[THREE]){

  //local variable defined to help with the if statements 
  int row;

  //translating the row input into something the array can understand
  if(move[1] == '1'){
  row = 0;
  }
  else if(move[1] == '2'){
  row = 1;
  }
  else if(move[1] == '3'){
  row = 2;
  }
  else if(move[1] == '4'){
  row = 3;
  }
  else if(move[1] == '5'){
  row = 4;
  }
  else if(move[1] == '6'){
  row = 5;
  }
  else if(move[1] == '7'){
  row = 6;
  }
  else if(move[1] == '8'){
  row = 7;
  }
  else{
    row = INVALID;
  }

  return row;

}

//creating a function that sees if the column is open
int getMoveCol(char move[THREE]){

  //local variable created to help the if statements work
  int col;

  //translating the column input into something the array can understand
  if(move[0] == 'A' || move[0] == 'a'){
  col = 0;
  }
  else if(move[0] == 'B' || move[0] == 'b'){
  col = 1;
  }
  else if(move[0] == 'C' || move[0] == 'c'){
  col = 2;
  }
  else if(move[0] == 'D' || move[0] == 'd'){
  col = 3;
  }
  else if(move[0] == 'E' || move[0] == 'e'){
  col = 4;
  }
  else if(move[0] == 'F' || move[0] == 'f'){
  col = 5;
  }
  else if(move[0] == 'H' || move[0] == 'h'){
  col = 6;
  }
  else if(move[0] == 'G' || move[0] == 'g'){
  col = 7;
  }
  else{
    col = INVALID;
  }

  return col;

}

//creating the function that displays the player's statistics
void displayStats(struct Player player){

  //prints everything in the struct "Player"
  printf("Player name: %s\n", player.playerName);
  printf("Player Number: %d\n", player.PlayerNum);
  printf("Player Character: %c\n", player.playChar);
  printf("Player discs: %d\n\n", player.discCount);
  
}

//creating function to determine if pieces on the board are outflanked
int isOutFlank(char move[THREE], char board[ROW][COL], char playChar){

    //declaring local variables to assist the function
    int flank = FALSE;
    int rowInt = getMoveRow(move);
    int colInt = getMoveCol(move);

    //checking to see if the position chosen is valid
    if (checkHorizontal(rowInt, colInt, board, playChar) > ZERO || checkVertical(rowInt, colInt, board, playChar) > ZERO || checkDiagonal(rowInt, colInt, board, playChar) > ZERO){
        flank = TRUE;
    }
    
    return flank;
}

//creating function to see if the input is valid horizontally
int checkHorizontal(int row, int col, char board[ROW][COL], char playerChar) {

  int count = 0;
  int c = col;
  int found = FALSE;

  // check left of location
  // start at the square to the left of the row selected
  c--;

  while(c >= MIN){
    // if the square to the left is a space, stop checking
    // if the square to the left is the same character as the player, stop checking
    // if the square to the left is the opposite letter, count
    if(board[row][c] == SPACE){
      break;
    }
    else{
      if(board[row][c] != playerChar){
        count++;
      }
      else{
        found = TRUE;
        break;
      }
    }

        c--;
  }

  // check right of location
  // start at the square to the right of the row selected
  c = col;
  c++;

  while(c <= MAX){
    // if the square to the left is a space, stop checking
    // if the square to the left is the same character as the player, stop checking
    // if the square to the left is the opposite letter, count
    if(board[row][c] == SPACE){
      break;
    }
    else{
      if(board[row][c] != playerChar){
        count++;
      }
      else{
        found = TRUE;
        break;
      }
    }

    c++;
  }

  if(count > ZERO && found == TRUE){
    return count;
  }
  else{
    return ZERO;
  }
}

//creating function to see if the input is valid vertically
int checkVertical(int row, int col, char board[ROW][COL], char playerChar) {
  int count = 0;
  int r = row;
  int found = FALSE;

  // check up of location
  r--;

  while(r >= MIN){
    if(board[r][col] == SPACE){
      break;
    }
    else{
      if(board[r][col] != playerChar){
        count++;
      }
      else{
        found = TRUE;
        break;
      }
    }

    r--;
  }

  // check bottom of location
  // start at the square to the below of the row selected
  r = row;
  r++;

  while(r <= MAX){
    // if the square to the left is a space, stop checking
    // if the square to the left is the same character as the player, stop checking
    // if the square to the left is the opposite letter, count
    if(board[r][col] == SPACE){
      break;
    }
    else{
      if(board[r][col] != playerChar){
       count++;
      }
      else{
      found = TRUE;
        break;
      }
    }

    r++;
  }

  if(count > ZERO && found == TRUE){
    return count;
  }
  else{
    return ZERO; 
  }
}

//creating function to see if input is valid diagonally (not complete)
int checkDiagonal(int row, int col, char board[ROW][COL], char playerChar) {
  
  //initializing some local variables to be used in the logic
  int r;
  int c;
  int count = 0;
  int found = FALSE;

  //moving towards [0][0]
  r = row - 1;
  c = col - 1;

  while(r >= MIN && c >= MIN){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != playerChar){
        count++;
      } 
      else{
        found = TRUE;
        break;
      }
    }

    r--;
    c--;
  }

  //moving towards [7][7]
  r = row + 1;
  c = col + 1;

  while(r <= MAX && c <= MAX){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != playerChar){
        count++;
      } 
      else{
        found = TRUE;
        break;
      }
    }

    r++;
    c++;
  }

  //moving towards [7][0]
  r = row + 1;
  c = col - 1;

  while(r <= MAX && c >= MIN){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != playerChar){
        count++;
      } 
      else{
        found = TRUE;
        break;
      }
    }

    r++;
    c--;
  }

  //moving towards [0][7]
  r = row -1;
  c = col + 1;

  while(r >= MIN && c <= MAX){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != playerChar){
        count++;
      } 
      else{
        found = TRUE;
        break;
      }
    }

    r--;
    c++;
  }

   if(count > ZERO && found == TRUE){
    return count;
  }
  else{
    return ZERO; 
  }


}

//creating function to update the board when input is put
void updateBoard(char move[3], char board[8][8],struct Player *player){
  int rowInt = getMoveRow(move);
  int colInt = getMoveCol(move);
  if(checkHorizontal(rowInt, colInt, board, player->playChar)>ZERO){
    updateHorizontal(rowInt, colInt, board, player);
  }
  if(checkVertical(rowInt, colInt, board, player->playChar)>ZERO){
    updateVertical(rowInt, colInt, board, player);
  }
  if(checkDiagonal(rowInt, colInt, board, player->playChar)>ZERO){
    updateDiagonal(rowInt, colInt, board, player);
  }
}

void updateHorizontal(int row, int col, char board[ROW][COL], struct Player *player){
  
  int c = col;

  // update the actual location first
  board[row][col] = player->playChar;

  // go left
  c--;
  while(c >= MIN){
    if(board[row][c] == SPACE){
      break;
    }
    else{
      if(board[row][c] != player->playChar){
        board[row][c] = player->playChar;
      }
      else{
        break;
      }
    }

   c--;
  }

  // go right
  c = col;
  c++;
  while(c <= MAX){
    if(board[row][c] == SPACE){
      break;
    }
    else{
      if(board[row][c] != player->playChar){
        board[row][c] = player->playChar;
      }
      else{
        break;
      }
    }

    c++;
  }
}

void updateVertical(int row, int col, char board[ROW][COL], struct Player *player){
 
  // update the actual location first
  board[row][col] = player->playChar;

  int r = row;

  // check up of location
  r--;
  while(r >= MIN){
    if(board[r][col] == SPACE){
      break;
    }
    else{
      if(board[r][col] != player->playChar){
          board[r][col] = player->playChar;
        }
      else{
       break;
      }
    }

   r--;
  }

  // check right of location
  // start at the square to the right of the row selected
  r = row;
  r++;

  while(r <= MAX){
    if(board[r][col] == SPACE){
      break;
    }
    else{
      if(board[r][col] != player->playChar){
        board[r][col]= player->playChar;
      }
      else{
       break;
      }
    }

   r++;
  }
}

//creating function to update the board for diagonal imputs 
void updateDiagonal(int row, int col, char board[ROW][COL], struct Player *player) {

  // update the actual location first
  board[row][col] = player->playChar;

  int r = row + 1;
  int c = col + 1;
  while(r <= MAX && c <= MAX){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != player->playChar){
        board[r][c]= player->playChar;
      }
      else{
       break;
      }
    }

   r++;
   c++;
  }

  r = row + 1;
  c = col - 1;
  while(r <= MAX && c >= MIN){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != player->playChar){
        board[r][c]= player->playChar;
      }
      else{
       break;
      }
    }

   r++;
   c--;
  }

  r = row - 1;
  c = col - 1;
  while(r >= MIN && c >= MIN){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != player->playChar){
        board[r][c]= player->playChar;
      }
      else{
       break;
      }
    }

   r--;
   c--;
  }

  r = row - 1;
  c = col + 1;
  while(r >= MIN && c >= MIN){
    if(board[r][c] == SPACE){
      break;
    }
    else{
      if(board[r][c] != player->playChar){
        board[r][c]= player->playChar;
      }
      else{
       break;
      }
    }

   r--;
   c++;
  }

  

  

}

//creating function to update disc count
void updateDiscCount(char board[ROW][COL],struct Player *player){

  //defining local varibale
  player->discCount = 0;

  //logic used to count the player discs
  for(int i=0;i<8;++i){
    for(int j=0;j<8;++j){
      if (board[i][j] == player->playChar) {
        player->discCount++;
      }
    }
  }
}

//creating function to see if the game is over
int isEndGame(char board[ROW][COL]){

  //testing to see if the board is full and thus the game has ended
  //these lines of code have been commented out as per the instruction of Professor Markle
    // setFullBoard(board);
    // displayBoard(board);

    if(getDiscCount(board) == SQUARES){
      return TRUE;
    }

    //testing to see if there are no valid moves left
    //these lines of code have been commented out as per the instruction of Professor Markle
      // setNoMoveBoard(board);
      // displayBoard(board);

    if(validMoveExists(board, 'X') == FALSE && validMoveExists(board, 'O') == FALSE){

      return TRUE;
    }
    else{
      return FALSE;
    }
}

//creating function to fetch the Disc Count at the end of the game
int getDiscCount(char board[ROW][COL]){

  //declaring local variables to be used in the function
  int disc = ZERO;

  //logic used to determine Disc Count 
  for(int i = 0; i <= 8; i++){
    for(int j = 0; j <= 8; j++){

      if(board[i][j] != SPACE){
        disc = disc + 1;
      }
    }
  }

  return disc;
}

//creating functon to determine if a valid move exists for either playerX or player O
int validMoveExists(char board[ROW][COL], char playerChar){

  //declaring local variables to be used in the function
  int spaces = ZERO;
  int result = FALSE;

  //logic used to determine if there are any free spaces 
  for(int i = 0; i <= 8; i++){
    for(int j = 0; j <= 8; j++){

      if(board[i][j] == SPACE){
        spaces = spaces + 1;
      }

      if(spaces > ZERO){
        if(checkHorizontal(ROW, COL, board, playerChar) && checkVertical(ROW, COL, board, playerChar) && checkDiagonal(ROW, COL, board, playerChar) == ZERO){
          result = FALSE;
        }
        else{
          result = TRUE;
          break;
        }
      }

    }
    if(result == FALSE){
        break;
   }
  }

  return result;
}

//creating function to end the Othello game :)
void gameOver(char board[ROW][COL], struct Player playerX, struct Player playerO){

//creating end game banner
printf("\n\n\n");
printf("*******************************************************\n");
printf("********************** GAME OVER **********************\n");
printf("*******************************************************\n");

//displaying the board as well as the final stats 
displayBoard(board);
updateDiscCount(board, &playerX);
updateDiscCount(board, &playerO);
displayStats(playerX);
displayStats(playerO);

}

//using function provided to test end game support function
void setFullBoard(char board[ROW][COL])
{
    for(int row = ZERO; row < ROW; row++)
    {
        for(int col = ZERO; col < COL; col++)
        {
            if(row % TWO == ZERO && col % TWO == ZERO)
                board[row][col] = 'X';
            else
                board[row][col] = 'O';
        }
    }
}

//using function provided to test end game support function
void setNoMoveBoard(char board[ROW][COL])
{
    // row 0
    // {'X','X','X','X','X','O','X','O'}
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';
    board[0][3] = 'X';
    board[0][4] = 'X';
    board[0][5] = 'O';
    board[0][6] = 'X';
    board[0][7] = 'O';

    // row 1
    // {'O','X','X','O','O','O','X','O'}
    board[1][0] = 'O';
    board[1][1] = 'X';
    board[1][2] = 'X';
    board[1][3] = 'O';
    board[1][4] = 'O';
    board[1][5] = 'O';
    board[1][6] = 'X';
    board[1][7] = 'O';

    // row 2
    // {'X','X','X','X','X','X','X','O'}
    board[2][0] = 'X';
    board[2][1] = 'X';
    board[2][2] = 'X';
    board[2][3] = 'X';
    board[2][4] = 'X';
    board[2][5] = 'X';
    board[2][6] = 'X';
    board[2][7] = 'O';

    // row 3
    // {'X','X','X','X','X','X','X','O'}
    board[3][0] = 'X';
    board[3][1] = 'X';
    board[3][2] = 'X';
    board[3][3] = 'X';
    board[3][4] = 'X';
    board[3][5] = 'X';
    board[3][6] = 'X';
    board[3][7] = 'O';

    // row 4
    // {'O','X','X','O','X','X','X','O'}
    board[4][0] = 'O';
    board[4][1] = 'X';
    board[4][2] = 'X';
    board[4][3] = 'O';
    board[4][4] = 'X';
    board[4][5] = 'X';
    board[4][6] = 'X';
    board[4][7] = 'O';

    // row 5
    // {'O','O','X','O','O','X','X','O'}
    board[5][0] = 'O';
    board[5][1] = 'O';
    board[5][2] = 'X';
    board[5][3] = 'O';
    board[5][4] = 'O';
    board[5][5] = 'X';
    board[5][6] = 'X';
    board[5][7] = 'O';

    // row 6
    // {'O','O','X','X','O','O','X','O'}
    board[6][0] = 'O';
    board[6][1] = 'O';
    board[6][2] = 'X';
    board[6][3] = 'x';
    board[6][4] = 'O';
    board[6][5] = 'O';
    board[6][6] = 'X';
    board[6][7] = 'O';

    // row 7
    // {'O','O','O','O','O','O','O',' '}
    board[7][0] = 'O';
    board[7][1] = 'O';
    board[7][2] = 'O';
    board[7][3] = 'O';
    board[7][4] = 'O';
    board[7][5] = 'O';
    board[7][6] = 'O';
    board[7][7] = ' ';
}