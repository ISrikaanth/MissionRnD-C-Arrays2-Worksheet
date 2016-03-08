/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int strcompare1(char *a, char *b);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if ((A == NULL) || (B == NULL))
		return NULL;
	struct transaction *t;
	t = (struct transaction *)malloc(30 * sizeof(struct transaction));
	int i = 0, j = 0,k=0,m=0;
	while ((i < ALen) && (j < BLen))
	{
		if ((strcompare1(A[i].date, B[j].date) == 0))
		{
			t[k].amount = A[i].amount;
			for (m = 0; m < 10; m++)
				t[k].date[m] = A[i].date[m];
			t[k].date[m] = '\0';
			for (m = 0; m < 10; m++)
				t[k].description[m] = A[i].description[m];
			t[k].description[m] = '\0';
			k++;
			i++;
		}
		else
		{
			t[k].amount = B[j].amount;
			for (m = 0; m < 10; m++)
				t[k].date[m] = B[j].date[m];
			t[k].date[m] = '\0';
			for (m = 0; m < 10; m++)
				t[k].description[m] = B[j].description[m];
			t[k].description[m] = '\0';
			k++;
			j++;
		}
	}
	while (i < ALen)
	{
		t[k].amount = A[i].amount;
		for (m = 0; m < 10; m++)
			t[k].date[m] = A[i].date[m];
		t[k].date[m] = '\0';
		for (m = 0; m < 10; m++)
			t[k].description[m] = A[i].description[m];
		t[k].description[m] = '\0';
		k++;
		i++;
	}
	while (j < BLen)
	{
		t[k].amount = B[j].amount;
		for (m = 0; m < 10; m++)
			t[k].date[m] = B[j].date[m];
		t[k].date[m] = '\0';
		for (m = 0; m < 10; m++)
			t[k].description[m] = B[j].description[m];
		t[k].description[m] = '\0';
		k++;
		j++;
	}
	return t;
}
int strcompare1(char *a, char *b)
{
	int d1 = 0, m1 = 0, yr1 = 0, d2 = 0, m2 = 0, yr2 = 0,i=0;
	while (a[i] != '-')
	{
		d1 = (d1 * 10) + (a[i] - '0');
		i++;
	}
	i++;
	while (a[i] != '-')
	{
		m1 = (m1 * 10) + (a[i] - '0');
		i++;
	}
	i++;
	while (a[i] != '\0')
	{
		yr1 = (yr1 * 10) + (a[i] - '0');
		i++;
	}
	i = 0;
	while (b[i] != '-')
	{
		d2 = (d2 * 10) + (b[i] - '0');
		i++;
	}
	i++;
	while (b[i] != '-')
	{
		m2 = (m2 * 10) + (b[i] - '0');
		i++;
	}
	i++;
	while (b[i] != '\0')
	{
		yr2 = (yr2 * 10) + (b[i] - '0');
		i++;
	}
	if (yr1 < yr2)
		return 0;
	else if (yr1 > yr2)
		return 1;
	else if (m1 < m2)
		return 0;
	else if (m1 > m2)
		return 1;
	else if (d1 < d2)
		return 0;
	else if (d1 > d2)
		return 0;
	else
		return 0;
}