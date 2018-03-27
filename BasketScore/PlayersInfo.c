#include "PlayersInfo.h"

void printTeamPlayers(PtPlayersGrid _this) {
	int count = 0;
	char team[20];

	printf("Introduza a equipa que deseja procurar: ");

	fgets(team, sizeof(team), stdin);
	team[strlen(team) - 1] = '\0';

	for (unsigned int i = 0; i < _this->size; i++) {
		if (strcmp((&_this->players[i])->team, team) == 0) {
			count++;
			printPlayer(&_this->players[i]);
		}
	}

	if (count == 0) {
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
	printf("=====================================\n");
	printf("| Escalão/  | Masculino  | Feminino |\n");
	printf("|  Genero   |            |          |\n");
	printf("|           |            |          |\n");
	printf("|  Sub %d   |     %d     |    %d    |\n", SQUAD_SUB14, countPlayersSquad(_this, SQUAD_SUB14, 'F'), countPlayersSquad(_this, SQUAD_SUB14, 'M'));
	printf("|  Sub %d   |     %d     |    %d    |\n", SQUAD_SUB16, countPlayersSquad(_this, SQUAD_SUB16, 'F'), countPlayersSquad(_this, SQUAD_SUB16, 'M'));
	printf("|  Sub %d   |     %d     |    %d    |\n", SQUAD_SUB18, countPlayersSquad(_this, SQUAD_SUB18, 'F'), countPlayersSquad(_this, SQUAD_SUB18, 'M'));
	printf("| %s  |     %d     |    %d    |\n", "Seniores", countPlayersSquad(_this, SQUAD_SENIOR, 'F'), countPlayersSquad(_this, SQUAD_SENIOR, 'M'));
	printf("=====================================\n");

}

/* ----------------------------------------------------------------------- */

