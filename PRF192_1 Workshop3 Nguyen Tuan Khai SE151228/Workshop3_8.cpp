#include<stdio.h>
double makeDouble(int ipart, int fraction)
{  double d_f= fraction;
    while (d_f >=1) {d_f = d_f/10;} /* create the fraction <1 */
    if (ipart<0) {return ipart-d_f;} /* case  -51 - 0.139 */
    return ipart + d_f ;  /* case 32 + 0.25 */
}
int main(){
	int ipart, fraction;
	printf("Type in the integral part:");
	scanf("%d", ipart);
	double value;
	printf("Type in the fraction part:");
	do{ 
		scanf("%d", fraction);
    }
    while (fraction<0);
    value= makeDouble(ipart,fraction);
    printf("The real number is:%lf", value);
}
