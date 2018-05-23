#include "Commands.h"

void loadPlayers(PtList list) {
	char filename[20];

	printf("LOADP\n\tPlease enter the name of the file: ");
	readCharArray(filename, 20);

	importPlayersFromFile(filename, list);

}