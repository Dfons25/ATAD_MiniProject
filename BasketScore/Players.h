#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// Player ---------------------------------------
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
unsigned int getPlayerAge(PtPlayer _this);

// Player Grid -----------------------------------
typedef struct playersGrid {
	Player *players;
	unsigned int size;
	unsigned int capacity;
} PlayersGrid;

typedef PlayersGrid* PtPlayersGrid;

PlayersGrid createPlayersGrid(unsigned int capacity);
void addPlayersGrid(PtPlayersGrid _this, Player player);
void printPlayersGrid(PtPlayersGrid _this);
void resetPlayersGrid(PtPlayersGrid _this);
void destroyPlayersGrid(PtPlayersGrid _this);
void orderPlayersGrid(PtPlayersGrid _this, unsigned int mode);
bool isPlayersEmpty(PtPlayersGrid _this);

