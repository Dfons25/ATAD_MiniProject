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


// Bibliotecas Costumizadas
#include "UserInterface.h"
#include "PlayersInfo.h"

/*
* Descrição do Programa
*/
int main(int argc, char** argv) {

	/* declaracao de variaveis */

	//importPlayersFromFile("players_1.csv");

	/* interpretador de comandos */
	char command[21];
	int quit = 0;
	while (!quit) {

		// Limpar a variável do comando
		memset(command, 0, sizeof(command));

		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */
		}
		else if (equalsStringIgnoreCase(command, "LOADG")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			printf("Comando LOADG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {
			loadp();
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
			printf("Comando nao encontrado.\n");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}
