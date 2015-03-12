#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
void sort(int list[], int n) ;
double get_time_ms();
void printArray (int *array, int n);

int main(){
	
	int Array1[] = {1,2,3,3,2,1}, n = 6;
	int Array2[1000], i = 0;
	
	for (i = 0; i < 1000; i++)
	{
		Array2[i] = rand();
	}
	
	
	printArray(Array1,n);
	sort(Array1,6);
	printArray(Array1,n);
	
	printArray(Array2,1000);
	sort(Array2,1000);
	printArray(Array2,1000);
	
	return 0;
  
}

double get_time_ms()
{
struct timeval t;
gettimeofday(&t, NULL);
return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

void printArray (int *array, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%i, ",array[i]);
	}
	printf("\n\n");
}

