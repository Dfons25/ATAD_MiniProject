/* MINI-PROJETO 1 ATAD 2018
* Identificacao dos Alunos:
*
*      Numero: 170221079 | Nome: Daniel Barreiro
*      Numero: 170221081 | Nome: David Afonso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Bibliotecas Costumizadas
#include "UserInterface.h"
#include "AdvanceIndicators.h"
#include "PlayersPerformanceInfo.h"
#include "Players.h"
#include "PlayersInfo.h"
#include "GamesInfo.h"
#include "Games.h"
#include "VarInput.h"

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
		readCharArray(command, 21);

		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */

		if (checkCommand(command, &playersGrid, &statisticsGrid)) {
			if (equalsStringIgnoreCase(command, "QUIT")) {
				quit = 1; /* vai provocar a saída do interpretador */
			} else if (equalsStringIgnoreCase(command, "LOADG")) {
				loadGames(&statisticsGrid);
			} else if (equalsStringIgnoreCase(command, "LOADP")) {
				loadPlayers(&playersGrid);
			} else if (equalsStringIgnoreCase(command, "SHOWP")) {
				showPlayers(&playersGrid);
			} else if (equalsStringIgnoreCase(command, "TABLE")) {
				printSquadTable(&playersGrid);
			} else if (equalsStringIgnoreCase(command, "SEARCH")) {
				printTeamPlayers(&playersGrid);
			} else if (equalsStringIgnoreCase(command, "SEARCHG")) {
				printGameGrid(&statisticsGrid);
			} else if (equalsStringIgnoreCase(command, "MVP")) {
				printGameMVP(&statisticsGrid);
			} else if (equalsStringIgnoreCase(command, "MFOULG")) {
				printPlayerFoulsPerGame(&statisticsGrid);
			} else if (equalsStringIgnoreCase(command, "MFOULP")) {
				printStatisticsFouls(&statisticsGrid, &playersGrid);
			} else if (equalsStringIgnoreCase(command, "FAIRPLAY")) {
				printFairPlayStatistic(&statisticsGrid, &playersGrid);
			} else if (equalsStringIgnoreCase(command, "IDEALTEAM")) {
				getIdealTeam(&statisticsGrid, &playersGrid);
			} else {
				printf("Comando não encontrado.\n");
			}
		} else {
			printf("\n\tNAO EXISTE INFORMAÇÂO");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}
