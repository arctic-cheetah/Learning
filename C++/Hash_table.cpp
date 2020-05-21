#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LENGTH 100


//The "array" of pointers to an entry 
//or keys that store the information to each value
typedef struct entry_t {
	char *key;
	char *value;
	struct entry_t *next;  
} entry_t;

typedef struct ht_t {
	entry_t **entries;
} ht_t;


//A function that converts a string to a hash value
int hash (char *key) {
	int value = 0;
	int i = 0;
	int key_len = strlen(key);
	
	while (i < key_len) {
		value = value * 37 + key[i];
		i++;
	}
	
	value = value % MAX_LENGTH;
	return value;
}

//Creates a hash table
ht_t *ht_create(void) {
	//allocate memory for table
	ht_t *hashTable = (ht_t*) malloc(sizeof(ht_t) * 1);
	//allocate table entries
	hashTable->entries = (entry_t**) malloc(sizeof(entry_t*) * MAX_LENGTH);
	
	//set all entries to be empty
	for (int i = 0; i < MAX_LENGTH; i++) {
		hashTable->entries[i] = NULL;
	}
	return hashTable;
}

//Add data to a specific entry in the hash table
entry_t *ht_pair (char *key, char *value) {
	entry_t *entry = (entry_t* ) malloc(sizeof(entry_t) * 1);
	//entry->key = malloc(sizeof(strlen(key) + 1));
	//entry->value = malloc(sizeof(strlen(value) + 1));
	
	strcpy(entry->key, key);
	strcpy(entry->value, value);
	
	entry->next = NULL;
	
	return entry;
}


//Initialises the hash table some values
void ht_set(ht_t *hashTable, char *key, char *value) {
	int slot = hash(key);
	
	entry_t *entry = hashTable->entries[slot];
	
	if (entry == NULL) {
		hashTable->entries[slot] = ht_pair(key, value);
		return;
	}
	
	entry_t *prev;
	
	//Search through each entry until the end is reached
	//or a key match is found
	while (entry != NULL) {
		//Checks if there is an existing entry
		//And replaces it
		if (strcmp(entry->key, key) == 0) {
			free(entry->value);
			//entry->value = malloc(strlen(value) + 1);
			strcpy(entry->value, value);
			return;
		}
		
		prev = entry;
		entry = prev->next;
	}
	
	//Add an entry to a vacant slot
	prev->next = ht_pair(key, value);
}

//Retrieves information from the hash table
char *ht_get(ht_t *hashTable, char *key) {
	int slot = hash(key);
	
	entry_t *entry = hashTable->entries[slot];
	//No slot, no entry
	if (entry == NULL) {
		return NULL;
	}
	
	//Search through each entry until the end is reached
	//or a key match is found
	while (entry != NULL) {
		
		if (strcmp(entry->key, key) == 0) {
			return entry->value;
		}
		entry = entry->next;
	}
	
	
	return NULL;
}

//Print the hash table
void ht_print(ht_t *hashTable) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		entry_t *entry = hashTable->entries[i];
		if (entry == NULL) {
			continue;
		}
		
		printf("slot[%d]: ", i);
		for (;;) {
			printf("%s=%s ", entry->key, entry->value);
			
			if (entry->next == NULL) {
				break;
			}
		
			entry = entry->next;
			
		}
		printf("\n");
	}
	
}

int main () {
	ht_t *hashTable = ht_create();
	
	ht_set(hashTable, "1", "Hello");
	ht_set(hashTable, "9", "Treello");
	ht_set(hashTable, "3", "Fellow");
	
	ht_print(hashTable);
	
	return 0;
}

























































