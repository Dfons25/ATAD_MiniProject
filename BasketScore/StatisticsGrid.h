#pragma once
#include "Statistics.h"

typedef struct statisticsGrid {
	PlayerGameStatistics *playerGameStatistics;
	unsigned int size;
	unsigned int capacity;
} StatisticsGrid;

typedef StatisticsGrid* PtStatisticsGrid;

StatisticsGrid createStatisticsGrid(unsigned int capacity);
void addStatisticsGrid(PtStatisticsGrid _this, PlayerGameStatistics playerGameStatistics);
void printGameGrid(PtStatisticsGrid _this, int idGame);
void printGameMVP(PtStatisticsGrid _this, int idGame);