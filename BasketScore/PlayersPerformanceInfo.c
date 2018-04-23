#pragma once

#include "FileHandler.h"
#include "PlayersPerformanceInfo.h"
#include "VarInput.h"


// LOADG -----------------------------------

void loadGames(PtStatisticsGrid _this) {
	char filename[20];

	printf("LOADG\n\tPlease enter the name of the file: ");
	readCharArray(filename, 20);

	importGamesFromFile(filename, _this);
};

// SEARCHG ----------------------------------

void printGameGrid(PtStatisticsGrid _this) {
	int totalPoints = 0, totalBlocks = 0, totalPlayers = 0;
	unsigned int idGame;

	bool gameExists = false;

	printf("SEARCHG\n\tID of the game?> ");
	readInteger(&idGame);

	for (unsigned int x = 0; x<_this->size; x++) {
		if (_this->playerGameStatistics[x].idGame == idGame) {
			totalPoints += (_this->playerGameStatistics[x].statistics.threePoints * 3) + (_this->playerGameStatistics[x].statistics.twoPoints * 2);
			totalBlocks += _this->playerGameStatistics[x].statistics.blocks;
			totalPlayers++;
			gameExists = true;
		}
	}
	if (gameExists) {
		printf("\n---------------------------------------------------");
		printf("\nTotal number of points %d", totalPoints);
		printf("\n---------------------------------------------------");
		printf("\nTotal number of blocks %d", totalBlocks);
		printf("\n---------------------------------------------------");
		printf("\nTotal number of used players %d", totalPlayers);
		printf("\n---------------------------------------------------");
	} else {
		printf("JOGO INEXISTENTE");
	}
}

// MVP -------------------------------------

void printGameMVP(PtStatisticsGrid _this) {
	int mvpID = 0, mvpScore = 0, sumScore = 0;
	unsigned int idGame;

	printf("MVP\n\tID of the game?> ");
	readInteger(&idGame);

	bool gameExists = false;

	for (unsigned int x = 0; x<_this->size; x++) {
		if (_this->playerGameStatistics[x].idGame == idGame) {
			printf("%d", _this->playerGameStatistics[x].idGame);
			sumScore = (_this->playerGameStatistics[x].statistics.threePoints * 3) 
					 + (_this->playerGameStatistics[x].statistics.twoPoints * 2) 
				     + (_this->playerGameStatistics[x].statistics.assists)
				     + (_this->playerGameStatistics[x].statistics.blocks * 2) 
				     - (_this->playerGameStatistics[x].statistics.fouls * 3);
			if (sumScore > mvpScore) {
				mvpScore = sumScore;
				mvpID = _this->playerGameStatistics[x].idPlayer;
			}
			gameExists = true;
		}
	}
	if (gameExists) {
		printf("\n---------------------------------------------------");
		printf("\nO melhor jogador em campo tem o ID %d e um MVP = %d", mvpID, mvpScore);
		printf("\n---------------------------------------------------");
	} else {
		printf("JOGO INEXISTENTE");
	}
}