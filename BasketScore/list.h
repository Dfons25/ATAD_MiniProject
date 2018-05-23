#pragma once

#define LIST_OK				0
#define LIST_NULL			1
#define LIST_NO_MEMORY		2
#define LIST_EMPTY			3
#define LIST_FULL			4
#define LIST_INVALID_RANK	5

#include "listElem.h"

struct listImpl;
typedef struct listImpl *PtList;

PtList createList(unsigned int initialCapacity);
int listDestroy(PtList *ptList);
int listAdd(PtList list, int rank, listElem elem);
int listRemove(PtList list, int rank, listElem *ptElem, listElem *ptRemovedElem);
int listGet(PtList list, int rank, listElem *ptElem);
int listSet(PtList list, int rank, listElem elem, listElem *ptOldElem);

int listSize(PtList list, int *ptSize);
int listIsEmpty(PtList list);
int listClear(PtList list);
void listPrint(PtList list);

