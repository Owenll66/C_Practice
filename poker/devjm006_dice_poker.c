/*
    Dice Poker - Provided file - PFfE Assignment 1 - sp2, 2019

    Please remove and place your file comments here.

	Write your code solution in this file.  : )

	//STAGE 1: MY CODE SO FAR

	Place code to randomly generate the roll of five dice here�
	*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function display_hand to display the face value of dice to the screen.
   You are provided with this function (see below) - please do NOT modify it. : ) */
void display_hand(int hand[], int max_die);

void display_details();
int roll_die();
void deal_hand(int hand[], int max_dice);
int rank_hand(int hand[], int max_dice);
void display_rank(int rank);

void display_details(){
  printf("File     : wayby001_dice_poker.c\n");
  printf("Author   : Batman\n");
  printf("Stud ID  : 0123456X\n");
  printf("Email ID : wayby001\n");
  printf("This is my own work as defined by the\n");
  printf("University's Academic Misconduct Policy.\n\n");

}

int roll_die(){
  int die = 0;

  return 1 + (rand() % 6);
}

void deal_hand(int hand[], int max_dice)
{
  for(int i = 0; i < max_dice; i++)
  {
    hand[i] = roll_die();
  }
}


int rank_hand(int hand[], int max_dice)
{
  int rank;
  int die_count[7] = {0};
  for(int i = 0; i < max_dice; i++)
  {
    die_count[hand[i]] += 1;
  }
  int max = die_count[1];
  for(int i = 1; i < 7; i++)
  {
    if(die_count[i] > max)
    {
      max = die_count[i];
    }
  }
  if(max == 5)
  {
    return 6;//five of a kind
  }
  else if (max == 4)
  {
    return 5;//four of a kind
  }
  else if(max == 3)
  {
    //if there is a pair
    for(int i = 1; i < 7; i++)
    {
      if(die_count[i] == 2)
      {
        return 4;//full house
      }
    }
    return 3;//three of a kind
  }
  else if(max == 2)
  {
    int two_cout = 0;
    //if there is a pair
    for(int i = 1; i < 7; i++)
    {
      if(die_count[i] == 2)
      {
        two_cout ++;
      }
    }
    if(two_cout == 2)
      return 2;//two pairs
    else
      return 1;//one pair
  }
  else//if (max == 1)
  {
    return 0;//nothing special
  }
}

void display_rank(int rank)
{
  switch (rank) {
    case 0: printf("Nothing special\n");break;
    case 1: printf("One pair\n");break;
    case 2: printf("Two pairs\n");break;
    case 3: printf("Three of a kind\n");break;
    case 4: printf("Full house\n");break;
    case 5: printf("Four of a kind\n");break;
    case 6: printf("Five of a kind\n");break;
  }
}

int main() {
  //result[0]: number of wins  result[1]: number of losses  result[2]: number of draws
  int result[3] = {0};
  int num_games = 0;
  int player_hand[5] = {0};
  int dealer_hand[5] = {0};

  srand(time(NULL));

  display_details();
  printf("Would you like to play dice poker [y|n]? ");
  char play[256];
  scanf("%s" , play);
  printf("\n\n");

  while(strcmp(play,"n") != 0)
  {
    if(strcmp(play,"y") == 0)
    {
      deal_hand(player_hand, 5);
      deal_hand(dealer_hand, 5);
      printf("Player's hand:");
      display_hand(player_hand, 5);
      printf("Dealer's hand:");
      display_hand(dealer_hand, 5);
      printf("\n");

      int player_rank, dealer_rank;
      player_rank = rank_hand(player_hand, 5);
      dealer_rank = rank_hand(dealer_hand, 5);
      printf("-- Player has ");
      display_rank(player_rank);
      printf("-- Dealer has ");
      display_rank(dealer_rank);
      printf("\n");

      if(player_rank > dealer_rank)
      {
        printf("** Player wins! **\n\n");
        result[0] ++;
      }
      else if(player_rank < dealer_rank)
      {
        printf("** Dealer wins! **\n\n");
        result[1] ++;
      }
      else
      {
        printf("** Draw! **\n\n");
        result[2] ++;
      }
      num_games++;

      printf("Play again [y|n]? ");
      scanf("%s" , play);

      while(strcmp(play,"n") != 0 && strcmp(play,"y") != 0)
      {
        printf("Please enter either 'y' or 'n'.\n\n");
        printf("Play again [y|n]? ");
        scanf("%s" , play);
      }
      printf("\n\n");
    }
    else
    {
      printf("Please enter either 'y' or 'n'.\n\n");
      printf("Would you like to play dice poker [y|n]? ");
      scanf("%s" , play);
      printf("\n\n");
    }
  }

  //display results
  if(num_games == 0)
  {
    printf("No worries... another time perhaps... :)");
  }
  else
  {
    printf("Game Summary\n============\nYou played %d games:", num_games);
    printf("  |--> Games won:   %d", result[0]);
    printf("  |--> Games lost:  %d", result[1]);
    printf("  |--> Games drawn: %d", result[2]);
    printf("\nThanks for playing!\n");

  }
	return 0;
}



/* Function display_hand to display the face value of dice to the screen.
   This function takes an array of integers as a parameter (i.e. the values of the five
   die to display) and displays the dice to the screen.
   Parameters:  Array storing five die face values.
   Returns : Nothing is returned from the function. */
void display_hand(int hand[], int max_dice) {

	int i;

	/* Display die number to the screen. */
	printf("\n%16s", "");
	for (i = 0; i < max_dice; i++) {
		printf("Die %-4d", i + 1);
	}
	printf("\n%12s", "");

	/* Display face value of die to the screen. */
	printf("     ");
	for (i = 0; i < max_dice; i++) {
		printf("[%d]     ", hand[i]);
	}
	printf("\n%12s", "");

	/* Display the top row of face value to the screen. */
	for (i = 0; i < max_dice; i++) {
		if (hand[i] == 1)
			printf("%8s", " ");
		else if (hand[i] == 2 || hand[i] == 3)
			printf("%8s", "* ");
		else if (hand[i] == 4 || hand[i] == 5 || hand[i] == 6)
			printf("%8s", "* *");
	}
	printf("\n%12s", "");

	/* Display the middle row of face value to the screen. */
	for (i = 0; i < max_dice; i++) {
		if (hand[i] == 1 || hand[i] == 3 || hand[i] == 5)
			printf("%8s", "* ");
		else if (hand[i] == 6)
			printf("%8s", "* *");
		else
			printf("%8s", " ");
	}
	printf("\n%12s", "");

	/* Display the bottom row of face value to the screen. */
	for (i = 0; i < max_dice; i++) {
		if (hand[i] == 1)
			printf("%8s", " ");
		else if (hand[i] == 2 || hand[i] == 3)
			printf("%8s", "* ");
		else if (hand[i] == 4 || hand[i] == 5 || hand[i] == 6)
			printf("%8s", "* *");
	}
	printf("\n\n");
}
