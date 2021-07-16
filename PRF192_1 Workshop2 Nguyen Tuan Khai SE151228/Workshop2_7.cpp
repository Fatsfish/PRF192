#include <stdio.h>
int main(){
	char c1, c2, t, c;
	int d;
	printf("Type 2 any characters:\n");
	scanf("%c %c", &c1, &c2);
     if(c1 > c2 ) 
     { t = c1; c1 = c2;  c2= t;
     }
     d = c2-c1; 
     printf("The number characters between them is:%d\n", d);
     for(c=c1;c<=c2;c++)
     {    printf("%c :   %d,   %o,   %X\n", c, c, c, c);
     }

}
