//Magic Square
#include<iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	
	if (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX))
	{
		if (checkUnique(arrayRow1, arrayRow2, arrayRow3, size))
		{
			if (checkRowSum(arrayRow1, arrayRow2, arrayRow3, size))
			{
				if (checkColSum(arrayRow1, arrayRow2, arrayRow3, size))
				{
					if (checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size))
					{
						showArray(arrayRow1, arrayRow2, arrayRow3, size);
						cout << "You have made a magic square!" << endl;
					}
					else
					{
						showArray(arrayRow1, arrayRow2, arrayRow3, size);
						cout << "You haven't made a magic square.";
					}
				}
				else
				{
					showArray(arrayRow1, arrayRow2, arrayRow3, size);
					cout << "You haven't made a magic square.";
				}
			}
			else
			{
				showArray(arrayRow1, arrayRow2, arrayRow3, size);
				cout << "You haven't made a magic square.";
			}
		}
		else
		{
			showArray(arrayRow1, arrayRow2, arrayRow3, size);
			cout << "You haven't made a magic square.";
		}
	}
	else
	{
		showArray(arrayRow1, arrayRow2, arrayRow3, size);
		cout << "You haven't made a magic square.";
	}
	
	return true;
}
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
	for (int x = 0; x < 2; x++)
	{
		if (arrayRow1[x] < min && arrayRow1[x] > max)
			return false;
		if (arrayRow2[x] < min && arrayRow2[x] > max)
			return false;
		if (arrayRow3[x] < min && arrayRow3[x] > max)
			return false;
		
	}
	return true;
}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int temp = 0;
	
	for (int x = 0; x < 2; x++)
	{
		if (temp != arrayRow1[x])
		{
			temp = arrayRow1[x];
		}
		else
			return false;
	}
	for (int y = 0; y < 2; y++)
	{
		if (temp != arrayRow2[y])
		{
			temp = arrayRow2[y];
		}
		else
			return false;


	}
	for (int x = 0; x < 2; x++)
	{
		if (temp != arrayRow3[x])
		{
			temp = arrayRow3[x];
		}
		else
			return false;
	}
	return true;
	
}
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	if ((arrayRow1[0] + arrayRow1[1] + arrayRow1[2]) == 15 && (arrayRow2[0] + arrayRow2[1] + arrayRow2[2]) == 15 && (arrayRow3[0] + arrayRow3[1] + arrayRow3[2]) == 15)
		return true;
	else
		return false;
}
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	if ((arrayRow1[0] + arrayRow2[0] + arrayRow3[0]) == 15 && (arrayRow1[1] + arrayRow2[1] + arrayRow3[1]) == 15 && (arrayRow1[2] + arrayRow2[2] + arrayRow3[2]) == 15)
		return true;
	else
		return false;
}
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	if ((arrayRow1[0] + arrayRow2[1] + arrayRow3[2]) == 15 && (arrayRow3[0] + arrayRow2[1] + arrayRow1[2]) == 15)
		return true;
	else
		return false;
}
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	for (int x = 0; x < 3; x++)
	{
		cout << "Enter the number for row 1 column " << x << ": ";
		cin >> arrayRow1[x];
	}
	for (int x = 0; x < 3; x++)
	{
		cout << "Enter the number for row 2 column " << x << ": ";
		cin >> arrayRow2[x];
	}
	for (int x = 0; x < 3; x++)
	{
		cout << "Enter the number for row 3 column " << x << ": ";
		cin >> arrayRow3[x];
	}
}
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	for (int x = 0; x < 3; x++)
	{
		cout << arrayRow1[x] << " ";
	}
	cout << endl;
	for (int x = 0; x < 3; x++)
	{
		cout << arrayRow2[x] << " ";
	}
	cout << endl;
	for (int x = 0; x < 3; x++)
	{
		cout << arrayRow3[x] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Welcome. Please enter in the numbers to build your magic square: " << endl;
	char userResponse;
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
	 fillArray( magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
	 showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
	 cout << endl;
	 isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

	 cout << "Would you like to try again? (Y/N): ";
	 cin >> userResponse;
	 while (userResponse == 'Y')
	 {
		 fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
		 showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
		 cout << endl;
		 isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
	 }
	 if (userResponse == 'N')
	 {
		 return 0;
	 }
	return 0;
}

