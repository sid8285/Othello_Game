//declaring local variables to be used in the function
  int disc = ZERO;

  //logic used to determine Disc Count 
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(board[i][j] != SPACE){
        disc = disc + 1;
      }
    }
  }