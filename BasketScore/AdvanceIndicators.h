#pragma once

#include <stdbool.h>
#include "Games.h"
#include "Players.h"

// IDEALTEAM --------------------------------

void getIdealTeam(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid);
int getIdealPlayer(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid, unsigned int squadType, int position, char gender, int exceptions[]);
bool checkIfInTeam(int playerId, int exceptions[]);