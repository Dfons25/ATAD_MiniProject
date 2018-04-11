/* MINI-PROJETO 1 ATAD 2018
* Identificacao dos Alunos:
*
*      Numero: 170221070 | Nome: Daniel Barreiro
*      Numero: ######### | Nome: David Afonso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Bibliotecas Costumizadas
#include "UserInterface.h"
#include "Players.h"
#include "Games.h"

/*
* Descrição do Programa
*/

int main(int argc, char** argv) {

	setlocale(LC_CTYPE, "Portuguese");
	/* declaracao de variaveis */
	PlayersGrid playersGrid = createPlayersGrid(200);
	StatisticsGrid statisticsGrid = createStatisticsGrid(200);

	/* interpretador de comandos */
	char command[21];
	int quit = 0;
	while (!quit) {
		
		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		importPlayersFromFile("players_1.csv", &playersGrid);
		importGamesFromFile("games_1.csv", &statisticsGrid);

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */
		}
		else if (equalsStringIgnoreCase(command, "LOADG")) {
			loadGames(&statisticsGrid);
		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {		
			loadPlayers(&playersGrid);	
		}
		else if (equalsStringIgnoreCase(command, "SHOWP")) {
			showPlayers(&playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "TABLE")) {
			printSquadTable(&playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "SEARCH")) {
			printTeamPlayers(&playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "STATG")) {
			printf("Comando STATG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SEARCHG")) {
			printGameGrid(&statisticsGrid);
		}
		else if (equalsStringIgnoreCase(command, "MVP")) {
			printGameMVP(&statisticsGrid);
		}
		else if (equalsStringIgnoreCase(command, "MFOULG")) {
			printPlayerFoulsPerGame(&statisticsGrid);
		}
		else if (equalsStringIgnoreCase(command, "MFOULP")) {
			printStatisticsFouls(&statisticsGrid, &playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "FAIRPLAY")) {
			printFairPlayStatistic(&statisticsGrid, &playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "IDEALTEAM")) {
			getIdealTeam(&statisticsGrid, &playersGrid);
		}
		else {
			printf("Comando não encontrado.\n");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}
