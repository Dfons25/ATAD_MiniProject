#include "players.h"

Player playerCreate(unsigned int id, char name[], char team[], Date birthDate, char gender)
{
	Player newPlayer;
	newPlayer.id = id;
	strcpy(newPlayer.name, name);
	strcpy(newPlayer.team, team);
	newPlayer.birthDate = birthDate;
	newPlayer.gender = gender;

	return newPlayer;
}

Date dateCreate(unsigned int day, unsigned int month, unsigned int year)
{
	Date newDate;
	newDate.day = day;
	newDate.month = month;
	newDate.year = year;

	return newDate;
}

void playerPrint(PtPlayer _this) {
	printf("Jogador %3d : %-20s | %-10s | %02d/%02d/%04d | %c \n", _this->id, _this->name, _this->team, _this->birthDate.day, _this->birthDate.month, _this->birthDate.year, _this->gender);
}

PlayersGrid playersGridCreate(unsigned int capacity)
{
	PlayersGrid newplayerGrid;
	newplayerGrid.players = (Player*)calloc(capacity, sizeof(Player));
	newplayerGrid.size = 0;
	newplayerGrid.capacity = capacity;
	return newplayerGrid;
}

void playersGridAddPlayer(PtPlayersGrid _this, Player player)
{
	if (_this->size == _this->capacity) {
		_this->capacity += 2;
		_this->players = (Player*)realloc(_this->players, _this->capacity * sizeof(Player));
	}
	_this->players[_this->size] = player;
	_this->size++;
}

void playersGridPrint(PtPlayersGrid _this) {
	for (int i = 0; i<_this->size; i++) {
		playerPrint(&_this->players[i]);
	}
};