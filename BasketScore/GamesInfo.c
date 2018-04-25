#pragma once

#include "Games.h"
#include "GamesInfo.h"


// MFOULP -----------------------------------

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
		if (numberOfGames != 0 && numberOfFouls != 0) {
			printf("\n\t%-20s | %13d | %.2f", ptPlayersGrid->players[x].name, numberOfGames, (float)numberOfFouls / numberOfGames);
		} else if (numberOfGames != 0 && numberOfFouls == 0) {
			printf("\n\t%-20s | %13d | %d", ptPlayersGrid->players[x].name, numberOfGames, 0);
		}
	}
};


// MFOULG -----------------------------------

double averageFoulsPerGame(PtStatisticsGrid _this) {
	double sum = 0;
	for (unsigned int i = 0; i < _this->size; i++) {
		sum += (&_this->playerGameStatistics[i])->statistics.fouls;
	}

	return (sum / (_this->size));

}

StatisticsGrid getGameArrayById(int gameId, PtStatisticsGrid _this) {
	StatisticsGrid temp = createStatisticsGrid(1);

	for (unsigned int i = 0; i < _this->size; i++) {
		if ((&_this->playerGameStatistics[i])->idGame == gameId) {
			addStatisticsGrid(&temp, _this->playerGameStatistics[i]);
		}
	}
	return temp;
}

void printPlayerFoulsPerGame(PtStatisticsGrid _this) {
	StatisticsGrid gameArray;

	orderPlayerGameStatisticsGrid(_this,1); // ASC

	printf("\tFOULS AVERAGE GAME\n");
	printf("\t#Game | Av. Fouls\n");
	printf("\t=================\n");

	for (unsigned int i = 0; i < _this->size; i++) {
		gameArray = getGameArrayById((&_this->playerGameStatistics[i])->idGame, _this);
		printf("\t%02d    | %.2f\n", (&_this->playerGameStatistics[i])->idGame
								   , averageFoulsPerGame(&gameArray));
		i += (gameArray.size - 1);
	}
}

// FAIRP -----------------------------------

char* getPlayerTeam(unsigned int idPlayer, PtPlayersGrid ptPlayersGrid) {
	for (unsigned int i = 0; i < ptPlayersGrid->size; i++) {
		if (ptPlayersGrid->players[i].id == idPlayer) {
			return ptPlayersGrid->players[i].team;
		}
	}

	return false;
}

TeamInfo createTeamInfo(char* team) {
	TeamInfo newTeamInfo;
	newTeamInfo.team = team;
	newTeamInfo.gameIdArray = (int*)calloc(1, sizeof(int));
	newTeamInfo.countFouls = 0;
	newTeamInfo.countGames = 0;

	return newTeamInfo;
}

void addGameToTeamInfo(PtTeamInfo _this, int gameId) {
	if (_this->countGames > 0) {
		_this->gameIdArray = (int*)realloc(_this->gameIdArray, 2 * (_this->countGames) * sizeof(int));
	}

	_this->gameIdArray[_this->countGames] = gameId;
	_this->countGames++;
}

TeamInfoGrid createTeamInfoGrid() {
	TeamInfoGrid newTeamInfoGrid;
	newTeamInfoGrid.teamInfo = (TeamInfo*)calloc(1, sizeof(TeamInfo));
	newTeamInfoGrid.size = 0;
	return newTeamInfoGrid;
}

void addTeamInfo(PtTeamInfoGrid _this, TeamInfo teamInfo) {
	if (_this->size > 0) {
		_this->teamInfo = (TeamInfo*)realloc(_this->teamInfo, 2 * (_this->size) * sizeof(TeamInfo));
	}
	_this->teamInfo[_this->size] = teamInfo;
	_this->size++;
}

PtTeamInfo getTeamInfo(PtTeamInfoGrid _this, char* team) {
	for (unsigned int i = 0; i < _this->size; i++) {
		if (strcmp(_this->teamInfo[i].team, team) == 0) {
			return &(_this->teamInfo[i]);
		}
	}

	return NULL;
}

bool existsGameInTeamInfo(PtTeamInfo _this, int gameId) {
	for (int i = 0; i < _this->countGames; i++) {
		if (_this->gameIdArray[i] == gameId) {
			return true;
		}
	}

	return false;
}

void orderFairPlayStatistic(PtTeamInfoGrid _this) {
	for (unsigned int x = 0; x < _this->size - 1; x++) {
		for (unsigned int y = 0; y < _this->size - x - 1; y++) {
			if ((float)(_this->teamInfo[y].countFouls / _this->teamInfo[y].countGames) >
				(float)(_this->teamInfo[y + 1].countFouls / _this->teamInfo[y + 1].countGames)) {

				TeamInfo temp = *(&_this->teamInfo[y]);
				*(&_this->teamInfo[y]) = *(&_this->teamInfo[y + 1]);
				*(&_this->teamInfo[y + 1]) = temp;
			}
		}
	}
}

void printFairPlayStatistic(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid) {

	TeamInfoGrid teamInfoGrid = createTeamInfoGrid();

	for (unsigned int i = 0; i < ptStatisticsGrid->size; i++) {
		char* team = getPlayerTeam(ptStatisticsGrid->playerGameStatistics[i].idPlayer, ptPlayersGrid);
		PtTeamInfo ptTeamInfo = getTeamInfo(&teamInfoGrid, team);

		if (ptTeamInfo != NULL) {
			if (!(existsGameInTeamInfo(ptTeamInfo, ptStatisticsGrid->playerGameStatistics[i].idGame))) {
				addGameToTeamInfo(ptTeamInfo, ptStatisticsGrid->playerGameStatistics[i].idGame);
			}
			ptTeamInfo->countFouls += ptStatisticsGrid->playerGameStatistics[i].statistics.fouls;
		} else {
			TeamInfo teamInfo = createTeamInfo(team);
			teamInfo.countFouls += ptStatisticsGrid->playerGameStatistics[i].statistics.fouls;
			addGameToTeamInfo(&teamInfo, ptStatisticsGrid->playerGameStatistics[i].idGame);
			addTeamInfo(&teamInfoGrid, teamInfo);
		}

	}

	orderFairPlayStatistic(&teamInfoGrid);

	for (unsigned int i = 0; i < teamInfoGrid.size; i++) {
		printf("\n\tTeam %-5s| Fouls: %-2d| Games: %-2d| Fouls Average: %.2f", teamInfoGrid.teamInfo[i].team
			, teamInfoGrid.teamInfo[i].countFouls
			, teamInfoGrid.teamInfo[i].countGames
			, (float)teamInfoGrid.teamInfo[i].countFouls / teamInfoGrid.teamInfo[i].countGames);
	}



}