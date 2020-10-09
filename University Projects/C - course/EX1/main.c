#include <stdio.h>

//start the game

int
Paketstart (int x[])
{
  printf ("Hello, User! Enter 3 numbers:\n");
  int a = 0;
  for (a = 0; a < 3; a++)
    {
      scanf ("%d", &x[a]);
      if (x[a]<0){
          	  printf ("\nInput is invalid\n");
          	  	  Paketstart (x);

      }
      printf ("Value is: %d\n", x[a]);
      int arrcop[2];
      copy (x, arrcop);
      sort (arrcop);
      if (arrcop[0] == 0 && arrcop[1] == 0 && arrcop[2] == 1)
	{

	  printf ("\nInput is invalid\n");
	  Paketstart (x);
	}

    }
}

//print array
void
Paket (int x[])
{
  int a = 0;
  printf ("paket is:");
  for (a = 0; a < 3; a++)
    {
      printf ("  %d", x[a]);

    }
}

//copy arr
void
copy (int x[2], int arrcop[2])
{
  int j;
  for (j = 0; j < 3; ++j)
    arrcop[j] = x[j];
}



//sort the array
void
sort (int arr[])
{
  int temp;
  while (arr[0] > arr[1] || arr[0] > arr[2] || arr[1] > arr[2])
    {
      if (arr[0] > arr[1])
	{
	  temp = arr[0];
	  arr[0] = arr[1];
	  arr[1] = temp;
	}

      if (arr[1] > arr[2])
	{
	  temp = arr[1];
	  arr[1] = arr[2];
	  arr[2] = temp;

	}
      if (arr[1] > arr[2])
	{
	  temp = arr[1];
	  arr[1] = arr[2];
	  arr[2] = temp;
	}
    }
}

//is the current paket balanced?
int
balance (int x[])
{
  int y = 0;
  int arrcop[2];
  copy (x, arrcop);
  sort (arrcop);
  if (arrcop[0] + arrcop[1] == arrcop[2])
    {
      y = 1;
    }
  return y;
  //x is 1 player starts, if x is 0 pc start
}


  //Userturn - choosing a heap, and sub from it a number
int
userturn (int arr[2])
{
  int heap;
  int num;
  printf ("\nYour Turn\n");
  printf ("Please enter a heap:\n");
  scanf ("%d", &heap);
  printf ("Please enter how much to sub from the desired heap:\n");
  scanf ("%d", &num);
  if (num <= 0 || num > arr[heap])
    {
      printf ("Enter a diffrent number!\n");
      return userturn (arr);
    }
  else
    {
      printf ("%d\n", num);
      arr[heap] = arr[heap] - num;
    }
}

void
PCturn (int x[])
{
  printf ("\nComputer turn");
  int rd;
  int arrcop[2];
  copy (x, arrcop);
  sort (arrcop);

//conditions X 0 0
  if (arrcop[0] == 0 && arrcop[1] == 0 && arrcop[2] > 1)
    {
      printf ("I changed ");
      printf ("%d", arrcop[2]);
      printf ("to 1\n");
      arrcop[2] = 1;
//conditions X 1 0
    }
  else if (arrcop[0] == 0 && arrcop[1] == 1 && arrcop[2] > 1)
    {
      printf ("I changed ");
      printf ("%d", arrcop[2]);
      printf ("to 0\n");
      arrcop[2] = 0;
//conditions X 1 1
    }
  else if (arrcop[0] == 1 && arrcop[1] == 1 && arrcop[2] > 1)
    {
      printf ("I changed \n");
      printf ("%d", arrcop[2]);
      printf (" to 1 \n");
      arrcop[2] = 1;
    }

  else
    {
      rd = arrcop[2];
      arrcop[2] = arrcop[1] - arrcop[0];
      printf (" I changed\n");
      printf ("%d", rd);
      printf (" to ");
      printf ("%d", arrcop[2]);
    }

  copy (arrcop, x);

}

int
winningcondition (int x[])
{
  int y = 1;
  int arrcop[2];
  copy (x, arrcop);
  sort (arrcop);
  if (arrcop[0] == 0 && arrcop[1] == 0 && arrcop[2] == 1)
    {
      y = 1;
    }
  else
    {
      y = 0;
    }
  return y;
}

int
main ()
{
  //whostated
  int started = 0;
  int paket[2];
  Paketstart (paket);
  balance (paket);
  Paket (paket);
//who is first?
  if (balance (paket) == 1)
    {
      userturn (paket);
      Paket (paket);
      started = 0;
    }
  else
    {
      PCturn (paket);
      Paket (paket);
      started = 1;
    }

///game of nim starts here
  int turn = 0;
  while (winningcondition (paket) == 0)
    {
      if (started = 1)
	{
	  userturn (paket);
	  Paket (paket);
	  turn = 0;
	  PCturn (paket);
	  Paket (paket);
	  turn = 1;


	}
      else
	{
	  PCturn (paket);
	  Paket (paket);
	  turn = 1;
	  userturn (paket);
	  Paket (paket);
	  turn = 0;
	}
    }
  if (turn = 0)
    {
      printf ("User win!");
    }
  else
    printf ("PC win");
  return 0;
}
