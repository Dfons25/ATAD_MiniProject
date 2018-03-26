#pragma once
#include "Statistics.h"

Statistics createStatistics(int twoPoints, int threePoints, int assists, int fouls, int blocks)
{
	Statistics newStatistics;
	newStatistics.twoPoints = twoPoints;
	newStatistics.threePoints = threePoints;
	newStatistics.assists = assists;
	newStatistics.fouls = fouls;
	newStatistics.blocks = blocks;
	return newStatistics;
}

PlayerGameStatistics createPlayerGameStatistics(int idPlayer, int idGame, Statistics statistics)
{
	PlayerGameStatistics newPlayerGameStatistics;
	newPlayerGameStatistics.idPlayer = idPlayer;
	newPlayerGameStatistics.idGame = idGame;
	newPlayerGameStatistics.statistics = statistics;
	return newPlayerGameStatistics;
}

void printPlayerGameStatistics(PtPlayerGameStatistics _this)
{
	printf("%3d : %3d : %3d : %3d : %3d : %3d : %3d  \n", _this->idPlayer, _this->idGame, _this->statistics.twoPoints, _this->statistics.threePoints, _this->statistics.assists, _this->statistics.fouls, _this->statistics.blocks);
}
