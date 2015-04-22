#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct UserInfo {
	int UserID;
	int Age;
	int Gender;
	int Marital;
	int Race;
	int BirthPlace;
	int Language;
	int Occupation;
	int Income;
} UserInfo;


int main(int argc, char * * argv)
{	
	/* Initial checks and open file */
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
	
	/* Declarations */
	UserInfo *Users;
	int i = 0;
	int NumUsers, Query1;
	float d1, d2, a;
	
	fscanf(FID,"%i, %f, %f %i, %f\n",&NumUsers, &d1, &d2, &Query1, &a);
	printf("%i, %f, %f %i, %f\n",NumUsers, d1, d2, Query1, a);
	Users = malloc(sizeof(Users) * NumUsers);
	
	
	while (!feof(FID))
	{
		fscanf(FID,"%i, %i, %i, %i, %i, %i, %i, %i, %i\n",&Users[i].UserID,&Users[i].Age,&Users[i].Gender,&Users[i].Marital,&Users[i].Race,&Users[i].BirthPlace,&Users[i].Language,&Users[i].Occupation,&Users[i].Income);
		printf("%i, %i, %i, %i, %i, %i, %i, %i, %i\n",Users[i].UserID,Users[i].Age,Users[i].Gender,Users[i].Marital,Users[i].Race,Users[i].BirthPlace,Users[i].Language,Users[i].Occupation,Users[i].Income);
	}
	
	
	fclose(FID);
	return EXIT_SUCCESS;
}
