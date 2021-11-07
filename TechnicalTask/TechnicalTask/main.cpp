#include <iostream>
#include <vector>
using namespace std;

void Input(vector<vector<int>> &matrix, char type)
{
	vector<int> vTemp;
	switch (type)
	{
	case 'a': {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				vTemp.push_back(1);
				if (j == 9) { matrix.push_back(vTemp); }
			}
		}
		break;
	}case 'n': {
		for (int i = 0; i < 51; i++)
		{
			for (int j = 0; j < 51; j++)
			{
				vTemp.push_back(0);
				if (j == 50) { matrix.push_back(vTemp); }
			}
		}
		break;
	}
	case 'b': {
		int temp[10][10] = {
		{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }
		};
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				vTemp.push_back(temp[i][j]);
				
				if (j == 9) {matrix.push_back(vTemp);vTemp.clear();
				}
			}
		}
		break;
	}
	case 'c': {
		int temp[10][10] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		};
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				vTemp.push_back(temp[i][j]);

				if (j == 9) {
					matrix.push_back(vTemp); vTemp.clear();
				}
			}
		}
		break;
	}
	
	default: {
		int temp[2][2] = {
		{ 1, 1 },
		{ 1, 1 }
		};
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				vTemp.push_back(temp[i][j]);
				if (j == 1) { matrix.push_back(vTemp); }
			}
		}
		break;
	}
	}

}

bool Pathfinder(vector<vector<int>> &matrix, int currentPos[], vector<int*> &prevPos, int sizeR, int sizeC)
{
	bool R = false, L = false, U = false, D = false;
	prevPos.push_back(currentPos);
	const vector<vector <int>>::size_type pPSize = prevPos.size();
	if (matrix[currentPos[0] + 1][currentPos[1]] == 1) 
	{
		D = true;
		int temp[2] = { currentPos[0] + 1, currentPos[1] };
		for (int i = 0; i < pPSize; i++)
		{
			if (prevPos[i][0] == temp[0] && prevPos[i][1] == temp[1]) { D = 0;}
		}
		if(D != 0)
		{
			D = Pathfinder(matrix, temp, prevPos, sizeR, sizeC);
		}
	}
	if (matrix[currentPos[0] - 1][currentPos[1]] == 1) 
	{
		U = true;
		int temp[2] = { currentPos[0] - 1,currentPos[1] };
		for (int i = 0; i < pPSize; i++)
		{
			if (prevPos[i][0] == temp[0] && prevPos[i][1] == temp[1]) { U = 0;}
		}
		if (U != 0)
		{
			U = Pathfinder(matrix, temp, prevPos, sizeR, sizeC);
		}
	}
	if (matrix[currentPos[0]][currentPos[1] + 1] == 1) 
	{
		R = true;
		int temp[2] = { currentPos[0], currentPos[1] + 1 };
		for (int i = 0; i < pPSize; i++)
		{
			if (prevPos[i][0] == temp[0] && prevPos[i][1] == temp[1]) { R = 0;}
		}
		if (R != 0)
		{
			R = Pathfinder(matrix, temp, prevPos, sizeR, sizeC);
		}
	}
	if (matrix[currentPos[0]][currentPos[1] - 1] == 1) 
	{
		L = true;
		int temp[2] = { currentPos[0],currentPos[1] - 1 };
		for (int i = 0; i < pPSize; i++)
		{
			if (prevPos[i][0] == temp[0] && prevPos[i][1] == temp[1]) { L = 0;}
		}
		if (L != 0)
		{
			L = Pathfinder(matrix, temp, prevPos, sizeR, sizeC);
		}
	}
	if ((currentPos[0] == sizeR && currentPos[1] == sizeC) || D == 1 || U == 1 || L == 1 || R == 1 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool MazePathfinder(vector<vector<int>> &matrix)
{
	// first of all we should detect the invalid matrix data if it exists
	const vector<vector <int>>::size_type sizeRow = matrix.size();
	const vector<int>::size_type sizeColumn = matrix[0].size();
	if (sizeRow < 2 || sizeColumn < 2) { cout << "Maze size is too low" << endl; }
	if (sizeRow > 50 || sizeColumn > 50) { cout << "Maze size is too big" << endl; }
	if (matrix[sizeRow-1][sizeColumn-1] == 0) { cout << "Maze exit is invalid" << endl; }
	if (matrix[0][0] == 0) { cout << "Maze entrance is invalid" << endl; }
	
	//We created a '2' border for our matrix to ignore the out-of-bounds area during the algorithm execution
	vector <vector <int>> tmpMaze;
	for(int i = 0; i < sizeRow+2; i++)
	{
		vector <int> temp(sizeColumn + 2, 2);
		tmpMaze.push_back(temp);
	}
	for(int i = 1; i < sizeRow+1;i++)
		for (int j = 1; j < sizeColumn + 1; j++)
		{
			tmpMaze[i][j] = matrix[i - 1][j - 1];
		}
	vector <int*> previousPositions;
	// Start position
	int currentPosition[] = { 1, 1 };
	return Pathfinder(tmpMaze, currentPosition, previousPositions, sizeRow, sizeColumn);
}

int main()
{
	vector <vector <int>> matrix;
	/*Input function can fill the matrix with different number orders using such key-symbols:
	1. a - stands for "All". All maze fields are 1
	2. b - stands for "Basic". Represents maze in snake-ish style
	3. c - stands for "Custom". Enter your own pattern to test it via algorithm!
	4. n - "None". Too big and contains only 0
	*/
	Input(matrix, 'a');
	cout << MazePathfinder(matrix) << endl;
	system("pause");
	return 0;
}