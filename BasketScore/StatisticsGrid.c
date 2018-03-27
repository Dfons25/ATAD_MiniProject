#pragma once
#include "stdbool.h"

#include "StatisticsGrid.h"
#include "PlayersGrid.h"

StatisticsGrid createStatisticsGrid(unsigned int capacity)
{
	StatisticsGrid newStatisticsGrid;
	newStatisticsGrid.playerGameStatistics = (PlayerGameStatistics*)calloc(capacity, sizeof(PlayerGameStatistics));
	newStatisticsGrid.size = 0;
	newStatisticsGrid.capacity = capacity;
	return newStatisticsGrid;
}

void addStatisticsGrid(PtStatisticsGrid _this, PlayerGameStatistics playerGameStatistics)
{
	if (_this->size == _this->capacity) {
		_this->capacity += 2;
		_this->playerGameStatistics = (PlayerGameStatistics*)realloc(_this->playerGameStatistics, _this->capacity * sizeof(PlayerGameStatistics));
	}
	_this->playerGameStatistics[_this->size] = playerGameStatistics;
	_this->size++;
}


void printGameGrid(PtStatisticsGrid _this, int idGame)
{
	int totalPoints = 0;
	int totalBlocks = 0;
	int totalPlayers = 0;
	bool gameExists = false;

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
	}
	else {
		printf("JOGO INEXISTENTE");
	}
}

void printGameMVP(PtStatisticsGrid _this, int idGame)
{
	int mvpID = 0;
	int mvpScore = 0;
	int sumScore = 0;

	bool gameExists = false;

	for (unsigned int x = 0; x<_this->size; x++) {
		if (_this->playerGameStatistics[x].idGame == idGame) {
			printf("%d", _this->playerGameStatistics[x].idGame);
			sumScore = (_this->playerGameStatistics[x].statistics.threePoints * 3) + (_this->playerGameStatistics[x].statistics.twoPoints * 2) + _this->playerGameStatistics[x].statistics.assists + (_this->playerGameStatistics[x].statistics.blocks * 2) - (_this->playerGameStatistics[x].statistics.fouls * 3);
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
	}
	else {
		printf("JOGO INEXISTENTE");
	}
}

void printStatisticsFouls(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid) {
	int numberOfGames;
	int numberOfFouls;
	printf("MFOULP\n\tFOULS AVERAGE PER PLAYER\n\n\tPlayer Name          | #Played Games | Av. Fouls");
	printf("\n\t ====================================================");

	for (unsigned int x = 0; x < ptPlayersGrid->size; x++) {
		numberOfGames = 0;
		numberOfFouls = 0;
		for (unsigned int y = 0; y < ptStatisticsGrid->size; y++) {
			if (ptPlayersGrid->players[x].id == ptStatisticsGrid->playerGameStatistics[y].idPlayer) {
				numberOfGames++;
				numberOfFouls += ptStatisticsGrid->playerGameStatistics[y].statistics.fouls;
			}
		}
		if(numberOfGames != 0 && numberOfFouls != 0){
		printf("\n\t%-20s | %13d | %.2f", ptPlayersGrid->players[x].name, numberOfGames , (float)numberOfFouls / numberOfGames);
		}
	}
};