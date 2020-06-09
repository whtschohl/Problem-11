//Hans Tschohl Problem 11
//====================================================================================

#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float calculateAngle(float A, float B, float Distance)
{
	float out, fA, d;

	d = Distance;
	fA = B - A;
	if (fA < 0)
		fA = fA * (-1);


	out = atan(fA / d);
	return out;
}

int main(void)
{
	// File Handeling
	FILE* pFile = fopen("Problem11in.txt", "r");
	if (pFile == NULL)
	{
		printf("File not found");
		return EXIT_FAILURE;
	}
	
	int	iRowAndCol, i, j;
	float fMaxSlope = 0, fAngle, fHeight, fInitialHeight = 0, a, c;
	
	if (fscanf(pFile, "%d\n", &iRowAndCol) != 1)
		return EXIT_FAILURE;

	float fValues[9][9];

	for (i = 0; i < iRowAndCol; i++)
	{
		for (j = 0; j < iRowAndCol; j++)
		{
			if (fscanf(pFile, "%f/n", &fHeight) != 1)
				return EXIT_FAILURE;
			fValues[i][j] = fHeight;
		}
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d ", fValues[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < iRowAndCol; i++)
	{
		for ( j=0; j < iRowAndCol; j++)
		{
			if (j < iRowAndCol)
			{
				fAngle = calculateAngle(fValues[i][j], fValues[i][j + 1], 1);
				if (fAngle > fMaxSlope)
					fMaxSlope = fAngle;
			}

			if (i < iRowAndCol)
			{
				fAngle = calculateAngle(fValues[i][j], fValues[i + 1][j], 1);
				if (fAngle > fMaxSlope)
					fMaxSlope = fAngle;
			}
			
			if ((i && j) < iRowAndCol)
			{
				fAngle = calculateAngle(fValues[i + 1][j + 1], fValues[i][j], sqrt(2));
				if (fAngle > fMaxSlope)
					fMaxSlope = fAngle;
			}
		}
	}

	fMaxSlope = fMaxSlope * 180 / M_PI;
	printf("Max Angle is %f degrees", fMaxSlope);
}



