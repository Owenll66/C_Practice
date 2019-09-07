/****
  Programming Fundamentals for Engineers - Assignment, 2019
  File  :  CharacterRecord.c

  YOU ARE REQUIRED TO MODIFY THIS FILE!
****/


#include "CharacterRecord.h"
#include <stdio.h>

int read_character_record(FILE *infile, CharacterRecord characters[]) {

	char name[STRING_LENGTH + 1];
	int  i = 0;
	char hero;

	fgets(name, STRING_LENGTH + 1, infile);

	while (i < MAX_CHARACTERS && !feof(infile))
	{

		name[strlen(name) - 1] = '\0';
		strcpy(characters[i].name, name);

		fgets(name, STRING_LENGTH + 1, infile);
		name[strlen(name) - 1] = '\0';
		strcpy(characters[i].secret_identity, name);

		fscanf(infile, "%c", &hero);
		if (hero == 'h')
			characters[i].hero = 1;
		else
			characters[i].hero = 0;
		fscanf(infile, "%d %d %d %d %d ", &characters[i].no_battles, &characters[i].no_won,
			&characters[i].no_lost, &characters[i].no_drawn, &characters[i].health);

		i++;

		fgets(name, STRING_LENGTH + 1, infile);
	}

	return i;
}

void display_characters(CharacterRecord character[], int total_num, int status)
{

	//printf("%s",character[1].name);
	printf("|===================================================|\n");
	printf("|          Characters (Heroes & Villains)           |\n");
	printf("|===================================================|\n");
	printf("|                                                   |\n");
	printf("|  Character Name             B  W  L  D  Health    |\n");
	printf("|===================================================|\n");
	if(status == 0)
	{
		for(int i = 0; i<total_num; i++)
		{
			character[i].name[strlen(character[i].name) - 1] = '\0';
			printf("|  %-26s",character[i].name);
			printf("%2d %2d %2d %2d %7d%%   |\n", character[i].no_battles, character[i].no_won,
			character[i].no_lost, character[i].no_drawn, character[i].health);

			printf("|---------------------------------------------------|\n");
		}
	}
	else if(status == 1)
	{

	}
	else if(status == 2)
	{

	}

	printf("|===================================================|\n");
}

/*int update_character_health(CharacterRecord [], int, int)
{

}*/

int update_character_health(CharacterRecord c[], int a, int b)
{
	return 1;
}
