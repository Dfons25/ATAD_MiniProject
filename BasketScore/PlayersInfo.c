
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FileHandler.h"

#define PLAYERS_FILE_TYPE "players_"

void loadp() {

	char filename[20];

	// Pedir nome do ficheiro
	printf("Introduza o nome do ficheiro a carregar: ");
	scanf_s("%s", filename, sizeof(filename));


	// Verifica se o nome do ficheiro é do tipo jogadores
	if (strstr(filename, PLAYERS_FILE_TYPE) == NULL) {
		printf("FICHEIRO INCORRETO!");
	} else {
		importPlayersFromFile(filename);
	}
}