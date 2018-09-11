#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chain.h"

chain* chainCreate(int x) {
	chain* command = malloc(sizeof(chain));
	command->count = 0;
	command->background = x;
	command->parsed = 0;
	command->piped = 0;
	command->firstpiped = 0;

	command->fileIn = NULL;
	command->fileOut = NULL;
	command->fileOutMode = 0;
	command->fileErrorOut = NULL;
	command->fileErrorStdout = 0;

	command->start = NULL;
	command->end = NULL;

	return command;
}

void chainReset(chain* command) {
	if (command == NULL) return;

	ll* current = command->start;
	ll* prev = NULL;

	while (current != NULL) {
		prev = current;
		current = current->next;

		llFree(prev);
	}

	command->count = 0;
	command->background = 0;
	command->parsed = 0;
	command->piped = 0;
	command->firstpiped = 0;
	command->fileIn = NULL;
	command->fileOut = NULL;
	command->fileOutMode = 0;
	command->fileErrorOut = NULL;
	command->fileErrorStdout = 0;
	command->start = NULL;
	command->end = NULL;
}

void chainPush(chain* command, ll* list) {
	if (command == NULL || list == NULL) return;

	if (command->start == NULL) {
		// no items in chain
		command->start = list;
		command->end = list;
	}
	else {
		list->next = NULL;
		command->end->next = list;
		command->end = list;
	}

	command->count++;
}

// Remove from front
ll* chainPop(chain* command) {
	if (command == NULL || command->start == NULL) return NULL;

	// current and prev node
	ll* current = command->start;
	ll* next = command->start->next;

	if (next == NULL) {
		// current is an only child
		command->start = NULL;
		command->end = NULL;
	}
	else {
		command->start = next;
	}

	command->count--;
	return current;
}

void chainPrint(chain* command) {
	if (command == NULL || command->start == NULL) {
		printf("No items found. \n");
		return;
	}

	printf("Number of ll in command: %d \n", command->count);
	if (command->fileIn != NULL) printf("Input from %s \n", command->fileIn);
	if (command->fileOut != NULL) printf("Output to %s \n", command->fileOut);
	if (command->fileErrorOut != NULL) printf("Error to %s \n", command->fileErrorOut);
	if (command->background == 1) printf("Process in background \n");

	// current node
	ll* current = command->start;

	// print nodes
	int index = 0;
	
	while (current != NULL) {
		index++;
		llPrint(current);
		current = current->next;
	}
}

