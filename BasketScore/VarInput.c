#include "VarInput.h"

void readInteger(int *ptVal){
	char line[20];
	fgets(line, sizeof(line), stdin);
	(*ptVal) = atoi(line);
}

void readCharArray(char *charArr, unsigned int maxChars) {
	fgets(charArr, maxChars, stdin);
	unsigned int len = strlen(charArr);
	if (len > 0 && charArr[len - 1] == '\n') {
		charArr[len - 1] = '\0';
	}
}