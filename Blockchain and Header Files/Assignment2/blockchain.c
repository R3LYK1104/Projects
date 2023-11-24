/*
 * CSEC-201
 * Authors: CSEC-201 Instructors
 * Semester: 2221
 * Purpose: Blockchain implementation
 */

#include "blockchain.h"

 /*
  * Name: initialize
  * Purpose: Creates and returns a pointer to an empty blockchain
  * Parameters: None
  * Returns: pointer to Blockchain
  */
struct Blockchain* initialize()
{
    struct Blockchain* chain = (struct Blockchain*)malloc(sizeof(struct Blockchain));
    chain->size = 0;
    chain->head = NULL;
    return chain;
}

/*
 * Name: print_blockchain
 * Purpose: Prints blockchain
 * Parameters: Pointer to Blockchain
 * Returns: None
 */
void print_blockchain(struct Blockchain* blockchain)
{
    printf("Printing...\n");
    struct Block* current = blockchain->head;
    while (current) {
        printf("{height: %d, data: %d, prev_hash: %d %d %d %d %d}\n",
            current->height, current->data, current->prev_hash.hash0, current->prev_hash.hash1,
            current->prev_hash.hash2, current->prev_hash.hash3, current->prev_hash.hash4);
        current = current->prev_block;
    }
}

void set_digest(struct Digest* digest, struct Block* block) {
    struct Digest* hash = (unsigned char*)SHA_40((unsigned char*)block, sizeof(struct Block));
    *digest = *hash;
}

void verify(struct Blockchain* chain) {
    struct Block* cur = chain->head;
    while (cur != NULL && cur->prev_block != NULL) {
        printf("verifying block %d\n", cur->height-1);
        struct Digest* hash = (struct Digest*)SHA_40((unsigned char*)cur->prev_block, sizeof(struct Block));
        printDigest(hash);
        if (digestEqual(&cur->prev_hash, hash) == 0) { printf("\nVerification of block %d failed\n", cur->height - 1); return 0; };
        cur = cur->prev_block;
        //free(hash);
    }   
    printf("\nblockchain verification successful\n");
    return 1;
}
void delete_at(struct Blockchain* chain, int height) {
    struct Block* cur = chain->head;
    for (int i = 0; i < chain->size; i++) {
        if (cur->height == height) {
            cur->prev_block = cur->prev_block->prev_block;
            chain->size--;
        }
        cur->height--;
        cur = cur->prev_block;
    }  
}
void add(struct Blockchain* chain, int data) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->data = data;
    newBlock->height = chain->size;
    if (chain->head == NULL || chain->size == 0) { 
        struct Digest none = { 0 };
        newBlock->prev_hash = none;
        newBlock->prev_block = NULL;  
        chain->head = newBlock; 
    }
    else {
        struct Block* tmp = chain->head;
        newBlock->prev_block = tmp;
        set_digest(&newBlock->prev_hash, tmp);
        chain->head = newBlock;
    }
    chain->size++;
}
void alter_block(struct Blockchain* chain, int height, int data) {
    struct Block* cur = chain->head;
    for (int i = 0; i < chain->size; i++) {
        if (cur->height == height) {
            cur->data = data;
        }
        cur = cur->prev_block;
    }
}
void alter_2_blocks(struct Blockchain* chain, int height, int data) {
    struct Block* cur = chain->head;
    while (cur != NULL && cur->prev_block != NULL) {
        if (cur->prev_block->height == height) {
            cur->prev_block->data = data;
            set_digest(&cur->prev_hash, cur->prev_block);
        }
        cur = cur->prev_block;
    }
}
/*
 * Name: test
 * Purpose: Test functions above
 */
int testBlockChain(void)
{

    //Create, print, and verify blockchain
    struct Blockchain* blockchain = initialize();
    for (int i = 1; i <= 5; i++)
    {
        add(blockchain, 10 * i);
    }
    
    ////Test cases
    ////Test 1
    /*printf("\nTest 1\n");
    print_blockchain(blockchain);
    verify(blockchain); */

    //Test 2
    //Alter the value in a block, print, and verify blockchain
    /*printf("Test 2\n");
    alter_block(blockchain, 2, 300);
    print_blockchain(blockchain);
    verify(blockchain);*/

    //Test 3
    //Comment out Test 2, and uncomment the following three code lines
    //Alter the value in a block and the hash value tracked for
    //that altered block
    /*printf("Test 3\n");
    alter_2_blocks(blockchain, 1, 200);
    print_blockchain(blockchain);
    verify(blockchain);*/

    //Test 4
    //Comment out Test 2 and 3, and uncomment the following three code lines
    printf("Test 4\n");
    delete_at(blockchain, 1);
    print_blockchain(blockchain);
    verify(blockchain);

    return 0;
}