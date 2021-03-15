#include <iostream>
#include <stdlib.h>     /* abs */
using namespace std;
int n;
int board[50][50] = { 0 };

void printBoard()
{
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << board[r][c] << " ";
		}
		cout << endl;
	}
}
bool isSafe(int row, int col)
{
	if (col >= n || row >= n) { return false; }

	//check the cell it self
	if (board[row][col] != 0) { return false; }

	//check row and column elemnts 
	for (int i = 0; i < n; i++)
	{
		if (board[row][i] != 0 || board[i][col] != 0) { return false; }
	}

	//checking diagonal on the left top 
	int checkRow = row - 1;
	int checkCol = col - 1;
	while (checkRow >= 0 && checkCol >= 0)
	{
		if (board[checkRow][checkCol] != 0) { return false; }
		checkRow--;
		checkCol--;
	}

	//check right bottom diagonal
	checkRow = row + 1;
	checkCol = col + 1;
	while (checkRow < n && checkCol < n)
	{
		if (board[checkRow][checkCol] != 0) { return false; }
		checkRow++;
		checkCol++;
	}

	//check right top diagonal
	checkRow = row - 1;
	checkCol = col + 1;
	while (checkRow >= 0 && checkCol < n)
	{
		if (board[checkRow][checkCol] != 0) { return false; }
		checkRow--;
		checkCol++;
	}

	//check left bottom diagonal
	checkRow = row + 1;
	checkCol = col - 1;
	while (checkRow < n && checkCol >= 0)
	{
		if (board[checkRow][checkCol] != 0) { return false; }
		checkRow++;
		checkCol--;
	}

	return true; //is safe
}
bool backtrack(int remQueen)
{
	if (remQueen == 0) { return true; }
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (isSafe(r, c))
			{
				board[r][c] = 1;
				if (backtrack(remQueen - 1)) { return true; };
				board[r][c] = 0;
			}
		}
	}
	return false;
}

void main()
{
	while (true) {
		cout << " Enter number of queens (at most 50):" << endl;
		cin >> n;
		cout << endl;
		if (backtrack(n))
		{
			cout << "solution found" << endl;
			printBoard();
		}
		else
		{
			cout << "no solution exists" << endl;
		}
	}
	int pause;
	cin >> pause;

}