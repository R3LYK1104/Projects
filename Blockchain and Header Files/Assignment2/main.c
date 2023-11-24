#include <stdio.h>
#include "hash.h"
#include "linkedList.h"
#include "blockchain.h"
int main(void) {
    //start of hash testing 
   /* struct Digest* first;
    struct Digest* second;
    struct Digest* third;
    struct Digest* fourth;
    struct Digest* fifth;
    first = (struct Digest*)SHA_40("Rob", 3);
    second = (struct Digest*)SHA_40("James", 5);
    third = (struct Digest*)SHA_40("Ahmed", 5);
    fourth = (struct Digest*)SHA_40("CSEC", 4);
    fifth = (struct Digest*)SHA_40("Kyler", 5);
    printDigest(first);
    printDigest(second);
    printDigest(third);
    printDigest(fourth);
    printDigest(fifth);
    printf("Rob = Rob?: %d\n", digestEqual(first, first));
    printf("Ahmed = James?: %d\n", digestEqual(third, fourth));*/
   //end
   //start of LL testing
    //struct linkedList* list = malloc(sizeof(struct linkedList*));
    //initializeLL(list);
   
    //addItem(list, 10);
    //addItem(list, 20);
    //addItem(list, 30);
    //printList(list);
    //printReverse(list);
    //printf("\nsize of list: %d", getSize(list));
    //addItem(list, 30); //30 twice?
    //addItem(list, 40);
    //addItem(list, 50);
    //addItem(list, 60);
    //updateItem(list, 5, 70);
    //printList(list);
    //deleteItem(list, 10);
    //printList(list);
    //deleteItem(list, 50);
    //printList(list);
    //deleteItem(list, 60);
    //printList(list);
    //deleteItem(list, 30);
    //printList(list);
    //int num = checkItem(list, 15);
    //printf("\n%d\n", num);
    //updateItem(list, 2, 69);
    //printList(list);
    //deleteItem(list, 20);
    //printList(list);
    testBlockChain();
}