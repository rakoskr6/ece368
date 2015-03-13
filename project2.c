#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
void sort(int list[], int n);

int cmpfunc (const void * a, const void * b)
{	
   return ( *(int*)a - *(int*)b );
}


void sort(int list[], int n) // up to 1 million numbers (will give sorted file)
{
	qsort(list,n,sizeof(int),cmpfunc);
}

