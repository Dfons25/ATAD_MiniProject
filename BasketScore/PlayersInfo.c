#include "PlayersInfo.h"

void printTeamPlayers(PtPlayersGrid _this) {
	bool teamExists = false;
	char team[20];

	printf("\tName of the team?: ");

	fgets(team, sizeof(team), stdin);
	team[strlen(team) - 1] = '\0';

	for (unsigned int i = 0; i < _this->size; i++) {
		if (strcmp((&_this->players[i])->team, team) == 0) {
			teamExists = true;
			printPlayer(&_this->players[i]);
		}
	}

	if (!teamExists) {
		printf("EQUIPA INEXISTENTE!");
	}

}


unsigned int getPlayerAge(PtPlayer _this) {
	time_t now = time(0);
	struct tm sysdate;

	localtime_s(&sysdate, &now);

	return (sysdate.tm_year+1900)- _this->birthDate.year; // tm_year começa a contagem de anos a partir de 1900

};

unsigned int countPlayersSquad(PtPlayersGrid _this, int squadType, char gender) {
	int count = 0;
	for (unsigned int i = 0; i < _this->size; i++) {

		if (squadType == SQUAD_SENIOR) {
			if ((&_this->players[i])->gender == gender && getPlayerAge(&_this->players[i]) > SQUAD_SUB18) {
				count++;
			}
		} else {
			if ((&_this->players[i])->gender == gender && getPlayerAge(&_this->players[i]) <= squadType) {
				count++;
			}
		}
	}
	return count;
};

void drawSquadTable(PtPlayersGrid _this) {

	int f14 = countPlayersSquad(_this, SQUAD_SUB14, 'F');
	int m14 = countPlayersSquad(_this, SQUAD_SUB14, 'M');
	int f16 = countPlayersSquad(_this, SQUAD_SUB16, 'F') - f14;
	int m16 = countPlayersSquad(_this, SQUAD_SUB16, 'M') - m14;
	int f18 = countPlayersSquad(_this, SQUAD_SUB18, 'F') - f14 - f16;
	int m18 = countPlayersSquad(_this, SQUAD_SUB18, 'M') - m14 - m16;
	int fS = countPlayersSquad(_this, SQUAD_SENIOR, 'F');
	int mS = countPlayersSquad(_this, SQUAD_SENIOR, 'M');

	printf("TABLE\n");
	printf("\n Level/Genre| Female  Male");
	printf("\n===============================");
	printf("\n      Sub 14| %4d     %4d", f14, m14);
	printf("\n-------------------------------");
	printf("\n      Sub 16| %4d     %4d", f16, m16);
	printf("\n-------------------------------");
	printf("\n      Sub 18| %4d     %4d", f18, m18);
	printf("\n-------------------------------");
	printf("\n     Seniors| %4d     %4d", fS, mS);
	printf("\n-------------------------------");
}

void getIdealTeam(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid){
	
	int team[5] = { 0 };
	int position[5] = { 0,1,1,2,2 };
	unsigned int squadType;
	char** squadRange[6] = { "sub14", "sub16", "sub18", "senior" };
	char** squadPostion[13] = { "CENTER", "SHOOTY GUARD", "POINT GUARD" };
	bool teamFull = true;


	printf("IDEALTEAM\n\tSquad range? (0-sub14; 1-sub16; 2-sub18; 3-senior)> ");
	scanf_s("%d", &squadType);
	getchar();
	//teste
	char gender = 'F';

	for (int i = 0; i < 5; i++) {
		team[i] = getIdealPlayer(ptStatisticsGrid, ptPlayersGrid, position[i], squadType, gender, team);
		if (team[i] == 0)
		{
			teamFull = false;
		}
	}

	if(teamFull){
		printf("\n====================================================================");
		printf("\n Ideal %s team", squadRange[squadType]);
		printf("\n====================================================================");
		for (int i = 0; i < 5; i++) {
			printf("\n   %s\n\n", squadPostion[position[i]]);
			printPlayer(&ptPlayersGrid->players[team[i]]);
			printf("-------------------------------------------------------------------");
		}
		}
		else {
			printf("\n\tNÃO EXISTEM JOGADORES PARA A EQUIPA IDEAL");
		}
	
}

int getIdealPlayer(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid, int position, unsigned int squadType, char gender, int exceptions[]) {

	int squadRanges[5] = { 0, 14, 16, 18, 100 };

	int mvpIndex = 0;
	int mvpScore = 0;
	int mvpAttendences = 0;
	int mvpAge = 200;

	int sumScore = 0;
	int numberOfGames;


	for (unsigned int x = 0; x < ptPlayersGrid->size; x++) {
		numberOfGames = 0;
		sumScore = 0;
		for (unsigned int y = 0; y < ptStatisticsGrid->size; y++) {
			if (ptPlayersGrid->players[x].id == ptStatisticsGrid->playerGameStatistics[y].idPlayer) {
				if (ptPlayersGrid->players[x].gender == gender && getPlayerAge(&ptPlayersGrid->players[x]) > squadRanges[squadType] && getPlayerAge(&ptPlayersGrid->players[x]) <= squadRanges[squadType + 1]) {
					if (!checkIfInTeam(x, exceptions)){
						numberOfGames++;
						switch (position){
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
		}
		else if (sumScore == mvpScore) {
			if (numberOfGames > mvpAttendences) {
				mvpScore = sumScore;
				mvpAge = getPlayerAge(&ptPlayersGrid->players[x]);
				mvpAttendences = numberOfGames;
				mvpIndex = x;
			}
			else if ((numberOfGames == mvpAttendences)) {
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
/* ----------------------------------------------------------------------- */

