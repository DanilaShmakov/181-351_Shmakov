#include <iostream>

void print(int *matrix[],  int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << '\n';
		for (int j = 0; j < columns; j++)
			std::cout << matrix[i][j] << " ";
	};
}
int main()
{
	int rows;
	int columns;
	std::cout << "Enter number of rows & columns: ";
	std::cin >> rows;
	std::cin >> columns;
	int **matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[columns];
	std::cout << "Enter elements ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cin >> matrix[i][j];
	};	
	print(matrix, rows,columns);
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
		std::cout << std::endl;
	system("pause");
	return 0;
}