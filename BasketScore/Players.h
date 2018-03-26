#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct date {
	int day, month, year;
} Date;

typedef struct player {
	int id;
	char name[50];
	char team[50];
	Date birthDate;
	char gender;
} Player;

typedef Player* PtPlayer;

Player createPlayer(unsigned int id, char name[], char team[], Date birthDate, char gender);
Date createDate(unsigned int day, unsigned int month, unsigned int year);
void printPlayer(PtPlayer _this);