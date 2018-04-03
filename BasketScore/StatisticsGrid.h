#pragma once
#include <stdbool.h>

#include "Statistics.h"
#include "PlayersGrid.h"

typedef struct statisticsGrid {
	PlayerGameStatistics *playerGameStatistics;
	unsigned int size;
	unsigned int capacity;
} StatisticsGrid;

typedef StatisticsGrid* PtStatisticsGrid;

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

StatisticsGrid createStatisticsGrid(unsigned int capacity);
void addStatisticsGrid(PtStatisticsGrid _this, PlayerGameStatistics playerGameStatistics);
void printGameGrid(PtStatisticsGrid _this, int idGame);
void printGameMVP(PtStatisticsGrid _this, int idGame);
void printStatisticsFouls(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid);

void printPlayerFoulsPerGame(PtStatisticsGrid _this);
void orderPlayerGameStatisticsGridAsc(PtStatisticsGrid _this);