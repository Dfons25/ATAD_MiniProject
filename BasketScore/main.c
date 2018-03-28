/* MINI-PROJETO 1 ATAD 2018
* Identificacao dos Alunos:
*
*      Numero: ######### | Nome: ###############################
*      Numero: ######### | Nome: ###############################
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Bibliotecas Costumizadas
#include "UserInterface.h"
#include "FileHandler.h"
#include "Players.h"
#include "PlayersGrid.h"
#include "PlayersInfo.h"

/*
* Descrição do Programa
*/


int main(int argc, char** argv) {

	setlocale(LC_CTYPE, "Portuguese");
	/* declaracao de variaveis */
	char filename[20];
	PlayersGrid playersGrid = createPlayersGrid(200);
	StatisticsGrid statisticsGrid = createStatisticsGrid(200);
	unsigned int option;

	//importPlayersFromFile("players_1.csv");

	/* interpretador de comandos */
	char command[21];
	int quit = 0;
	while (!quit) {



		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */
		}
		else if (equalsStringIgnoreCase(command, "LOADG")) {

			printf("LOADP\n\tPlease enter the name of the file: ");
			fgets(filename, sizeof(filename), stdin);
			filename[strlen(filename) - 1] = '\0';

			importGamesFromFile(filename, &statisticsGrid);

		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {
			
			printf("LOADP\n\tPlease enter the name of the file: ");
			fgets(filename, sizeof(filename), stdin);
			filename[strlen(filename) - 1] = '\0';

			importPlayersFromFile(filename, &playersGrid);
			
		}
		else if (equalsStringIgnoreCase(command, "SHOWP")) {
			
			printf("SHOWP\n\t1 - Sort [A-Z]\n\t2 - Sort [Z-A]\n\tOption> ");
			scanf_s("%d", &option);
			getchar();

			switch (option) {
				case 1: 
					orderPlayersGridAsc(&playersGrid);
				break;
				case 2:
					orderPlayersGridDesc(&playersGrid);
				break;
			}

			printPlayersGrid(&playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "TABLE")) {
			drawSquadTable(&playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "SEARCH")) {
			printTeamPlayers(&playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "STATG")) {
			printf("Comando STATG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SEARCHG")) {

			printf("SEARCHG\n\tID of the game?> ");
			scanf_s("%d", &option);
			getchar();

			printGameGrid(&statisticsGrid, option);
		}
		else if (equalsStringIgnoreCase(command, "MVP")) {

			printf("MVP\n\tID of the game?> ");
			scanf_s("%d", &option);
			getchar();

			printGameMVP(&statisticsGrid, option);
		}
		else if (equalsStringIgnoreCase(command, "MFOULG")) {
			printPlayerFoulsPerGame(&statisticsGrid);
		}
		else if (equalsStringIgnoreCase(command, "MFOULP")) {
			printStatisticsFouls(&statisticsGrid, &playersGrid);
		}
		else if (equalsStringIgnoreCase(command, "FAIRPLAY")) {
			importPlayersFromFile("players_1.csv", &playersGrid);
			importGamesFromFile("games_1.csv", &statisticsGrid);
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
