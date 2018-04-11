#pragma once

#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "Players.h"
#include "FileHandler.h"
#include "UserInterface.h"


#define SQUAD_SUB14 14
#define SQUAD_SUB16 16
#define SQUAD_SUB18 18
#define SQUAD_SENIOR 99


// LOADP -----------------------------------

void loadPlayers(PtPlayersGrid _this);

// SHOWP -----------------------------------

void showPlayers(PtPlayersGrid _this);

// TABLE -----------------------------------

void printSquadTable(PtPlayersGrid _this);
unsigned int countPlayersSquad(PtPlayersGrid _this, int squadType, char gender);

// SEARCH ----------------------------------

void printTeamPlayers(PtPlayersGrid _this);

