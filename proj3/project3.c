#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char * * argv)
{	
	if (argc != 2)
	{
		printf("Error, need input file\n");
		return EXIT_FAILURE;
	}
	
	FILE	 *FID = fopen(argv[1],"r");
	if (FID == NULL)
	{
		printf("Need valid file name\n");
		return EXIT_FAILURE;
	}
	
	
	fclose(FID);
	return EXIT_SUCCESS;
}
