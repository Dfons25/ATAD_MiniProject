#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Players.h"
#include "PlayersGrid.h"

void importPlayersFromFile(char* filename, PlayersGrid *grid);
char** split(char *str, int nFields, const char *delim);