/*"создать класс матриц matrix размера т*п, 1<=т<=10/ 1<=п<=10/ с операциями
1) сложение bool summMatrix{ matrix matr2);
a b + k 1 = a + k b + 1
c d m n c + m d + n
верно, размерь: матриц совпадают
2) умножение bool muitMatrix(matrix matr2);
all al2 al3 bll bl2 ell cl2
a21 a22 a23 * b21 b22 = c21 c22
b31 b32
c21 = a21 * bll + a22 * b21 + a23 * b31 cij = ail * blj + ai2 * b2j + ... + ain * bnj верно, если columns(a) = rows(b)
3) транспонирование bool transpO;
all al2 a!31 *
a21 a22 a23I
al3 a23
4) печать bool print();
5) ввод с клавиатуры bool input();
создать класс - наследник вектор vector, длиной n, 1 <= п <= 10, с дополнительными операциями
1) как оказалось нужно не скалярное, а векторное умножение, по формуле a*b = (a2b3 - a3b2; a3b1 - a1b3; a1b2 - b2a1;)
2) умножение вектора на число(al а2 a3)*k = < а1*к а2*к аЗ*к)"
*/
#include <iostream>

class matrix {
protected:
	double matr[10][10];
	int rows, columns;
public:
	matrix();
	~matrix();
	matrix(int m_rows, int m_columns)
	{
		rows = m_rows; columns = m_columns;
	}
	int getRows() { return rows; }
	int getColumns() { return columns; }
	double getElem(int row, int col)
	{
		if (row < rows && col < columns && row > -1 && col > -1)
		{
			return matr[row][col];
		}
		else
		{
			std::cout << "Cannot get element. Index error!\n";
			return -1;
		}
	}
	
	bool summMatrix(matrix matr2)// сумма матриц
	{
		if (matr2.getRows() != rows || matr2.getColumns() != columns) // проверка сорозмерности матриц
		{
			std::cout << "Invalid size!";
			return false;
		}
		else
		{
			for (int i = 0; i < rows; i++)// сложение
			{
				for (int j = 0; j < columns; j++)
				{
					matr[i][j] += matr2.getElem(i, j);
				}
			}
			return true;
		} 

	}
	bool multMatrix(matrix matr2) // произведение
	{
		double matr3[10][10];
		if (columns == matr2.getRows()) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < matr2.getColumns(); j++) {
					double sum = 0;
					for (int k = 0; k < columns; k++) {
						sum += matr[i][k] * matr2.getElem(k, j);
					}
					matr3[i][j] = sum;
				}
			}
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					matr[i][j] = 0;
				}
			}
			columns = matr2.getColumns();
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					matr[i][j] = matr3[i][j];
				}
			}

			return true;
		}
		else {
			return false;
		}
	}
	bool transp()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = i; j < rows; j++)
			{
				double tmp = matr[i][j];
				matr[i][j] = matr[j][i];
				matr[j][i] = tmp;
			}
		}
		print();
		return true;
	}
	bool print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << matr[i][j] << '\t';
			}
			std::cout << '\n';
		}
		return true;
	}
	bool input()
	{
		std::cout << "Enter number of rows: ";
		std::cin >> rows;
		if (rows < 1 || rows > 10)
		{
			std::cout << "Invalid value!";
			return false;
		}
		std::cout << "Enter number of columns: ";
		std::cin >> columns;
		if (columns < 1 || columns > 10)
		{
			std::cout << "Invalid value!";
			return false;
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cin >> matr[i][j];
			}
		}
	}
};

class  vector :public matrix
{
public:
	vector() { columns = 1; }
	bool multVec(vector vec2);
};
bool vector::multVec(vector vec2)
{
	int scal = 0;
	if (rows == vec2.getRows())
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < 1; j++)
			{
				scal = scal + matr[i][j] * vec2.getElem(i, j);
			}
		std::cout << scal;
		return true;
	}
	else {
		std::cout << "error";
		return false;
	}
}



int main()
{
	matrix matrA, matrB;
	vector vec1;
	vector vec2;
	vec1.multVec(vec2);
	vec1.print();
	matrA.input();
	matrB.input();
	matrA.print();
	matrA.transp(); 
	matrA.summMatrix(matrB); matrA.print();
	matrA.multMatrix(matrB); matrA.print();
	system("pause");
	return 0;
}
matrix::matrix() {}
matrix::~matrix() {}