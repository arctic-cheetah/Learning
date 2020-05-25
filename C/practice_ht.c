//A practice of implementing a hash table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 6


//The structs for manifestation of the hash table
typedef struct entry_t {
	char *key;
	char *data;
	struct entry_t *next;
} entry_t;
typedef struct hash_t {
	entry_t **entries;
} hash_t;

//Allocates a position for the entries

int hash (char *key) {
	int wordLen = strlen(key);
	int value = 0;
	for (int i = 0; i < wordLen; i++) {
		//Safe guard to prevent integer overflow
		value = value * 31 + key[i];
	}
	
	return value % MAX_LENGTH;
}

//Create a hash table
hash_t *ht_create() {
	//Create the ht
	hash_t *ht = (hash_t*) malloc(sizeof(hash_t) * 1);
	
	//Allocate memory to the hash table entries
	ht->entries = (entry_t**) malloc(sizeof(entry_t) * MAX_LENGTH);
	
	//Set the entries to NULL
	for(int i = 0; i < MAX_LENGTH; i++) {
		ht->entries[i] = NULL;
	}
	return ht;
}

//Copies strings into a specific entry
entry_t *ht_pair (char *key, char *data) {
	entry_t *newNode = (entry_t*) malloc(sizeof(entry_t) * 1);
	
	//Allocate memory to the key and data within an entry
	newNode->key = malloc(sizeof(strlen(key) + 1));
	newNode->data = malloc(sizeof(strlen(data) + 1));
	
	//Copy the data to the new entrt
	strcpy(newNode->key, key);
	strcpy(newNode->data, data);
	
	newNode->next = NULL;
	return newNode;
}

//Add an entry to the hash table
void ht_insert (hash_t *ht, char *key, char *data) {
	//Get a unique key
	int slot = hash(key);
	
	entry_t *entry = ht->entries[slot];
	
	//If there is no entry. Simply add an entry
	if (ht->entries[slot] == NULL) {
		ht->entries[slot] = ht_pair(key, data);
		return;
	}
	entry_t *prev = entry;
	//Otherwise, if an entry exists and loop through the linked list
	while (entry != NULL) {
		//find if any keys are identical.
		if (strcmp(entry->key, key) == 0) {
			//update the data in the linked list
			free(entry->data);
			entry->data = malloc(strlen(data) + 1);//CHECK HERE
			strcpy(entry->data, data);
			//Stop the process
			return;
		}
		prev = entry;
		entry = entry->next;
	}
	//If there are no identical keys, allocate a new memory for the data
	//in that entry
	prev->next = ht_pair(key, data);
}


char *ht_get (hash_t *ht, char *key) {
	int slot = hash(key);
	
	//Two cases
	//Either there is no entry
	//Or there is a linked list in an entry
	entry_t *entry = ht->entries[slot];
	if (ht->entries[slot] == NULL) {
		printf("The user chose an empty entry");
		return NULL;
	}
	
	while (entry != NULL) {
		//Find a key match in the linked list
		if (strcmp (entry->key, key) == 0) {
			return entry->data;
		}
		entry = entry->next;	
	}
	printf("Data not found!\n");
	return NULL;
}
 
//Print all of the entries in the ht
void ht_print(hash_t *ht) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		if (ht->entries[i] == NULL) {
			continue;
		}
		printf("slot[%d]", i);
		entry_t *entry = ht->entries[i];
		while (entry != NULL) {
			printf("|%s %s|", entry->key, entry->data);
			entry = entry->next;
		}
		printf("\n");
	}
}


int main () {
	hash_t *hashTable = ht_create();
	
	ht_insert(hashTable, "1", "Hello");
	ht_insert(hashTable, "9", "Treello");
	ht_insert(hashTable, "3", "Fellow");
	ht_insert(hashTable, "ghea", "so");
	ht_insert(hashTable, "rhea", "Treo");
	ht_insert(hashTable, "Pos", "Few");
	
	ht_print(hashTable);
	printf("The data is : %s\n", ht_get(hashTable, "Pos"));
	
}











































