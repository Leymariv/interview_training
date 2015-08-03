#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_cell{
	char val;
	int key;
	struct hash_cell *next;
};

int hash_char(char c, int size)
{
	int ascii = c;
	return ascii % size;
}

int twice_a_char(char *word) 
{
	struct hash_cell **hash_table = NULL;
	int size = strlen(word);
	if ((hash_table = malloc(sizeof(struct hash_cell*) * size)) != NULL) {//attention au parentheses ici qui sont très importantes!
		for (int i = 0; i< size; i++) {
			int index_i = hash_char(word[i], size);
			if (hash_table[index_i]	== NULL)
				hash_table[index_i] = calloc(1, sizeof(struct hash_cell));	
			if (hash_table[index_i]->val == word[i])
				return 1;
			else
				hash_table[index_i]->val = word[i];		
		}
	} else {
		printf("Allocation Error\n");
	}
	return 0;
}

int main (int arc, char *argv[]) {

	char *word = "saucion"; 
	int is_twice = twice_a_char(word);
	if (is_twice)
		printf("Yes, twice the same character in %s\n",word);
	else
		printf("Not twice the same character in %s\n",word);
	return 0;
}


