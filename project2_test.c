#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

void sort(int list[], int n);
double get_time_ms();

int main(){
	
	double total_time = 0;
	
	fprintf(stdout,"Running Benchmarks\n\n\n");
	
	int num_test = 1000000;
	
	int *my_array = malloc(num_test*sizeof(int));
	
	int i = 0;
	int negative = 0;
	for(i=0;i<num_test;i++)
	{
		my_array[i] = rand() % 100000 + 1;
	}

    double start = get_time_ms();	

    sort(my_array,num_test);

    double end = get_time_ms();
  
    total_time = total_time + end-start;
  
    int correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Random array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
  
	for(i=0;i<num_test;i++)
	{
		my_array[i] = i;
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
	
	for(i=0;i<num_test;i++)
	{
		my_array[i] = i;
	  if(rand() % 25 == 0);
	  {
		int temp = my_array[i];
		my_array[i] = my_array[i-1];
		my_array[i-1] = temp;
	  }
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Nearly sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
	
	for(i=0;i<num_test;i++)
	{
		my_array[i] = i;
	  if(rand() % 4 == 0);
	  {
		int temp = my_array[i];
		my_array[i] = my_array[i-1];
		my_array[i-1] = temp;
	  }
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Less nearly sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
	
			
	
	
	for(i=num_test;i>0;i--)
	{
		my_array[i] = i;
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Reverse sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
  
	num_test = 100000;
	
	i = 0;
	for(i=0;i<num_test;i++)
	{
		my_array[i] = rand() % 100000 + 1;
	}

    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();
	total_time = total_time + end-start;
  
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Random array of 100 thousand elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
  
	for(i=0;i<num_test;i++)
	{
		my_array[i] = i;
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();
	total_time = total_time + end-start;	
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Sorted array of 100 thousand elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
	
	
	
	
	for(i=num_test;i>0;i--)
	{
		my_array[i] = i;
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();
	total_time = total_time + end-start;	
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Reverse sorted array of 100 thousand elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
  

	num_test = 1000000;
  
  	for(i=0;i<num_test;i++)
	{
		my_array[i] = rand() % 100000 + 1;
		negative = rand() % 2;
		if(negative)
			{
				my_array[i] = -1 * my_array[i];
			}
	}

    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();
	total_time = total_time + end-start;
  
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Random array of 1 million elements (with negatives)\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);
  
    int counter = -1 * num_test/2;
	for(i=0;i<num_test;i++)
	{
		my_array[i] = counter;
		counter++;
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();
	total_time = total_time + end-start;	
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Sorted array of 1 million elements (with negatives)\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);

    counter = num_test / 2;
	for(i=num_test;i>0;i--)
	{
		my_array[i] = counter;
		counter--;
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Reverse sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);



    counter = num_test / 2;
	for(i=0;i<num_test;i++)
	{
		my_array[i] = counter;
		counter--;
		
		if(rand() % 25 == 0);
		{
			int temp = my_array[i];
			my_array[i] = my_array[i-1];
			my_array[i-1] = temp;
	  }
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Nearly reverse sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);



    counter = num_test / 2;
	for(i=0;i<num_test;i++)
	{
		my_array[i] = counter;
		counter--;
		
		if(rand() % 4 == 0);
		{
			int temp = my_array[i];
			my_array[i] = my_array[i-1];
			my_array[i-1] = temp;
	  }
	}
	
    start = get_time_ms();	

    sort(my_array,num_test);
  
    end = get_time_ms();	
	total_time = total_time + end-start;
	
    correct = 1;
    for(i=0; i<num_test-1;i++)
    {
	  if(my_array[i]>my_array[i+1])
	  {
		  correct = 0;
	  }
	}
  
    fprintf(stdout,"Less nearly reverse sorted array of 1 million elements\n");
	if(correct)
	{
	  fprintf(stdout,"\tARRAY IS CORRECTLY SORTED\n");
	}
	else
	{
	  fprintf(stdout,"\tARRAY IS NOT CORRECTLY SORTED\n");
	}
  
	fprintf(stdout,"\tfile sorted in %f milliseconds\n\n",end-start);

	
	fprintf(stdout, "Benchmarking Complete:\n");
	fprintf(stdout, "\tTotal Time : %f milliseconds\n",total_time);
  
    //getchar();
	
	return 0;
  
}

double get_time_ms()
{
struct timeval t;
gettimeofday(&t, NULL);
return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
