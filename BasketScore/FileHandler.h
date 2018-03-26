#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Players.h"
#include "PlayersGrid.h"
#include "Statistics.h"
#include "StatisticsGrid.h"

void importPlayersFromFile(char* filename, PlayersGrid *grid);
void importGamesFromFile(char* filename, StatisticsGrid *grid);
char** split(char *str, int nFields, const char *delim);