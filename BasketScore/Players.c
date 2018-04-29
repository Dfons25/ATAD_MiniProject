#include "Players.h"

// PLAYER ------------------------------------

Player createPlayer(unsigned int id, char name[], char team[], Date birthDate, char gender)
{
	Player newPlayer;
	newPlayer.id = id;
	strcpy_s(newPlayer.name, sizeof(newPlayer.name), name);
	strcpy_s(newPlayer.team, sizeof(newPlayer.team), team);
	newPlayer.birthDate = birthDate;
	newPlayer.gender = gender;

	return newPlayer;
}

Date createDate(unsigned int day, unsigned int month, unsigned int year)
{
	Date newDate;
	newDate.day = day;
	newDate.month = month;
	newDate.year = year;

	return newDate;
}

void printPlayer(PtPlayer _this) {
	printf("\t%-7d : %-20s | %-12s | %02d/%02d/%04d | %c      |\n", 
		_this->id,
		_this->name,
		_this->team,
		_this->birthDate.day,
		_this->birthDate.month,
		_this->birthDate.year,
		_this->gender);
}

unsigned int getPlayerAge(PtPlayer _this) {
	time_t now = time(0);
	struct tm sysdate;

	localtime_s(&sysdate, &now);

	return (sysdate.tm_year + 1900) - _this->birthDate.year; // tm_year começa a contagem de anos a partir de 1900

};

unsigned int getPlayerAgeFull(PtPlayer _this) {
	time_t now = time(0);
	struct tm sysdate;

	localtime_s(&sysdate, &now);

	return _this->birthDate.year * 10000 + _this->birthDate.month * 100 + _this->birthDate.day; // tm_year começa a contagem de anos a partir de 1900

};

// PLAYER GRID ------------------------------------


PlayersGrid createPlayersGrid(unsigned int capacity)
{
	PlayersGrid newPlayersGrid;
	newPlayersGrid.players = (Player*)calloc(capacity, sizeof(Player));
	newPlayersGrid.size = 0;
	newPlayersGrid.capacity = capacity;
	return newPlayersGrid;
}

void addPlayersGrid(PtPlayersGrid _this, Player player)
{
	if (_this->size == _this->capacity) {
		_this->capacity += 2;
		_this->players = (Player*)realloc(_this->players, _this->capacity * sizeof(Player));
	}
	_this->players[_this->size] = player;
	_this->size++;
}

void resetPlayersGrid(PtPlayersGrid _this) {
	_this->size = 0;
}

void destroyPlayersGrid(PtPlayersGrid _this) {
	free(_this->players);
}

void printPlayersGrid(PtPlayersGrid _this) {
	printf("\n\tPlayer\t| Name                 | Team         | BirthDate  | Gender |");
	printf("\n\t========================================================================");
	for (unsigned int x = 0; x<_this->size; x++) {
		printPlayer(&_this->players[x]);
	}
};

void swapPlayer(Player *xp, Player *yp) {
	Player temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void orderPlayersGrid(PtPlayersGrid _this, unsigned int mode) {
	for (unsigned int x = 0; x < _this->size - 1; x++) {
		for (unsigned int y = 0; y < _this->size - x - 1; y++) {
			if (mode == 1) { // ASC
				if (strcmp(_this->players[y].name, _this->players[y + 1].name)>0) {
					swapPlayer(&_this->players[y], &_this->players[y + 1]);
				}
			} else { // DESC
				if (strcmp(_this->players[y].name, _this->players[y + 1].name)<0) {
					swapPlayer(&_this->players[y], &_this->players[y + 1]);
				}
			}
		}
	}
}

bool isPlayersEmpty(PtPlayersGrid _this) {
	if (_this->size > 0) {
		return false;
	} else {
		return true;
	}
};

