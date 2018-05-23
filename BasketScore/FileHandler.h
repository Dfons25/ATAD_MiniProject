#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "Players.h"
#include "Games.h"

void importPlayersFromFile(char* filename, PtList list);
void importGamesFromFile(char* filename, StatisticsGrid *grid);
char** split(char *str, int nFields, const char *delim);