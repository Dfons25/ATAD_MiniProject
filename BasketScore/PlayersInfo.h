#pragma once

#include <time.h>
#include <string.h>

#include "Players.h"
#include "PlayersGrid.h"


#define SQUAD_SUB14 14
#define SQUAD_SUB16 16
#define SQUAD_SUB18 18
#define SQUAD_SENIOR 99


unsigned int countPlayersSquad(PtPlayersGrid _this, int squadType, char gender);

unsigned int getPlayerAge(PtPlayer _this);

void drawSquadTable(PtPlayersGrid _this);

void printTeamPlayers(PtPlayersGrid _this);
