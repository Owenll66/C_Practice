/****
  Programming Fundamentals for Engineers - Assignment, 2019
  File  :  assign.c

  Program:  Heroes and Villains.

  YOU ARE REQUIRED TO MODIFY THIS FILE!
****/


#include "CharacterRecord.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	CharacterRecord characters[MAX_CHARACTERS] = { 0 };
	int no_characters = 0;

	FILE *fp;
	fp = fopen("characters.txt", "r");

	no_characters = read_character_record(fp, characters);

	display_characters(characters,no_characters,0);
	//write_to_file

	return 0;
}
