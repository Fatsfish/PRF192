#include <stdio.h>
#include <math.h>
int quadraticEquation(double a, double b, double c){
	double x1,x2;
	double x;
	double d;
	if(a==0){
	x=-c/b;
	printf("The value is:x=%lf\n", x);}
	if(a!=0){
		d=b*b-4*a*c;
		if (d>0){
			x1=(b+sqrt(d))/(2*a);
			x2=(b-sqrt(d))/(2*a);
			printf("The values are: %lf and %lf\n", x1,x2);}
		if (d==0){
			x=b/(2*a);
			printf("The only value is: %lf\n",x);}
		if (d<0){	printf("The equation doesn't have results");}
		}
	}
	int main ()				{double a,b,c;
			   				printf("Type in a,b,c as intergers:");
               				scanf("%lf %lf %lf", &a, &b, &c);
               				quadraticEquation (a,b,c);}
