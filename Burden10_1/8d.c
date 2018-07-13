#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 3

double f1(double x[n]) {	
    return (pow(x[0],2) + 2*pow(x[1],2) - x[2] - 2*x[2]);
}

double f2(double x[n]) {	
    return (pow(x[0],2) - 8*pow(x[1],2) + 10*x[2]);
}

double f3(double x[n]) {	
    return ((pow(x[0],2)/(7*x[1]*x[2]))-1);
}

double x1(double x[n]) {
    return sqrt(x[1]+2*x[2]-2*pow(x[1],2));
}

double x2(double x[n]) {
    return sqrt((pow(x[0],2)+10*x[2])/8);
}

double x3(double x[n]) {
    return pow(x[0],2)/(7*x[1]);
}

int main(int argc, char **argv) {	
	double x[n] = {0.1,0.1,0.1}, acc=1e-5;
	double norm, norma;
	double (*equation[n])()={x1,x1,x3};
	int i;
	do {	
        norma = norm = 0;
		for(i=0; i<n; i++) {	
			norm += pow(x[i], 2);
			x[i] = equation[i](x);
			norma += pow(x[i], 2);
		}
	}while(acc < sqrt(fabs(norma-norm)));
    for(i=0; i<n; i++) 
		printf("%lf\n", x[i]);
}