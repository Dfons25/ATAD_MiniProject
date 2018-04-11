#include "PlayersInfo.h"

// LOADP -----------------------------------
void loadPlayers(PtPlayersGrid _this) {
	char filename[20];

	printf("LOADP\n\tPlease enter the name of the file: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strlen(filename) - 1] = '\0';

	importPlayersFromFile(filename, _this);
}


// SHOWP -----------------------------------

void showPlayers(PtPlayersGrid _this) {
	unsigned int option;

	printf("SHOWP\n\t1 - Sort [A-Z]\n\t2 - Sort [Z-A]\n\tOption> ");
	scanf_s("%d", &option);
	getchar();

	orderPlayersGrid(_this, option);
	printPlayersGrid(_this);

}


// TABLE -----------------------------------

unsigned int countPlayersSquad(PtPlayersGrid _this, int squadType, char gender) {
	int range, count = 0;

	switch (squadType) {
		case SQUAD_SUB14: range = 0; break;
		case SQUAD_SUB16: range = SQUAD_SUB14; break;
		case SQUAD_SUB18: range = SQUAD_SUB16; break;
	}
	for (unsigned int i = 0; i < _this->size; i++) {

		if (squadType == SQUAD_SENIOR) {
			if (_this->players[i].gender == gender && getPlayerAge(&(_this->players[i])) > SQUAD_SUB18) {
				count++;
			}
		} else {
			if (_this->players[i].gender == gender && 
				((getPlayerAge(&_this->players[i]) <= squadType) && ((getPlayerAge(&_this->players[i]) > range)))) {
				count++;
			}
		}
	}
	return count;
};

void printSquadTable(PtPlayersGrid _this) {

	printf("TABLE\n");
	printf("\n Level/Genre| Female  Male");
	printf("\n===============================");
	printf("\n      Sub 14| %4d     %4d", countPlayersSquad(_this, SQUAD_SUB14, 'F'),
										  countPlayersSquad(_this, SQUAD_SUB14, 'M'));
	printf("\n-------------------------------");
	printf("\n      Sub 16| %4d     %4d", countPlayersSquad(_this, SQUAD_SUB16, 'F'),
										  countPlayersSquad(_this, SQUAD_SUB16, 'M'));
	printf("\n-------------------------------");
	printf("\n      Sub 18| %4d     %4d", countPlayersSquad(_this, SQUAD_SUB18, 'F'),
										  countPlayersSquad(_this, SQUAD_SUB18, 'M'));
	printf("\n-------------------------------");
	printf("\n     Seniors| %4d     %4d", countPlayersSquad(_this, SQUAD_SENIOR, 'F'),
										  countPlayersSquad(_this, SQUAD_SENIOR, 'M'));
	printf("\n-------------------------------");
}

// SEARCH ----------------------------------

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




