#include "listElem.h"
#include <stdio.h>

void printListElem(listElem elem) {
	printf("\t%-7d : %-20s | %-12s | %02d/%02d/%04d | %c |\n",
		elem.id,
		elem.name,
		elem.team,
		elem.birthDate.day,
		elem.birthDate.month,
		elem.birthDate.year,
		elem.gender);
}
