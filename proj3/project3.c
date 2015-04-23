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
	
	TempSum = pow((First->Age - Second->Age),2);
	TempSum = pow((First->Gender - Second->Gender),2) + TempSum;
	TempSum = pow((First->Marital - Second->Marital),2) + TempSum;
	TempSum = pow((First->Race - Second->Race),2) + TempSum;
	TempSum = pow((First->BirthPlace - Second->BirthPlace),2) + TempSum;
	TempSum = pow((First->Language - Second->Language),2) + TempSum;
	TempSum = pow((First->Occupation - Second->Occupation),2) + TempSum;
	TempSum = pow((First->Income - Second->Income),2) + TempSum;

	return sqrt(TempSum);
}

void Query1 (int UserID, double **DistMtrx, float d, int NumUsers)
{
	int y = 0;
	double Min = 1.0;
	for (y = 0; y < NumUsers; y++)
	{
		if (DistMtrx[y][UserID] > d)
		{
			if (DistMtrx[y][UserID] <= Min)
			{
				Min = DistMtrx[y][UserID];
			}
		}
		
	}	
	printf("%f",Min);
	for (y = 0; y < NumUsers; y++)
	{
		if (DistMtrx[y][UserID] == Min)
		{
			printf(", %i",y+1);
		}
	}
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
	int NumUsers, UserID;
	float d1, d2, a;
	double **DistMtrx, Max = 0;
	
	fscanf(FID,"%i, %f, %f, %i, %f\n",&NumUsers, &d1, &d2, &UserID, &a);
	printf("\nInitial info:\n%i, %f, %f %i, %f\n\n",NumUsers, d1, d2, UserID, a);
	Users = malloc(sizeof(UserInfo) * NumUsers);
	

	printf("Original file\n");
	while (!feof(FID))
	{
		fscanf(FID,"%i, %i, %i, %i, %i, %i, %i, %i, %i\n",&Users[i].UserID,&Users[i].Age,&Users[i].Gender,&Users[i].Marital,&Users[i].Race,&Users[i].BirthPlace,&Users[i].Language,&Users[i].Occupation,&Users[i].Income);
		printf("%i:  %i, %i, %i, %i, %i, %i, %i, %i, %i\n",i,Users[i].UserID,Users[i].Age,Users[i].Gender,Users[i].Marital,Users[i].Race,Users[i].BirthPlace,Users[i].Language,Users[i].Occupation,Users[i].Income);
		i++;
	}
	

	// make matrix to store distances
	DistMtrx = malloc(sizeof(double) * NumUsers);
	for (i = 0; i < NumUsers;  i++)
	{
		DistMtrx[i] = malloc(sizeof(double) * NumUsers );
	}

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
	printf("\nUnnormalized Distances\n");
	for (y = 0; y < NumUsers; y++)
	{
		for (x = 0; x < NumUsers; x++)
		{
			printf("(%i,%i):   ",x,y);
			printf("%.1f     ",DistMtrx[y][x]);
		}
		printf("\n");
		
	}

	printf("\nNormalized Distances\n");
	
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
	printf("\n");
	Query1(1, DistMtrx, .5, NumUsers);
	printf("\n");
	
	
	fclose(FID);
	return EXIT_SUCCESS;
}
