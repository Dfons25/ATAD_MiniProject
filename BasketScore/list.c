#include "list.h"
#include <stdlib.h>

typedef struct listImpl {
	listElem *elements;
	unsigned int size;
	unsigned int capacity;
} ListImpl;


PtList createList(unsigned int initialCapacity) {
	PtList newList = (PtList)malloc(initialCapacity, sizeof(PtList));
	if (newList == NULL) return LIST_NULL;

	newList->elements = (listElem*)malloc(initialCapacity, sizeof(listElem));
	if (newList->elements == NULL) return LIST_NULL;

	newList->capacity = initialCapacity;
	newList->size = 0;

	return newList;
};


int listDestroy(PtList *ptList) {
	PtList tempList = *ptList;
	if (tempList == NULL) return LIST_NULL;

	free(tempList->elements);
	free(tempList);

	*ptList = NULL;

	return LIST_OK;
};

int listAdd(PtList list, int rank, listElem elem) {
	if (list == NULL) return LIST_NULL;
	if (list->size == list->capacity) return LIST_FULL;
	if (rank < 0 || rank > list->size) return LIST_INVALID_RANK;

	for (int i = list->size - 1; i >= rank; i--) {
		list->elements[i + 1] = list->elements[i];
	}
	list->elements[rank] = elem;
	list->size++;

	return LIST_OK;

};

int listRemove(PtList list, int rank, listElem *ptElem, listElem *ptRemovedElem) {
	if (list == NULL) return LIST_NULL;
	if (list->size == 0) return LIST_EMPTY;
	if (rank < 0 || rank > list->size) return LIST_INVALID_RANK;

	for (int i = rank; i < list->size - 1; i++) {
		list->elements[i] = list->elements[i + 1];
	}

	list->size--;

	return LIST_OK;
};

int listGet(PtList list, int rank, listElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	if (list->size == 0) return LIST_EMPTY;
	if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

	(*ptElem) = list->elements[rank];

	return LIST_OK;

};
int listSet(PtList list, int rank, listElem elem, listElem *ptOldElem) {
	if (list == NULL) return LIST_NULL;
	if (list->size == list->capacity) return LIST_FULL;
	if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

	(*ptOldElem) = list->elements[rank];

	list->elements[rank] = elem;

	return LIST_OK;
};

int listSize(PtList list, int *ptSize) {
	if (list == NULL) return LIST_NULL;
	(*ptSize) = list->size;

	return LIST_OK;
};
int listIsEmpty(PtList list) {
	if (list == NULL) return 1;
	return (list->size == 0) ? 1 : 0;
};
int listClear(PtList list) {
	if (list == NULL) return LIST_NULL;

	list->size = 0;

	return LIST_OK;

};
void listPrint(PtList list) {
	if (list == NULL) {
		printf("LIST NULL!\n");
	} else if (listIsEmpty(list)) {
		printf("LIST EMPTY!\n");
	} else {
		for (int i = 0; i < list->size; i++) {
			printListElem(list->elements[i]);
		}
	};

};