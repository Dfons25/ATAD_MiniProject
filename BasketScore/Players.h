#pragma once
#pragma once

typedef struct date {
	int day, month, year;
} Date;

typedef struct player {
	int id;
	char name[50];
	char team[50];
	Date birthDate;
	char gender;
} Player;


