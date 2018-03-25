void printCommandsMenu() {
	printf("\n====================================================================================");
	printf("\n                           MINI-PROJECT: Basket Scores                              ");
	printf("\n====================================================================================");
	printf("\nA. Info about players (LOADP, SHOWP, TABLE, SEARCH).");
	printf("\nB. Specific info about players' performance during the games (LOADG, SEARCHG, MVP).");
	printf("\nC. Aggregated info about games and players (MFOULP, MFOULG, FAIRPLAY).");
	printf("\nD. Advanced indicator (IDEALTEAM)");
	printf("\nE. Exit (QUIT)\n\n");
	printf("COMMAND> ");
}

int equalsStringIgnoreCase(char str1[], char str2[]) {
	return (_strcmpi(str1, str2) == 0);
}