#include <stdio.h>

void swap(double *a, double *b);
int main(){
	double a = 1.5;
	double b = 2.5;
	
	printf(" a = %f \n", a);
	printf(" b = %f \n", b);
	
	swap(&a, &b);
	printf(" a = %f \n", a);
	printf(" b = %f \n", b);
	
	return 0;
}

void swap(double *a, double *b){
	double temp = *a;
	*a = *b;
	*b =  temp;
}