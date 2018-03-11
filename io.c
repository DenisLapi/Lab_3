#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "io.h"

void read_matrix_from_file() {

	int row = 0;
	int col = 0;
	int max_col = 0;
	int max_row = 0;
	int isNewline = 0;
	int matrix[20][20];
	char str[250];
	char *token;
	
	FILE *file = fopen("matrix.txt", "r");

	assert(file);

	while(!feof(file)) {

		fscanf(file, "%s", str);

		if(strstr(str, ",")) {

			token = strtok(str, ",");
			matrix[row][col] = atoi(token);
			col++;

		} else {

			matrix[row][col] = atoi(str);
			isNewline = 1;
			row++;
			if(max_col <= 0) {
				max_col = col;	
			}	
			col = 0;

		}

		isNewline = 0;

	}

	fclose(file);

	// minus one because of the last value in the matrix ([n][m])
	max_row = row - 1; 

	printf("[IO] Matrix from a file:\n\n");
	for(row = 0; row <= max_row; row++) {
		for(col = 0; col <= max_col; col++) {
			printf("%d ", matrix[row][col]);
		}
		printf("\n");
	}
	
}

void print_matrix_in_file(int row, int col) {

	int i;
	int j;
	int matrix[row][col];

	FILE *file = fopen("matrix.txt", "w+");

	assert(file);

	// Create matrix and add values

	printf("[IO] Enter values in matrix to print in a file: \n\n");

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
			if(j != col - 1) {
				fprintf(file,"%d, ", matrix[i][j]);
			} else {
				fprintf(file,"%d", matrix[i][j]);
				if(i != row - 1) {
					fprintf(file,"\n");
				}
			}
		}
	}

	fclose(file);
}