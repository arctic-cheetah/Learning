//Implementation of a hash function from programwizz
//https://www.programiz.com/dsa/hash-table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 7

//The manifestation of the table via it's entries
typedef struct entry_t {
	char *key;
	char *data;
	struct entry_t *next;
} entry_t;
typedef struct hash_t {
	entry_t **entry;
} hash_t;

//The function which will allocate a position
int hash_function (char *key) {
	int value = 0;
	int str_len = strlen(key);
	int i = 0;
	while (i < str_len) {
		value = value * 19 + key[i];
		i++;	
	}
	return value % MAX_LENGTH;
}

//Create the hash table

hash_t *ht_create() {
	//Allocate table
	hash_t *ht = (hash_t*) malloc(sizeof(hash_t) * 1);
	
	//Allocate table entries
	ht->entry = (entry_t**) malloc(sizeof(entry_t) * MAX_LENGTH);
	
	//Set all entries to be NULL
	int i = 0;
	while (i < MAX_LENGTH) {
		ht->entry[i] = NULL;
		i++;
	}
	return ht;
}


//Add data to a specific entry
//Need to process the data from the insert_data function
entry_t *Input_pair(char *key, char *value) {
	//Allocate memory for a new node
	entry_t *newNode = (entry_t*) malloc(sizeof(entry_t));	
	//Allocate memory for key
	newNode->key = malloc(sizeof(strlen(key) + 1));
	//Allocate memory for value
	newNode->data = malloc(sizeof(strlen(value) + 1));
	
	//Copy the strings into their designated spaces
	strcpy(newNode->key, key);
	strcpy(newNode->data, value);
	//Make the next pointer point to NULL
	newNode->next = NULL;
	return newNode;
}

//Insert data to the hash table by sending in the key and value
void ht_insert (hash_t *ht, char *key, char *value) {
	//Get a position in the hash table
	int slot = hash_function(key);
	
	//Be able to point to a slot in the hash table
	entry_t *entry = ht->entry[slot];
	
	//Add data into the entry...But check these conditions first
	
	//Check if there is an existing entry
	if (entry == NULL) {
		ht->entry[slot] = Input_pair(key, value);
		return;
	}
	entry_t *prev = NULL;
	//Otherwise loop through the linked list and check for duplicate entries
	while (entry != NULL) {
		//If matching key is found, update the entry
		if (strcmp(entry->key, key) == 0) {
			free(entry->data);
			entry->data = malloc(strlen(value) + 1);
			strcpy(entry->data, value);
			return;
		}
		
		prev = entry;
		entry = entry->next;
	}
	prev->next = Input_pair(key, value);
}


//Obtain an entry from the hash table
char *ht_get (hash_t *ht, char *key) {
	//Get the position of the entry in the hash table
	int slot = hash_function(key);
	
	entry_t *entry = ht->entry[slot];
	//Check if entry is Null
	if (entry == NULL) {
		printf("User chose an empty entry\n");
		return NULL;
	} 	
	//Otherwise loop through the linked list until key match is found
	while (entry != NULL) {
		if (strcmp(entry->key, key) == 0 ) {
			return entry->data;	
		}
		entry = entry->next;
	}
	//If no key match is found,
	return NULL;
}


//Print the entire hash table
void ht_print(hash_t *ht) {

	for (int i = 0; i < MAX_LENGTH; i++) {
		entry_t *entry = ht->entry[i];
		//check if entry is not NULL
		if (entry == NULL) {
			continue;
		}
		printf("slot[%d] ", i);
			//Loop through the entry if a linked list exists
		while (entry != NULL) {
			
			printf("%s = %s ", entry->key, entry->data);
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
	ht_insert(hashTable, "Poy", "Few");

	
	ht_print(hashTable);

}

















































