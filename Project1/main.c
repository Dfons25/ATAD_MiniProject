#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<windows.h>

#include "players.h"
#include "printSource.h"
#include "players.h"

int main()
{
	setlocale(LC_CTYPE, "Portuguese");
	system("mode 84");

	//Passagem de ficheiro para a estrutura
	/*PlayersGrid grid = playersGridCreate(200);
	importPlayersFromFile("players_1.csv", &grid);
	playersGridPrint(&grid);*/

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
			printf("Comando LOADP nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {
			PlayersGrid grid = playersGridCreate(200);
			importPlayersFromFile(&grid);
		}
		else if (equalsStringIgnoreCase(command, "SHOWP")) {
			printf("Comando SHOWP nao implementado.\n");
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
			printf("Comando não encontrado.\n");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);

	system("pause");
	return 0;
}

