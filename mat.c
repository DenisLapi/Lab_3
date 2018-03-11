#include <stdio.h>

#define ROW 3
#define COL 3

void sum_matrixes() {

	int row = 3;
	int col = 3;
	int i;
	int j;

	int matrix_a[ROW][COL] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int matrix_b[ROW][COL] = {
		{9,8,7},
		{6,5,4},
		{3,2,1}
	};

	int matrix_c[ROW][COL];

	// Sum matrixes
	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COL; j++) {
			matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}

	// Show sum matrix
	printf("[Mat] Sum of two matrixes: \n");
	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COL; j++) {
			printf("%d ",matrix_c[i][j]);
		}
		printf("\n");
	}

}