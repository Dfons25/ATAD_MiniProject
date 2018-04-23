#pragma once

#include "AdvanceIndicators.h"
#include "UserInterface.h"
#include "VarInput.h"
#include <ctype.h>

// IDEALTEAM --------------------------------

void getIdealTeam(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid) {

	int team[5] = { 0 };
	int position[5] = { 0,1,1,2,2 };
	unsigned int squadType = 1;
	char** squadRange[6] = { "sub14", "sub16", "sub18", "senior" };
	char** squadPostion[13] = { "CENTER", "SHOOTY GUARD", "POINT GUARD" };
	bool teamFull = true;
	char gender;

	
	printf("IDEALTEAM\n\tSquad range? (0-sub14; 1-sub16; 2-sub18; 3-senior) > ");
	readInteger(&squadType);

	printf("\n\tSquad gender? (M - Male; F - Female) > ");
	scanf_s(" %c", &gender, 1);
	getchar();

	for (int i = 0; i < 5; i++) {
		team[i] = getIdealPlayer(ptStatisticsGrid, ptPlayersGrid, position[i], squadType, gender, team);
		if (team[i] == 0) {
			teamFull = false;
		}
	}

	if (teamFull) {
		printf("\n====================================================================");
		printf("\n Ideal %s team", squadRange[squadType]);
		printf("\n====================================================================");
		for (int i = 0; i < 5; i++) {
			printf("\n   %s\n\n", squadPostion[position[i]]);
			printPlayer(&ptPlayersGrid->players[team[i]]);
			printf("-------------------------------------------------------------------");
		}
	} else {
		printf("\n\tNOT ENOUGH PLAYERS TO MAKE IDEAL TEAM");
	}

}

int getIdealPlayer(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid, int position, unsigned int squadType, char gender, int exceptions[]) {

	unsigned int squadRanges[5] = { 0, 14, 16, 18, 100 };

	unsigned int mvpIndex = 0;
	unsigned int mvpScore = 0;
	unsigned int mvpAttendences = 0;
	unsigned int mvpAge = 200;

	unsigned int sumScore = 0;
	unsigned int numberOfGames;


	for (unsigned int x = 0; x < ptPlayersGrid->size; x++) {
		numberOfGames = 0;
		sumScore = 0;
		for (unsigned int y = 0; y < ptStatisticsGrid->size; y++) {
			if (ptPlayersGrid->players[x].id == ptStatisticsGrid->playerGameStatistics[y].idPlayer) {
				if (ptPlayersGrid->players[x].gender == toupper(gender) && getPlayerAge(&ptPlayersGrid->players[x]) > squadRanges[squadType] && getPlayerAge(&ptPlayersGrid->players[x]) <= squadRanges[squadType + 1]) {
					if (!checkIfInTeam(x, exceptions)) {
						numberOfGames++;
						switch (position) {
						case 0:
							sumScore += ptStatisticsGrid->playerGameStatistics[y].statistics.assists;
							break;
						case 1:
							sumScore += (ptStatisticsGrid->playerGameStatistics[y].statistics.threePoints * 3) + (ptStatisticsGrid->playerGameStatistics[y].statistics.twoPoints * 2);
							break;
						case 2:
							sumScore += ptStatisticsGrid->playerGameStatistics[y].statistics.blocks;
							break;
						}
					}
				}
			}
		}

		if (sumScore > mvpScore) {
			mvpScore = sumScore;
			mvpAge = getPlayerAge(&ptPlayersGrid->players[x]);
			mvpAttendences = numberOfGames;
			mvpIndex = x;
		} else if (sumScore == mvpScore) {
			if (numberOfGames > mvpAttendences) {
				mvpScore = sumScore;
				mvpAge = getPlayerAge(&ptPlayersGrid->players[x]);
				mvpAttendences = numberOfGames;
				mvpIndex = x;
			} else if ((numberOfGames == mvpAttendences)) {
				if (getPlayerAge(&ptPlayersGrid->players[x]) < mvpAge) {
					mvpScore = sumScore;
					mvpAge = getPlayerAge(&ptPlayersGrid->players[x]);
					mvpAttendences = numberOfGames;
					mvpIndex = x;
				}
			}
		}
	}
	return mvpIndex;
}

bool checkIfInTeam(int playerId, int exceptions[]) {
	for (int i = 0; i < 5; i++) {
		if (playerId == exceptions[i]) {
			return true;
		}
	}
	return false;
}
