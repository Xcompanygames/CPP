#include <stdio.h>

int win (int table[7][6], int player){
        //check for vertical win
        for (int i = 0; i < 7; i++){
                for (int j = 0; j < 4; j++){
                        if (player == table[i][j] && player == table[i][j+1] && player == table [i][j+2] && player == table [i][j+3]) return 1;
                }
        }
        //check for horizontal win
        for (int j = 0; j < 6; j++){
                for (int i = 0; i < 4; i++){
                        if (player == table[i][j] && player == table[i+1][j] && player == table[i+2][j] && player == table[i+3][j]) return 1;
                }
        }
        //check for diagonal win
        for (int i = 0; i < 7; i++){
                for (int j = 0; j < 6; j++){
                        //holy shit this is a mess. I'm pretty sure it works, but I didn't actually confirm it.
                        if (player == table[i][j] && player == table[i+1][j+1] && player == table[i+2][j+2] && player == table[i+3][j+3]) return 1;
                        if (player == table[7-i][j] && player == table[6-i][j+1] && player == table[5-i][j+2] && player == table[4-i][j+3]) return 1;
                        if (player == table[i][6-j] && player == table[i+1][5-j] && player == table[i+2][4-j] && player == table[i+3][3-j]) return 1;
                        if (player == table[7-i][6-j] && player == table[6-i][5-j] && player == table[5-i][4-j] && player == table[4-i][3-j]) return 1;
                }
        }
        return 0;
} ///////////victory condition


int  //input col
inputcol ()
{fseek(stdin,0,SEEK_END);
    int c=1;
      scanf("%d", &c);
  if (c < 8&&c>0)
    { 
        return c;
   }
   else if(c==0){
       return c;
   }
   else
   {
     printf("Invalid input! the number must be between 1 to 7:");
       inputcol();
   }

}

int //input row
inputrow ()
{fseek(stdin,0,SEEK_END);
  int c=1;
 scanf("%d", &c);
  if (c < 7&&c>0)
    {
        return c;
     }else
   {
       printf("Invalid input! the number must be between 1 to 6:");
       inputrow();
   }
}

//changing the array!!!
void arraychange(int  a[6][7],int col,int row,int player,int undo){
if(undo==1){
        a[col-1][row-1]=0;

}else{
   int row2;
   int col2;
    if(a[col-1][row-1]==0&&row!=0){
    a[col-1][row-1]=player;
    }
    else{
    printf("Invalid input, this column is full. Please choose another one");
    col2 = inputcol();
    row2 = inputrow();
    arraychange(a,col2,row2,player,0);
    }}
}
///end of changing function

      //    printing the array 0 is non, 1 is X and 2 is O
void
arrprint (int a[6][7]) 
{  printf (" ");

      for (int x = 1; x < 8; x++) //print numbers in bot
    {
      printf ("%d ", x);
      printf (" ");

    }
      printf ("\n");

    
  for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j < 7; j++)
	{
	  printf ("|");

	  if (a[i][j] == 0)
	    {
	      printf (" ");

	    }
	  if (a[i][j] == 1)
	    {
	      printf ("X");
	    }
	  if (a[i][j] == 2)
	    {
	      printf ("O");

	    }
	  printf ("|");

	}
      printf ("\n");
    }
}

int
playerswitch (int player) //changing the players
{

  if (player == 2)
    {      player = 1;
    return player;
    }
   if (player == 1)
    { player = 2;
    return player;

   
    }
}

void
playerprompt (int player) //prompt msg
{
  if (player == 1)
    {
      printf ("\n");

      printf ("Player X, please enter a row and a column number (or 0 to undo):");
    }
  if (player == 2)
    {
      printf ("\n");

      printf ("Player O, please enter a row and a column number (or 0 to undo):");
    }
}
///the main game function
void
gameloop ()
{fseek(stdin,0,SEEK_END);
int vic=0;
////vic 1 player 1 won, vic 2 player 2 won
  int player = 1; //who's starting
  int row=0;
  int col=0;
  int ff=0; //int first turn
  //new array
  int myarray[6][7] = { 
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0
  };
  int coltest=0;
  printf ("Welcome! ");
while(vic==0){
printf ("\n");
arrprint (myarray);
playerprompt (player);
printf ("\n");
col = inputcol();
if (col==0&&ff>0){
    arraychange(myarray,coltest,row,player,1);
    ff=ff+1;
    if (win(myarray,player)==1&&player==1){
    printf("Player X wins!");
return 0;

}
if (win(myarray,player)==1&&player==2){
    printf("Player O wins!");
return 0;
}
player = playerswitch(player);

}



else{
coltest=col;
row = inputrow();
arraychange(myarray,col,row,player,0);
  ff=ff+1;
if (win(myarray,player)==1&&player==1){
    printf("Player X wins!");
return 0;

}
if (win(myarray,player)==1&&player==2){
    printf("Player O wins!");
return 0;
}
player = playerswitch(player);

}}
}

int
main ()
{
  gameloop ();

  return 0;
}