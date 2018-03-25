#include "filehandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void importPlayersFromFile(PlayersGrid *grid) {
	FILE *fd;
	char filename[20];
	printf("\tPlease enter the name of the file: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strlen(filename) - 1] = '\0';

	int err = fopen_s(&fd, filename, "r");

	if (err != 0) {
		printf("Não foi possivel abrir o ficheiro %s ...\n", filename);
		return;
	}

	printf("\tThe file %s was opened", filename);

	char nextline[1024];
	int countPlayers = 0;

	while (fgets(nextline, sizeof(nextline), fd)) {
		if (strlen(nextline) < 1)
			continue;

		char **tokens = split(nextline, 5, ";");
		int day, month, year;
		sscanf_s(tokens[3], "%d/%d/%d", &day, &month, &year);

		Player newPlayer = playerCreate(atoi(tokens[0]), tokens[1], tokens[2], dateCreate(day, month, year), tokens[4][0]);
		playersGridAddPlayer(grid, newPlayer);

		free(tokens);
		countPlayers++;
	}
	printf("\n\t%d players were imported", countPlayers);
	getch();
	fclose(fd);
}


char** split(char *str, int nFields, const char *delim) {
	char **tokens = malloc(sizeof(char*) * nFields);

	int index = 0;
	char *next_token = NULL;

	char *token = strtok_s(str, delim, &next_token);
	while (token) {
		tokens[index++] = token;
		token = strtok_s(NULL, delim, &next_token);
	}
	return tokens;
}