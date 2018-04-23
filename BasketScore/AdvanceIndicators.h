#pragma once

#include <stdbool.h>
#include "Games.h"
#include "Players.h"

// IDEALTEAM --------------------------------

void getIdealTeam(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid);
int getIdealPlayer(PtStatisticsGrid ptStatisticsGrid, PtPlayersGrid ptPlayersGrid, int position, unsigned int squadType, char gender, int exceptions[]);
bool checkIfInTeam(int playerId, int exceptions[]);