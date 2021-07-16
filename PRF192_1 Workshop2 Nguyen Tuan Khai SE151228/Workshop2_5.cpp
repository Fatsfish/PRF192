#include <stdio.h>
#include <ctype.h>
int main(){
char ch;
int nVowels=0;
int nConsonants=0;
int nOthers=0;
printf("Type the string of charaters:\n");
do {
 	ch=getchar();   /* ch= getchar(); */
 	ch = toupper(ch); 	/* ch= toupper(ch); */
if (ch>='A' && ch <='Z') {
     switch (ch) {
         case 'A' :nVowels ++; break;
         case 'E' :nVowels ++; break;
         case 'I' :nVowels ++; break;
         case 'O' :nVowels ++; break;
         case 'U' :nVowels ++; break;
         default:  nConsonants++;
     }
}
else if (ch!=10) nOthers++;
    }
while ( ch != '\n');
printf("number of Vowels:%d\n", nVowels);
printf("number of Consonants:%d\n", nConsonants);
printf("number of Others:%d\n", nOthers);
}
