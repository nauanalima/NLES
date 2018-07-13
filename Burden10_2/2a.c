#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define n 3

double f1(double x[n]) {	
	return 3*x[0] - cos(x[1]*x[2]) - 0.5;
}

double f2(double x[n]) {
	return 4*pow(x[0],2) - 625*pow(x[1],2) + 2*x[1] - 1;
}

double f3(double x[n]) {	
	return exp(-x[0]*x[1]) + 20*x[2] + (10*M_PI-3)/3.;
}

void print(double **matrix, int row, int col){
	int i, j;
	printf("\nMatriz: \n");
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) { 
			printf("%5.2lf\t",matrix[i][j]);
		}	  
		printf("\n");
	}
	printf("\n");
}

int uppertriangular (double **matrix, int row, int col) {
	int i, j, k, k1, test, pivot;
	double m, temp;

	int steps = 0; 

	for (k=0; k<row; k++) {
		for (j=k; j<row; j++) {
			test = -1;
			if (fabs(matrix[j][k]) > matrix[k][k]) {
				test = j;
			}
			if (test!=-1) {
				exchangelines(matrix[k], matrix[test], row);
				steps++;
				printf("\nSteps: %d", steps);
			}
		}
		for (i=k+1; i<row; i++) {
			m = matrix[i][k]/matrix[k][k];
			for (j=k; j<=col; j++)
				matrix[i][j] = matrix[i][j] - m*matrix[k][j];
		}
		printf("\nEstágio da matriz:");
		print(matrix,row,col);
	}
	return steps;		
}

double reversesub (double **matrix, double *root, const int dim) {
	int j, k, n;
	double sum;
	root[dim-1] = matrix[dim-1][dim]/matrix[dim-1][dim-1];
	k = dim-2;
	while (k>=0) {
		sum = matrix[k][dim];
		for (j=k+1; j<dim; j++) 
			sum = sum - matrix[k][j]*root[j];
		root[k] = sum/matrix[k][k];
		k--;
	}
}

int main()
{	
}