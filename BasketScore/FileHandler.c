
#include "FileHandler.h"

char** split(char *str, int nFields, const char *delim) {

	char **tokens = malloc(sizeof(char*) * nFields);

	int index = 0;
	char *next_token = NULL; // para controlo interno da funcção strtok_s

	char *token = strtok_s(str, delim, &next_token);
	while (token) {
		//puts(token)
		tokens[index++] = token;
		token = strtok_s(NULL, delim, &next_token);
	}

	if (index != nFields) {
		return NULL;
	}

	return tokens;

	
}


void importPlayersFromFile(char* filename, PtList list) {
	FILE *fd;
	
	int err = fopen_s(&fd, filename, "r");
	

	if (err != 0) {
		printf("Não foi possivel abrir o ficheiro %s ...\n", filename);
		return;
	}

	printf("\tThe file %s was opened", filename);

	if (listIsEmpty(list) != 1) {
		listClear(list);
	}

	char nextline[1024];
	int countPlayers = 0;

	while (fgets(nextline, sizeof(nextline), fd)) {
		if (strlen(nextline) < 1)
			continue;

		char **tokens = split(nextline, 5, ";");

		if (tokens == NULL && countPlayers == 0) {
			printf("\n\tFICHEIRO INVALIDO");
			return;
		}

		int playerId = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[3], "%d/%d/%d", &day, &month, &year);

		Player newPlayer = createPlayer(playerId, tokens[1], tokens[2], createDate(day, month, year), tokens[4][0]);
		listAdd(list, 0, newPlayer);

		free(tokens);
		countPlayers++;
	}
	printf("\n\t%d players were imported", countPlayers);
	fclose(fd);

}


void importGamesFromFile(char* filename, StatisticsGrid *grid) {
	FILE *fd;
	int err = fopen_s(&fd, filename, "r");
	

	if (err != 0) {
		printf("Não foi possivel abrir o ficheiro %s ...\n", filename);
		return;
	}

	printf("\tThe file %s was opened", filename);
	resetStatisticsGrid(grid);

	char nextline[1024];
	int countGames = 0;

	while (fgets(nextline, sizeof(nextline), fd)) {
		if (strlen(nextline) < 1)
			continue;

		char **tokens = split(nextline, 7, ";");

		if (tokens == NULL && countGames == 0) {
			printf("\n\tFICHEIRO INVALIDO");
			return;
		}

		Statistics newStatistic = createStatistics(atoi(tokens[2]), atoi(tokens[3]), atoi(tokens[4]), atoi(tokens[5]), atoi(tokens[6]));
		PlayerGameStatistics newPlayerGameStatistics = createPlayerGameStatistics(atoi(tokens[0]), atoi(tokens[1]), newStatistic);

		addStatisticsGrid(grid, newPlayerGameStatistics);

		free(tokens);
		countGames++;
	}
	printf("\n\t%d games were imported", countGames);
	fclose(fd);

}
