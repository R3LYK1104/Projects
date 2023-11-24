#pragma once
struct node {
	int data;
	struct node* next;
};
struct linkedList {
	int size;
	struct node* top;
};
void initializeLL(struct linkedList* list);
void addItem(struct linkedList* list, int item);
void printList(struct linkedList* list);
void printReverse(struct linkedList* list);
int checkItem(struct linkedList* list, int item);
void updateItem(struct linkedList* list, int position, int newVal);
void deleteItem(struct linkedList* list, int item);
