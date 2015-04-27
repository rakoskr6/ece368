#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>


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

void Query1(int UserID, double **DistMtrx, float d, int NumUsers)
{
	int y = 1;
	int Min = 100;
	float MinOut = 0;
	for (y = 1; y <= NumUsers; y++)
	{
		if ((DistMtrx[y][UserID] > d) && (DistMtrx[y][UserID] > 0))
		{
			if (DistMtrx[y][UserID] <= Min)
			{
				Min = DistMtrx[y][UserID];
			}
		}
		
	}	
	MinOut = (float)Min/100.0;
	printf("%.2f",MinOut);
	for (y = 1; y <= NumUsers; y++)
	{
		if (DistMtrx[y][UserID] == Min)
		{
			printf(",%i",y);
		}
	}
	printf("\n");
}


int MinDist(int *ShortDist, int *Included, int NumUsers)
{ // returns min disance of not yet processed verticies
	int Min = INT_MAX, MinIndex = 0, i;
	
	for (i = 1; i <= NumUsers; i++)
	{
		if ((Included[i] == 0) && (ShortDist[i] <= Min))
		{
			Min = ShortDist[i];
			MinIndex = i;
		}
	}
	return MinIndex;
}


double Dijkstras (int StartUser, int EndUser, double **DistMtrx, float d, int NumUsers)
{ // function to return distance from Start to End node
	int ShortDist[NumUsers + 1]; // shortest distance from StartUser to EndUser
	int Included[NumUsers + 1]; // 1 if value is finalized
	int i, x, y;
	
	for (i = 1; i <= NumUsers; i++)
	{ // initial distances
		ShortDist[i] = INT_MAX;
		Included[i] = 0;
	}
	ShortDist[StartUser] = 0;
	
	for (i = 1; i < NumUsers; i++)
	{
		x = MinDist(ShortDist, Included, NumUsers); // min distance vertex from unproccessed
		Included[x] = 1;
	
		for (y = 1; y <= NumUsers; y++)
		{
			if (!Included[y] && (DistMtrx[x][y] > d) && (ShortDist[x] != INT_MAX) && ((ShortDist[x] + DistMtrx[x][y]) < ShortDist[y]))
			{ // if not processed, edge exists, and smaller value exists, update shortest distance
				ShortDist[y] = ShortDist[x] + DistMtrx[x][y]; 
			}
		}
	
	}
	
	//printf("Distance from %i to %i is %i\n",StartUser,EndUser,ShortDist[EndUser]);
	return ShortDist[EndUser];
}


void Query2 (int UserID, double **DistMtrx, float d, int NumUsers, float a)
{
	int i = 1, NumNodes = 0;
	double Dist = 0;
	
	for (i = 1; i <= NumUsers; i++) // Finds distance from source to all nodes
	{
		if (i != UserID)
		{
			Dist = Dijkstras(UserID, i, DistMtrx, d, NumUsers);
			if (Dist < a)
			{
				NumNodes++; // found another node less than a
			}
		}
	}

	printf("%i\n",NumNodes);
}


void Query3 (int UserID, double **DistMtrx, float d, int NumUsers)
{
	int y = 1, Num = 0;
	for (y = 1; y <= NumUsers; y++)
	{
		if ((DistMtrx[y][UserID] > d) && (DistMtrx[y][UserID] > 0))
		{
			Num++;
		}
		
	}	
	printf("%i",Num);
	for (y = 1; y <= NumUsers; y++)
	{
		if ((DistMtrx[y][UserID] > d) && (DistMtrx[y][UserID] > 0))
		{
			printf(",%i",y);
		}
	}
	printf("\n");
}

void Query4 (int UserID, double **DistMtrx, float d, int NumUsers)
{
	int i = 1, Hops[NumUsers + 1], y = 1;
	
	for (i = 0; i <= NumUsers; i++)
	{
		Hops[i] = 0;
	}
	
	for (y = 1; y <= NumUsers; y++)
	{
		if ((DistMtrx[y][UserID] > d) && (DistMtrx[y][UserID] > 0))
		{
			for (i = 1; i <= NumUsers; i++)
			{
				if ((DistMtrx[y][i] > d) && (DistMtrx[y][i] > 0) && (i != UserID))
				{
					Hops[i] = 1;
				}
			}
		}
		
	}	
	y = 0;
	for (i = 0; i <= NumUsers; i++)
	{
		y += Hops[i];
	}
	
	printf("%i",y);
	
	for (i = 0; i <= NumUsers; i++)
	{
		if (Hops[i] == 1)
		{
			printf(",%i",i);
		}
	}
	printf("\n");
	
}

void Query5 (double **DistMtrx, float d, int NumUsers)
{
	double Average = 0;
	double CutAverage;
	int i = 1, y = 1, Num = 0;
	
	for (i = 1; i <= NumUsers; i++)
	{
		for (y = 1; y <= NumUsers; y++)
		{
			if ((DistMtrx[y][i] > d) && (DistMtrx[y][i] > 0))
			{
				Num++;
			}
			
		}	
	
		Average += Num;
		Num = 0;
	}
	Average = Average / NumUsers;
	CutAverage = floor(100.0 * Average) / 100;
	printf("%.2f\n",CutAverage);
}

void Query6 (double **DistMtrx, float d, int NumUsers)
{
	int UserID = 1;
	double Average = 0;
	double CutAverage;
	int i = 1, Hops[NumUsers + 1], y = 1;
	for (UserID = 1; UserID <= NumUsers; UserID++)
	{

		for (i = 0; i <= NumUsers; i++)
		{
			Hops[i] = 0;
		}
		
		for (y = 1; y <= NumUsers; y++)
		{
			if ((DistMtrx[y][UserID] > d) && (DistMtrx[y][UserID] > 0))
			{
				for (i = 1; i <= NumUsers; i++)
				{
					if ((DistMtrx[y][i] > d) && (DistMtrx[y][i] > 0) && (i != UserID))
					{
						Hops[i] = 1;
					}
				}
			}
		}	
		y = 0;
		for (i = 0; i <= NumUsers; i++)
		{
			y += Hops[i];
		}
		Average += (double)y;
	}
	Average = Average / (double)NumUsers;
	CutAverage = floor(100.0 * Average) / 100;
	printf("%.2f\n",CutAverage);
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
	int i = 1, x = 0, y = 0;
	int NumUsers, UserID;
	float d1, d2, a;
	double **DistMtrx, Max = 0;
	
	fscanf(FID,"%i, %f, %f, %i, %f\n",&NumUsers, &d1, &d2, &UserID, &a);
	//printf("\nInitial info:\n%i, %f, %f %i, %f\n\n",NumUsers, d1, d2, UserID, a);
	Users = malloc(sizeof(UserInfo) * (NumUsers + 1));
	

	//printf("Original file\n");
	while (!feof(FID))
	{
		fscanf(FID,"%i, %i, %i, %i, %i, %i, %i, %i, %i\n",&Users[i].UserID,&Users[i].Age,&Users[i].Gender,&Users[i].Marital,&Users[i].Race,&Users[i].BirthPlace,&Users[i].Language,&Users[i].Occupation,&Users[i].Income);
		//printf("%i:  %i, %i, %i, %i, %i, %i, %i, %i, %i\n",i,Users[i].UserID,Users[i].Age,Users[i].Gender,Users[i].Marital,Users[i].Race,Users[i].BirthPlace,Users[i].Language,Users[i].Occupation,Users[i].Income);
		i++;
	}
	

	// make matrix to store distances
	DistMtrx = malloc(sizeof(double) * (NumUsers + 1));
	for (i = 1; i <= NumUsers;  i++)
	{
		DistMtrx[i] = malloc(sizeof(double) * NumUsers );
	}

	// Fill matrix with unnormalized distances
	for (y = 1; y <= NumUsers; y++)
	{
		for (x = 1; x <= NumUsers; x++)
		{
			if (x == y)
			{
				DistMtrx[y][x] = -1;
			}
			else
			{
				DistMtrx[y][x] = Distance(&Users[y],&Users[x]);
				if (DistMtrx[y][x] > Max)
				{
					Max = DistMtrx[y][x];
				}
			}
		}

	}
	//printf("\nUnnormalized Distances\n");
	for (y = 1; y <= NumUsers; y++)
	{
		for (x = 1; x <= NumUsers; x++)
		{

			//printf("(%i,%i):   ",x,y);
			//printf("%.2f     ",DistMtrx[y][x]);
		}
		//printf("\n");
		
	}

	//printf("\nNormalized Distances\n");
	
	// Normalize distances
	for (y = 1; y <= NumUsers; y++)
	{
		for (x = 1; x <= NumUsers; x++)
		{
			if (x == y)
			{
				DistMtrx[y][x] = -1;
			}
			else
			{
				DistMtrx[y][x] = floor((1.0 - DistMtrx[y][x] / Max) * 100.0);
				
			}
			//printf("(%i,%i):   ",x,y);
			//printf("%.0f     ",DistMtrx[y][x]);
			
		
		}
		//printf("\n");
	}
	//printf("\n");
	d1 = floor(d1 * 100);
	d2 = floor(d2 * 100);
	a = floor(a * 100);
	
	
	Query1(UserID, DistMtrx, d1, NumUsers);
	Query2 (UserID, DistMtrx, d1, NumUsers, a);
	Query3(UserID,DistMtrx,d1,NumUsers);
	Query4 (UserID, DistMtrx, d1, NumUsers);
	Query5 (DistMtrx, d1, NumUsers);
	Query6 (DistMtrx, d1, NumUsers);
	
	printf("\n");
	
	Query1(UserID, DistMtrx, d2, NumUsers);
	Query2 (UserID, DistMtrx, d2, NumUsers, a);
	Query3(UserID,DistMtrx,d2,NumUsers);
	Query4 (UserID, DistMtrx, d2, NumUsers);
	Query5 (DistMtrx, d2, NumUsers);
	Query6 (DistMtrx, d2, NumUsers);
	
	printf("\n");
	
	
	fclose(FID);
	return EXIT_SUCCESS;
}
