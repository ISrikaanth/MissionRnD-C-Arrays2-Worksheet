/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int strcompare(char *a, char *b);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if ((A == NULL) || (B == NULL))
		return NULL;
	struct transaction * t;
	t = (struct transaction *)malloc(10 * sizeof(struct transaction));
	int i, j,k=0,m=0;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (strcompare(A[i].date,B[j].date)==1)
			{
				t[k].amount = A[i].amount;
				for (m = 0; m < 10;m++)
				   t[k].date[m] = A[i].date[m];
				t[k].date[m] = '\0';
				for (m = 0; m < 10; m++)
					t[k].description[m] = A[i].description[m];
				t[k].description[m] = '\0';
				k++;
			}
		}
	}
	if (k == 0)
		return NULL;
	return t;
}
int strcompare(char *a, char *b)
{
	int i = 0;
	while (i < 10)
	{
		if (a[i] != b[i])
			break;
		i++;
	}
	if (i >= 10)
		return 1;
	else
		return 0;
}