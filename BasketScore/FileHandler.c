#include <stdlib.h>
#include <stdio.h>

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

	return tokens;

	
}

void importPlayersFromFile(char* filename) {
	FILE *fd;
	int err = fopen_s(&fd, filename, "r");

	if (err != 0) {
		printf("Nao foi possivel abrir o ficheiro %s ... \n", filename);
		return;
	}

	char nextline[1024];

	//contagem de jogadores lidos
	int countPlayers = 0;

	while (fgets(nextline, sizeof(nextline), fd)) {
		if (strlen(nextline) < 1)
			continue;
		
		char **tokens = split(nextline, 5, ";");
		// o array neste momento contém as seguintes "strings"
		// tokens[0] - id
		// tokens[1] - nome
		// tokens[2] - clube
		// tokens[3] - data de nascimento
		// tokens[4] - genero

		int playerId = atoi(tokens[0]);
		int day, month, year;

		sscanf_s(tokens[3], "%d/%d/%d", &day, &month, &year);
		
		char playerGender = tokens[4][0]; // primeiro caracter de tokens[4]

		printf("Jogador %3d : %-20s | %-10s | %02d/%02d/%04d | %c \n",
			playerId, tokens[1], tokens[2], day, month, year, playerGender);

		free(tokens); // memória alocada na função 'split' tem de ser libertada
		countPlayers++;
	}

	printf("\n\nForam lidos %d jogadores... \n", countPlayers);
	fclose(fd);

}