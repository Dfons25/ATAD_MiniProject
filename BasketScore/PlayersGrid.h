#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Players.h"

typedef struct playersGrid {
	Player *players;
	unsigned int size;
	unsigned int capacity;
} PlayersGrid;

typedef PlayersGrid* PtPlayersGrid;

PlayersGrid createPlayersGrid(unsigned int capacity);
void addPlayersGrid(PtPlayersGrid _this, Player player);
void printPlayersGrid(PtPlayersGrid _this);
void orderPlayersGridAsc(PtPlayersGrid _this);
void orderPlayersGridDesc(PtPlayersGrid _this);
void swap(Player *xp, Player *yp);