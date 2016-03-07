/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int i = 0, count = 0, year = 0, month = 0, dat = 0, j = 0, year1 = 0, month1 = 0, dat1 = 0;
	while (date[j] != '-')
	{
		dat1 = (dat1 * 10) + (date[j] - '0');
		j++;
	}
	j++;
	while (date[j] != '-')
	{
		month1 = (month1 * 10) + (date[j] - '0');
		j++;
	}
	j++;
	while (date[j] != '\0')
	{
		year1 = (year1 * 10) + (date[j] - '0');
		j++;
	}
	j = 0;
	for (i = 0; i < len; i++)
	{
		while (date[j] != '-')
		{
			dat = (dat * 10) + ((Arr[i].date[j]) - '0');
			j++;
		}
		j++;
		while (date[j] != '-')
		{
			month = (month * 10) + ((Arr[i].date[j]) - '0');
			j++;
		}
		j++;
		while (date[j] != '\0')
		{
			year = (year * 10) + ((Arr[i].date[j]) - '0');
			j++;
		}
		if (year > year1)
			count = count + 1;
		else if ((month > month1) && (year == year1))
			count = count + 1;
		else if ((dat > dat1) && (month == month1) && (year == year1))
			count = count + 1;
		j = 0;
		dat = month = year = 0;
	}
	return count;
}
