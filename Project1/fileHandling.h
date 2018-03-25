#pragma once
#include "players.h"

void importPlayersFromFile(PlayersGrid *grid);
char** split(char *str, int nFields, const char *delim);