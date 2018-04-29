#pragma once
#include "Games.h"


// Statistics -------------------------------------------
Statistics createStatistics(int twoPoints, int threePoints, int assists, int fouls, int blocks) {
	Statistics newStatistics;
	newStatistics.twoPoints = twoPoints;
	newStatistics.threePoints = threePoints;
	newStatistics.assists = assists;
	newStatistics.fouls = fouls;
	newStatistics.blocks = blocks;
	return newStatistics;
}

PlayerGameStatistics createPlayerGameStatistics(int idPlayer, int idGame, Statistics statistics) {
	PlayerGameStatistics newPlayerGameStatistics;
	newPlayerGameStatistics.idPlayer = idPlayer;
	newPlayerGameStatistics.idGame = idGame;
	newPlayerGameStatistics.statistics = statistics;
	return newPlayerGameStatistics;
}

void printPlayerGameStatistics(PtPlayerGameStatistics _this) {
	printf("%3d : %3d : %3d : %3d : %3d : %3d : %3d  \n", _this->idPlayer, _this->idGame, _this->statistics.twoPoints, _this->statistics.threePoints, _this->statistics.assists, _this->statistics.fouls, _this->statistics.blocks);
}


// Statistics Grid ----------------------------------------

StatisticsGrid createStatisticsGrid(unsigned int capacity) {
	StatisticsGrid newStatisticsGrid;
	newStatisticsGrid.playerGameStatistics = (PlayerGameStatistics*)calloc(capacity, sizeof(PlayerGameStatistics));
	newStatisticsGrid.size = 0;
	newStatisticsGrid.capacity = capacity;
	return newStatisticsGrid;
}

void addStatisticsGrid(PtStatisticsGrid _this, PlayerGameStatistics playerGameStatistics) {
	if (_this->size == _this->capacity) {
		_this->capacity += 2;
		_this->playerGameStatistics = (PlayerGameStatistics*)realloc(_this->playerGameStatistics, _this->capacity * sizeof(PlayerGameStatistics));
	}
	_this->playerGameStatistics[_this->size] = playerGameStatistics;
	_this->size++;
}

void swapGame(PlayerGameStatistics *xp, PlayerGameStatistics *yp) {
	PlayerGameStatistics temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void orderPlayerGameStatisticsGrid(PtStatisticsGrid _this, unsigned int mode) {
	for (unsigned int x = 0; x < _this->size - 1; x++) {
		for (unsigned int y = 0; y < _this->size - x - 1; y++) {
			if (mode == 1) { // ASC
				if ((_this->playerGameStatistics[y].idGame > _this->playerGameStatistics[y + 1].idGame)) {
					swapGame(&_this->playerGameStatistics[y], &_this->playerGameStatistics[y + 1]);
				}
			} else { // DESC
				if ((_this->playerGameStatistics[y].idGame < _this->playerGameStatistics[y + 1].idGame)) {
					swapGame(&_this->playerGameStatistics[y], &_this->playerGameStatistics[y + 1]);
				}
			}
		}
	}
}

void resetStatisticsGrid(PtStatisticsGrid _this) {
	_this->size = 0;
}

bool isGamesEmpty(PtStatisticsGrid _this) {
	if (_this->size > 0) {
		return false;
	} else {
		return true;
	}
};
