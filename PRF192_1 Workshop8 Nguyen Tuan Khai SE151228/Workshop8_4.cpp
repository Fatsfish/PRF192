#include<stdio.h>
void fileToArray(char* fname, int*a, int* pn){
	FILE* f=fopen(fname,"r");
	fscanf(f,"%d",pn);
	int i;
	for (i=0;i<*pn;i++){
		fscanf(f,"%d", &a[i]);
	}
	fclose(f);
}
void Asce(int *a, int n){
	int i,j,t;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
}
int print( int* a, int n){
	int i;
	for (i=0;i<n;i++){printf("%d ", a[i]);
	}
}
int printToFile (char* fname, int*a, int n){
	FILE* f=fopen(fname,"w");
	fprintf(f,"%d",n);
	int i;
	for (i=0;i<n;i++){
		fprintf(f,"%d",a[i]);
	}
	fclose(f);
}
int main(){
	char infName[]="array1.txt";
	char outfName[]= "array2.txt";
	int a[200];
	int n=0;
	fileToArray(infName, a, &n);
	printf("The sequence in array1.txt which can be created in workshop8_2 and workshop8_3:\n");
	print(a,n);
	Asce(a,n);
	printf("\nThe sequence after being sorted:\n");
	print(a,n);
	printToFile(outfName, a, n);
	getchar();
	return 0;
}
