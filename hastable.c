#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_cell{
	char *val;
	char *key;
	struct hash_cell *next;
};

struct hash_cell **ht_create(int size)
{
	struct hash_cell **hash_t = malloc(size * sizeof(struct hash_cell));
	if (hash_t == NULL){
		printf("Allocation Error\n");
		return NULL;
	} else {
		for (int i = 0; i < size; i ++) {
		hash_t[i] = NULL;
		}
	}
	return hash_t;
}

int hash_key(char *key)
{
	int size = strlen(key);
	int hash_val = 0;
	for (int i = 0; i< size; i++)
		hash_val += key[i];
	return hash_val % size;
}

void ht_set(struct hash_cell** hash_t, char *key, char *val)
{
	struct hash_cell *new_entry = malloc(sizeof(struct hash_cell));
	new_entry->key = key;
	new_entry->val = val;
	new_entry->next = NULL;

	struct hash_cell **current = &(hash_t[hash_key(key)]);

	if (*current == NULL) {
		*current = new_entry;
	} else {
		while((*current)->next != NULL)
			(*current) = (*current)->next;
		(*current)->next = new_entry;	
	}
}

char *ht_get(struct hash_cell **hash_t, char* key)
{
	struct hash_cell *temp = hash_t[hash_key(key)];
	do {
		if (strcmp(temp->key, key) == 0)
			return temp->val;
		else 
			temp = temp->next;	
	}while(temp != NULL);
	return NULL;
}

int main( int argc, char **argv )
{

	int size = 4;
	struct hash_cell **hashtable = ht_create(size);

	ht_set( hashtable, "key1", "inky" );
	ht_set( hashtable, "*", "pinky" );
	ht_set( hashtable, "key3", "blinky" );
	ht_set( hashtable, "key4", "floyd" );
	
	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "*" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );

	return 0;
}

