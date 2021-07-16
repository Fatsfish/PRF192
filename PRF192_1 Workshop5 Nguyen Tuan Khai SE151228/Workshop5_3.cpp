#include <stdio.h>
int character(char c1, char c2);
int valid(int d, int m, int y);
int main(){
	int choice;
     do   /* Print out the menu and get user choice*/
      {    printf("1- Processing date data\n");
           printf("2- Character data\n");
           printf("3- Quit\n");
           printf("Select an operation:");
           scanf("%d", &choice);
           switch(choice) 
               { 	case 1:	
			   					int d,m,y;
								printf("Type in day month year:\n");
							    scanf("%d %d %d", &d, &m, &y);
							    if(valid(d,m,y)){printf("valid date\n");}
							    else{ printf("invalid date\n");}
                               break;
                    case 2:		
								char c1, c2, t, c;
								character(c1,c2);
								break;
                	case 3: printf("Thank you for using the program.\n");
                				break;
                    default: printf("The option is not supported.");
        }} while ( choice >0 & choice<3); }

int valid ( int d, int m, int y) {
int maxd = 31; /*max day of months 1, 3, 5, 7, 8, 10, 12 */
/* basic checking */
if ( d<1 || d>31 || m<1 || m>12) {return 0;}
/* update maxd of a month */
if ( m==4 || m==6 || m==9 || m==11) {maxd=30;}
else if (m==2) {
            /* leap year? */
             if ( y%400==0 || y%4==0 && y%100!=0){maxd=29;}
             else maxd=28;
       }
return d<=maxd; 
}
int character(char c1, char c2){
	char t,c;
	int e;
	printf("Type 2 any characters:\n");
	fflush(stdin);
   	scanf("%c%c",&c1,&c2);
     if(c1 > c2 ) 
     { t = c1; c1 = c2;  c2= t;
     }
     e = c2-c1;
     	printf("The number characters between them is:%d\n", e);
    	for(c=c2;c>=c1;c--)
     	{ printf("%c :   %d,   %o,   %X\n", c, c, c, c);}
     }
