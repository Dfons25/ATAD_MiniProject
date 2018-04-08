#include "Players.h"

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
	printf("Jogador %3d : %-20s | %-12s | %02d/%02d/%04d | %c \n", _this->id, _this->name, _this->team, _this->birthDate.day, _this->birthDate.month, _this->birthDate.year, _this->gender);
}