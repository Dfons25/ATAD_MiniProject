#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Games.h"
#include "Players.h"

int equalsStringIgnoreCase(char str1[], char str2[]);
void printCommandsMenu();
bool checkCommand(char command[], PtPlayersGrid players, PtStatisticsGrid games);
