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

double Distance(UserInfo *First, UserInfo *Second)
{
	double TempSum = 0;
	
	printf("User[%i] - User[%i]\n",First->UserID,Second->UserID);
	
	printf("Age (%i - %i)^2 + %.1f = ",First->Age,Second->Age,TempSum);
	TempSum = pow((First->Age - Second->Age),2);
	printf("%.1f\n",TempSum);
	
	printf("Gender (%i - %i)^2 + %.1f = ",First->Gender,Second->Gender,TempSum);
	TempSum = pow((First->Gender - Second->Gender),2) + TempSum;
	printf("%.1f\n",TempSum);
	
	printf("Marital (%i - %i)^2 + %.1f = ",First->Marital,Second->Marital,TempSum);
	TempSum = pow((First->Marital - Second->Marital),2) + TempSum;
	printf("%.1f\n",TempSum);
	
	printf("Race (%i - %i)^2 + %.1f = ",First->Race,Second->Race,TempSum);
	TempSum = pow((First->Race - Second->Race),2) + TempSum;
	printf("%.1f\n",TempSum);
	
	printf("BirthPlace (%i - %i)^2 + %.1f = ",First->BirthPlace,Second->BirthPlace,TempSum);
	TempSum = pow((First->BirthPlace - Second->BirthPlace),2) + TempSum;
	printf("%.1f\n",TempSum);
	
	printf("Language (%i - %i)^2 + %.1f = ",First->Language,Second->Language,TempSum);
	TempSum = pow((First->Language - Second->Language),2) + TempSum;
	printf("%.1f\n",TempSum);
	
	printf("Occupation (%i - %i)^2 + %.1f = ",First->Occupation,Second->Occupation,TempSum);
	TempSum = pow((First->Occupation - Second->Occupation),2) + TempSum;
	printf("%.1f\n",TempSum);
	
	printf("Income (%i - %i)^2 + %.1f = ",First->Income,Second->Income,TempSum);
	TempSum = pow((First->Income - Second->Income),2) + TempSum;
	printf("%.1f\n\n",TempSum);
	
	return sqrt(TempSum);
}

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
	int i = 0, x = 0, y = 0;
	int NumUsers, Query1;
	float d1, d2, a;
	double **DistMtrx, Max = 0;
	
	fscanf(FID,"%i, %f, %f, %i, %f\n",&NumUsers, &d1, &d2, &Query1, &a);
	printf("%i, %f, %f %i, %f\n\n",NumUsers, d1, d2, Query1, a);
	Users = malloc(sizeof(Users) * NumUsers);
	

	// make matrix to store distances
	DistMtrx = malloc(sizeof(double) * NumUsers);
	for (i = 0; i < NumUsers;  i++)
	{
		DistMtrx[i] = malloc(sizeof(double) * NumUsers);
	}
	
	
	/***** Between here ***********/
	i = 0;
	while (!feof(FID))
	{
		fscanf(FID,"%i, %i, %i, %i, %i, %i, %i, %i, %i\n",&Users[i].UserID,&Users[i].Age,&Users[i].Gender,&Users[i].Marital,&Users[i].Race,&Users[i].BirthPlace,&Users[i].Language,&Users[i].Occupation,&Users[i].Income);
		printf("%i:  %i, %i, %i, %i, %i, %i, %i, %i, %i\n",i,Users[i].UserID,Users[i].Age,Users[i].Gender,Users[i].Marital,Users[i].Race,Users[i].BirthPlace,Users[i].Language,Users[i].Occupation,Users[i].Income);
		i++;
	}
	
	/********* And here, the DistMtrx is being overwritten **************/
	


	// Fill matrix with unnormalized distances
	for (y = 0; y < NumUsers; y++)
	{
		for (x = 0; x < NumUsers; x++)
		{
			DistMtrx[y][x] = Distance(&Users[y],&Users[x]);
			if (DistMtrx[y][x] > Max)
			{
				Max = DistMtrx[y][x];
			}
		}

	}
	printf("\n\n");
		for (y = 0; y < NumUsers; y++)
	{
		for (x = 0; x < NumUsers; x++)
		{
			printf("(%i,%i):   ",x,y);
			printf("%.1f     ",DistMtrx[y][x]);
		}
		printf("\n");
		
	}
	printf("%f",Max);
	printf("\n\n");
	
	// Normalize distances
	for (y = 0; y < NumUsers; y++)
	{
		for (x = 0; x < NumUsers; x++)
		{
			DistMtrx[y][x] = 1.0 - DistMtrx[y][x] / Max;
			printf("(%i,%i):   ",x,y);
			printf("%.3f     ",DistMtrx[y][x]);
		}
		printf("\n");
		
	}
	
	
	fclose(FID);
	return EXIT_SUCCESS;
}
