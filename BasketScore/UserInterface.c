#pragma once


#include "UserInterface.h"

int equalsStringIgnoreCase(char str1[], char str2[]) {
	return (_strcmpi(str1, str2) == 0);
}

bool checkCommand(char command[], PtPlayersGrid players, PtStatisticsGrid games) {
	if (equalsStringIgnoreCase(command, "SHOWP")) {
		if (isPlayersEmpty(players)) {	return false; }
	} else if (equalsStringIgnoreCase(command, "TABLE")) {
		if (isPlayersEmpty(players)) { return false; }
	} else if (equalsStringIgnoreCase(command, "SEARCH")) {
		if (isPlayersEmpty(players)) { return false; }
	} else if (equalsStringIgnoreCase(command, "SEARCHG")) {
		if (isGamesEmpty(games)) { return false; }
	} else if (equalsStringIgnoreCase(command, "MVP")) {
		if (isGamesEmpty(games)) { return false; }
	} else if (equalsStringIgnoreCase(command, "MFOULG")) {
		if (isGamesEmpty(games)) { return false; }
	} else if (equalsStringIgnoreCase(command, "MFOULP")) {
		if (isPlayersEmpty(players) && isGamesEmpty(games)) { return false; }
	} else if (equalsStringIgnoreCase(command, "FAIRPLAY")) {
		if (isPlayersEmpty(players) && isGamesEmpty(games)) { return false; }
	} else if (equalsStringIgnoreCase(command, "IDEALTEAM")) {
		if (isPlayersEmpty(players) && isGamesEmpty(games)) { return false; }
	} else {
		return true;
	}

	return true;
}


void printCommandsMenu() {
	printf("\n================================================================================");
	printf("\n                          MINI-PROJECT: Basket Scores                              ");
	printf("\n================================================================================");
	printf("\nA. Info about players (LOADP, SHOWP, TABLE, SEARCH).");
	printf("\nB. Specific info about players' performance during the games (LOADG, SEARCHG, MVP).");
	printf("\nC. Aggregated info about games and players (MFOULP, MFOULG, FAIRPLAY).");
	printf("\nD. Advanced indicator (IDEALTEAM)");
	printf("\nE. Exit (QUIT)\n\n");
	printf("COMMAND> ");
}