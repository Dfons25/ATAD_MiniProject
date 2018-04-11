#pragma once

#include <stdbool.h>
#include "Players.h"
#include "Games.h"

// MFOULP -----------------------------------

void printStatisticsFouls(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid);

// MFOULG -----------------------------------

void printPlayerFoulsPerGame(PtStatisticsGrid _this);

// FAIRP ------------------------------------

typedef struct teamInfo {
	char* team;
	unsigned int* gameIdArray;
	int countGames;
	int countFouls;
} TeamInfo;

typedef struct teamInfoGrid {
	TeamInfo *teamInfo;
	unsigned int size;

} TeamInfoGrid;

typedef TeamInfo* PtTeamInfo;
typedef TeamInfoGrid* PtTeamInfoGrid;

void printFairPlayStatistic(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid);