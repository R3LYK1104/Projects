#include "linkedList.h"
#include <stdio.h>
void initializeLL(struct linkedList* list) {
	list->size = 0;
	list->top = NULL;
}
void addItem(struct linkedList* list, int item) {
	struct node* newNode = malloc((struct node*)sizeof(struct node));
	newNode->data = item;
	if (list->top == NULL) { 
		newNode->next = NULL; 
		list->top = newNode; 
		list->size++; 
	}

	else {
		struct node* temp = list->top;
		newNode->next = temp;
		list->top = newNode;
		list->size++;

	}
}
void printList(struct linkedList* list) {
	if (list->top == NULL) printf("Empty Linked List...");
	else {
		printf("\nPrinting Linked List...\n%d", list->top->data);
		struct node* cur = list->top->next;
		while (cur!= NULL && cur->data != NULL) {
			printf(" %d", cur->data);
			cur = cur->next;
		}
	}
}
void printReverse(struct linkedList* list) {

	int* arrlist = (int*)malloc(sizeof(int) * list->size);
	struct node* cur = list->top;
	int c = 0;
	while (cur != NULL && cur->data != NULL) {
		arrlist[c] = cur->data;
		cur = cur->next;
		c++;
	}
	printf("\nPrinting Linked List in Reverse Order...\n");
	for (int i = list->size - 1; i >= 0; i--) {
		printf("%d ", arrlist[i]);
	}
}
int checkItem(struct linkedList* list, int item) {
	struct node* cur = list->top;
	while (cur != NULL && cur->data != NULL) {
		if (cur->data == item) return 1;
		cur = cur->next;
	}
	return 0;
}
void updateItem(struct linkedList* list, int position, int newVal) {
	if (list->size < position + 1) return 0;
	struct node* cur = list->top;
	for (int i = 0; i < position; i++) {
		cur = cur->next;
	}
	cur->data = newVal;
}
void deleteItem(struct linkedList* list, int item) {
	struct node* cur = list->top;
	struct node* prev = NULL;
	while (cur != NULL && cur->data != NULL) {
		if (cur->data == item) { prev->next = cur->next; free(cur); list->size--; return 1; };
		prev = cur;
		cur = cur->next;
	}
	printf("Item not found");
}
int getSize(struct linkedList* list) {
	return list->size;
}