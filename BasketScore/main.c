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

/*
* Descri��o do Programa
*/


int main(int argc, char** argv) {

	setlocale(LC_CTYPE, "Portuguese");
	/* declaracao de variaveis */
	char filename[20];
	PlayersGrid grid = createPlayersGrid(200);
	unsigned int option;

	//importPlayersFromFile("players_1.csv");

	/* interpretador de comandos */
	char command[21];
	int quit = 0;
	while (!quit) {



		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta t�cnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a sa�da do interpretador */
		}
		else if (equalsStringIgnoreCase(command, "LOADG")) {
			/* invoca��o da fun��o respons�vel pela respetiva
			funcionalidade. Remover printf seguinte ap�s implementa��o */
			printf("Comando LOADG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {
			
			printf("LOADP\n\tPlease enter the name of the file: ");
			fgets(filename, sizeof(filename), stdin);
			filename[strlen(filename) - 1] = '\0';

			importPlayersFromFile(filename, &grid);
			
		}
		else if (equalsStringIgnoreCase(command, "SHOWP")) {
			
			printf("SHOWP\n\t1 - Sort [A-Z]\n\t2 - Sort [Z-A]\n\tOption> ");
			scanf_s("%d", &option);
			getchar();

			switch (option) {
				case 1: 
					orderPlayersGridAsc(&grid);
				break;
				case 2:
					orderPlayersGridDesc(&grid);
				break;
			}

			printPlayersGrid(&grid);
		}
		else if (equalsStringIgnoreCase(command, "TABLE")) {
			printf("Comando TABLE nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SEARCH")) {
			printf("Comando SEARCH nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "STATG")) {
			printf("Comando STATG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SEARCHG")) {
			printf("Comando SEARCHG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "MVP")) {
			printf("Comando MVP nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "MFOULG")) {
			printf("Comando MFOULG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "MFOULP")) {
			printf("Comando FOULP nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "FAIRPLAY")) {
			printf("Comando FAIRPLAY nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "IDEALTEAM")) {
			printf("Comando IDEALTEAM nao implementado.\n");
		}
		else {
			printf("Comando n�o encontrado.\n");
		}
	}

	/* libertar mem�ria e apresentar mensagem de sa�da. */

	return (EXIT_SUCCESS);
}
