#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Games ----------------------------------------------------------

typedef struct statistics {
	int twoPoints;
	int threePoints;
	int assists;
	int fouls;
	int blocks;
}Statistics;

typedef struct playerGameStatistics {
	int idPlayer;
	int idGame;
	Statistics statistics;
}PlayerGameStatistics;

typedef PlayerGameStatistics* PtPlayerGameStatistics;

Statistics createStatistics(int twoPoints, int threePoints, int assists, int fouls, int blocks);
PlayerGameStatistics createPlayerGameStatistics(int idPlayer, int idGame, Statistics statistics);
void printPlayerGameStatistics(PtPlayerGameStatistics _this);

// Games Grid -------------------------------------------------------
typedef struct statisticsGrid {
	PlayerGameStatistics *playerGameStatistics;
	unsigned int size;
	unsigned int capacity;
} StatisticsGrid;

typedef StatisticsGrid* PtStatisticsGrid;

StatisticsGrid createStatisticsGrid(unsigned int capacity);
void addStatisticsGrid(PtStatisticsGrid _this, PlayerGameStatistics playerGameStatistics);