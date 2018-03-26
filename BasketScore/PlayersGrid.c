#include "PlayersGrid.h"

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

void printPlayersGrid(PtPlayersGrid _this) {
	for (unsigned int x = 0; x<_this->size; x++) {
		printPlayer(&_this->players[x]);
	}
};

void orderPlayersGridAsc(PtPlayersGrid _this) {
	for (unsigned int x = 0; x < _this->size - 1; x++)
	{
		for (unsigned int y = 0; y < _this->size - x - 1; y++)
		{
			if (strcmp(_this->players[y].name ,_this->players[y + 1].name)>0)
			{
				swap(&_this->players[y], &_this->players[y + 1]);
			}
		}
	}
}

void orderPlayersGridDesc(PtPlayersGrid _this) {
	for (unsigned int x = 0; x < _this->size - 1; x++)
	{
		for (unsigned int y = 0; y < _this->size - x - 1; y++)
		{
			if (strcmp(_this->players[y].name, _this->players[y + 1].name)<0)
			{
				swap(&_this->players[y], &_this->players[y + 1]);
			}
		}
	}
}

void swap(Player *xp, Player *yp)
{
	Player temp = *xp;
	*xp = *yp;
	*yp = temp;
}