#include <stdio.h>
#include <math.h>
int bankDeposit (int m, double r, int n){
	double P;
	if(r>=0 && r<=0.1 && n>0)
	{
	P=m*pow((1+r),n);
	printf("The amount after the duration is:%lf\n", P);}
	else{printf("Please pay attention to conditions\n");
	}
}
int main (){				int m,n;
                    		double r;
							printf("Type in deposit, yearly rate and number of years (m,r,n):");
							fflush(stdin);
                    		scanf("%d %lf %d", &m, &r, &n);
                    		bankDeposit(m,r,n);}
                    	
