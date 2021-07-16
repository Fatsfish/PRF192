#include <stdio.h>
int main (){
int x,y;
do {	printf("Type in 2 intergers:");
        scanf("%d%d", x, y);
         int t= x;         
         x= y;
         y= t;
        printf("2 new intergers:%d %d", x, y);
}
while ( x!=0 && y!=0);}
