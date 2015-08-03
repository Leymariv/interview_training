#include <stdio.h>
#include <stdlib.h>

#define N 5

void print_img(int **img, int size)
{
	for (int i=0; i < size; i++){
		for (int j=0; j < size; j++)
			printf("%d ", img[i][j]);
		printf("\n");
	}
}

void set_img(int **img, int size)
{
	int val = 1;
	for (int i=0; i < size; i++){
		for (int j=0; j < size; j++)
			img[i][j] = val++;
	}
}

int **rotate(int **img, int size)
{
	int **img_temp = malloc(size*sizeof(int*));
	for (int i=0; i<size; i++)
		img_temp[i] = malloc(sizeof(int));
	for (int i=0; i < size; i++)
		for (int j=0; j < size; j++)
			img_temp[i][j] = img[size-1-j][i];
	return img_temp;
}

int main(int argc, char *argv[])
{
	int **img = malloc(N*sizeof(int*));
	for (int i=0; i<N; i++)
		img[i] = malloc(N*sizeof(int));
	set_img(img, N);
	print_img(img, N);
	print_img(rotate(img, N), N);
}
