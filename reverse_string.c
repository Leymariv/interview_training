#include <stdio.h>

void swap(char* word, int from, int to)
{
	char c = word[from];
	word[from] = word[to];
	word[to] = c;
}

void reverse(char *word, int size){
	int index = size-1;
	int mid = index/2;
	for (int i = 0; i<= mid; i++)
		swap(word, i, index-i);
}

int main()
{
	char word[] = {'a', 'b', 'c', 'd','\0'};
	reverse(word, 4);
	printf("%s\n", word);
	return 0;
}
