#pragma once

typedef struct date {
	int day, month, year;
}Date;

typedef struct player {
	int id;
	char name[50];
	char team[50];
	Date birthDate;
	char gender;
}Player;

typedef Player* PtPlayer;

Player playerCreate(unsigned int id, char name[], char team[], Date birthDate, char gender);
Date dateCreate(unsigned int day, unsigned int month, unsigned int year);

void playerPrint(PtPlayer _this);

typedef struct playersGrid {
	Player *players;
	unsigned int size;
	unsigned int capacity;
} PlayersGrid;

typedef PlayersGrid* PtPlayersGrid;


PlayersGrid playersGridCreate(unsigned int capacity);
void playersGridAddPlayer(PtPlayersGrid _this, Player player);
void playersGridPrint(PtPlayersGrid _this);