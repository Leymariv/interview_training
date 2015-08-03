#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *array, int left, int right);
void swap(int *array, int i, int j);
void print_tab(int *array, int size);
int main() 
{
	int array[10] = {0,3,5,1,9,6,7,2,8,4};
	
	int right = 9;
	int left = 0;
	quick_sort(array, left, right);	
	return 0;
}

void quick_sort(int *array, int left, int right)
{
	if (left >= right)
		return;
	int wall = left;
	int index = left;
	int pivot = right;
	while (index < right) {
		if (array[index] <= array[pivot]) {
			swap(array,index,wall);
			wall++;
		}
		index++;
	}
	swap(array,index,wall);
	print_tab(array,10);
	quick_sort(array, wall+1, right);
	quick_sort(array, left, wall-1);
}

void swap (int *array, int i, int j) 
{
	int c = array[i];
	array[i] = array[j];
	array[j] = c;
}

void print_tab(int *array, int size)
{
	for (int i = 0; i<size; i++) 
		printf("%d, ", array[i]);
	printf("\n");
}
