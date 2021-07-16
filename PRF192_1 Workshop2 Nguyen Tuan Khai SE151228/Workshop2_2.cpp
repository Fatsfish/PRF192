#include <stdio.h>
#define pa 9000000
#define pd 3600000
int main(){
	double ti, income, tf;
	double n;
	double it;
	double tax;
	printf("nhap du lieu income, n:\n");
	scanf("%lf%lf", &income, &n);
	tf=12*(pa+n*pd);
	ti=income-tf;
	if(ti<0){
		tax=0;
		ti=0;
		printf("tax=0\n");}
	if(ti>=0 && ti<5000000){
		tax=0.05;
		printf("tax=0.05\n");
	}
	if(ti>=5000001 && ti<10000000){
		tax=0.1;
		printf("tax=0.1\n");
	}
	if(ti>=10000001 && ti<18000000){
		tax=0.15;
		printf("tax=0.15\n");
	}
	if(ti>=18000001){
		tax=0.2;
		printf("tax=0.2\n");
	}
	it=ti*tax;
	printf("so tien mien thue=%lf\n", tf);
	printf("so tien co the danh thue=%lf\n", ti);
	printf("so tien thue=%lf\n", it);
}
