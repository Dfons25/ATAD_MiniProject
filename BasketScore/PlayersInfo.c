#include "PlayersInfo.h"
#include "VarInput.h"

// LOADP -----------------------------------
void loadPlayers(PtPlayersGrid _this) {
	char filename[20];

	printf("LOADP\n\tPlease enter the name of the file: ");
	readCharArray(filename, 20);

	importPlayersFromFile(filename, _this);
}


// SHOWP -----------------------------------

void showPlayers(PtPlayersGrid _this) {
	unsigned int option;

	printf("SHOWP\n\t1 - Sort [A-Z]\n\t2 - Sort [Z-A]\n\tOption> ");
	readInteger(&option);

	orderPlayersGrid(_this, option);
	printPlayersGrid(_this);

}


// TABLE -----------------------------------

unsigned int countPlayersSquad(PtPlayersGrid _this, unsigned int squadType, char gender) {
	unsigned int range, count = 0;

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

	printf("SEARCH\n\tName of the team?: ");

	readCharArray(team, 20);

	PlayersGrid temporaryPlayersGrid = createPlayersGrid(_this->capacity);

	for (unsigned int i = 0; i < _this->size; i++) {
		if (strcmp((&_this->players[i])->team, team) == 0) {
			teamExists = true;
			addPlayersGrid(&temporaryPlayersGrid,_this->players[i]);
		}
	}
	orderPlayersGrid(&temporaryPlayersGrid, 1);
	printPlayersGrid(&temporaryPlayersGrid);
	destroyPlayersGrid(&temporaryPlayersGrid);

	if (!teamExists) {
		printf("EQUIPA INEXISTENTE!");
	}

}




