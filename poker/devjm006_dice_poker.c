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


/* Function display_hand to display the face value of dice to the screen.
   You are provided with this function (see below) - please do NOT modify it. : ) */
void display_hand(int hand[], int max_die);

void display_details(void);
int roll_die(void);
void deal_hand(int hand[], int max_dice);
int rank_hand(int hand[], int max_dice);
void display_rank(int rank);

int main() {
  int player_hand[5] = { 0,0,0,0,0 };
  int dealer_hand[5] = { 0,0,0,0,0 };
	int die_count[7] = {0, 0, 0, 0, 0, 0, 0};


	printf("\n\nProgramming assignment - this will be deleted in stage 1!\n\n");
	int die = 0;
	int total;

	srand(time(NULL));


	int index;

	// Populates the player_hand array with a set of random dice values
	for (index = 0; index < 5; index++) {
		die = 1 + (rand() % 6);
		player_hand[index] = die;
	}

	//* Create an array to store the frequency of occurence of each die face value in the player hand *//
	for (index = 0; index < 5; index++) {
		die_count[player_hand[index]]++;
	}

	/*
	for (index = 0; index < 7; index++) {
		printf("%d ",die_count[index]);

	}*/



	/* Display player's hand to the screen. */
	printf("\n\nPlayer's hand:");
	display_hand(player_hand, 5);

  printf("\n die count:");
  for(int index = 0; index < 7; index++)
  {
    printf("[%d]: %d  ",index,die_count[index]);
  }
  printf("\n");

	return 0;
}


int rank_hand(int hand[], int max_dice){
  
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
