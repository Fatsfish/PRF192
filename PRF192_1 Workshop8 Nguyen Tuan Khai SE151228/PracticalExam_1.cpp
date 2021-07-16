#include<stdio.h>
void fileToArray(char* fname, int*a, int* pn){
	*pn=0;
	FILE* f=fopen(fname,"r");
	if(f!=NULL){
		while(fscanf(f,"%d%*c" , &a[*pn])==1){
			(*pn)++;
		}
	fclose(f);
	}
}
int find(int v,int a[16], int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==v){
			return i;
		}
	}
	return -1;
}
void add(int v, int a[16], int &n){
	int i;
	int t=find(v,a, n);
	if(t<0){
		for(i=n-1;i>=0;i--){
			a[i+1]=a[i];
		}
		n++;
		a[0]=v;
		printf("The value is added at the beginning!\n");
	}
}
void remove(int v, int a[16], int &n){
	int i;
	int t=find(v,a, n);
	if(t>=0 && t<n){
		for(i=t;i<n-1;i++){
			a[i]=a[i+1];
		}
		n--;
		printf("The value is removed!\n");
	}
}
void Desc(int *a, int n){
	int i,j,t;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j]>a[j-1]){
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
	fprintf(f,"There are %d values: \n",n);
	int i;
	for (i=0;i<n;i++){
		fprintf(f,"%d ",a[i]);
	}
	fclose(f);
}
int main(){
	char infName[]="input1.txt";
	char outfName[]= "output1.txt";
	fflush(stdin);
	int a[16];
	int n=0;
	int v,i;
	fileToArray(infName, a, &n);
	printf("The sequence in input1.txt:\n");
	print(a,n);
	printf("\nType in the search value:");
	fflush(stdin);
	scanf("%d", &v);
	i=find(v, a, n);
	if(i<0){
		printf("\nThe value's not found!\n");
		add(v,a,n);
	}
	if(i>=0){
		printf("\nThe value is found at %d position!\n", i+1);
		remove(v,a,n);
	}
	printf("\nThe sequence after being search:\n");
	print(a,n);
	Desc(a,n);
	printf("\nThe sequence after being sorted:\n");
	print(a,n);
	printToFile(outfName, a, n);
	getchar();
	return 0;
}
