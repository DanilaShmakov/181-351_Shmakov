#include <iostream>
#include <string>
/* A - 65; Z -90
a - 97; z - 122 */

// Cesar

char user_text[256];
void encrypt()
{
	std::cout << "Enter your text\n";
	std::cin.getline(user_text, 256, '\n');
	int n;
	n = strlen(user_text);
	for (int i = 0; i < n; i++)
	{
		if (((static_cast<int>(user_text[i]) >= 97) && (static_cast<int>(user_text[i]) <= 119))
			|| ((static_cast<int>(user_text[i]) >= 65) && (static_cast<int>(user_text[i]) <= 87)))
		{
			user_text[i] += 3;
		}
		else if (((static_cast<int>(user_text[i]) > 119) && (static_cast<int>(user_text[i]) < 123))
			|| ((static_cast<int>(user_text[i]) > 87) && (static_cast<int>(user_text[i]) < 91)))
		{
			 user_text[i] -= 22;
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << user_text[i];
	}
	std::cout << std::endl;
}
/* A - 65; Z -90
a - 97; z - 122 */
void decode()
{
	std::cout << "Enter your text\n";
	std::cin.getline(user_text, 256, '\n');
	int n;
	n = strlen(user_text);
	for (int i = 0; i < n; i++)
	{
		if (((static_cast<int>(user_text[i]) >= 100) && (static_cast<int>(user_text[i]) <= 122))
			|| ((static_cast<int>(user_text[i]) >= 68) && (static_cast<int>(user_text[i]) <= 90)))
		{
			user_text[i] -= 3;
		}
		else if (((static_cast<int>(user_text[i]) >= 97) && (static_cast<int>(user_text[i]) < 100))
			|| ((static_cast<int>(user_text[i]) >= 65) && (static_cast<int>(user_text[i]) < 68)))
		{
			user_text[i] += 22;
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << user_text[i];
	}
	std::cout << std::endl;
}

// Bubble

void bubble(int *arr, int size)
{
	int count(0); // счетчик перемещений
	int temp; // временная переменная для обмена элементов местами

	   // Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
			}
		}
	}
	for (int i = 0; i < size; i++) // вывод отсортированного массива
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "Number of changes: " << count << std::endl;
};

// Shaker

void shaker(int *arr, int size)
{
	int count(0); // счетчик перемещений 
	int left{ 0 }, right{ size - 1 };// левая и правая границы
	bool flag(true);// имеются ли перемещения элементов
	while ((left <right) && (flag))
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (arr[i] > arr[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				int t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				count++;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (arr[i - 1] > arr[i]) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				int t = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = t;
				count++;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	for (int i = 0; i < size; i++) // вывод отсортированного массива
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "Number of changes: " << count << std::endl;
}
int main()
{
	int *arr;
	arr = 0;
	bool exit(true);
	int x;
	while (exit)
	{
		std::cout << "1. Encrypt\n";
		std::cout << "2. Decode\n";
		std::cout << "3. Enter the array\n";
		std::cout << "4. Bubble_sorting\n";
		std::cout << "5. Shaker_sorting\n";
		std::cout << "6. Cleaning the console\n";
		std::cout << "0. Exit\n";
		std::cin >> x;
		std::cin.get();
		switch (x)
		{
		case 1:
			encrypt();
			break;
		case 2:
			decode();
			break;
		case 3:
			int size;
			std::cout << "Enter a size of array\n";
			std::cin >> size;
			arr = new int[size]; // выделение памяти под массив
			for (int i = 0; i < size; i++) // заполнение массива
			{
				std::cout << "arr[" << i << "] = ";
				std::cin >> arr[i];
			}
			break;
		case 4:
			bubble(arr, size);
			break;
		case 5:
			shaker(arr, size);
			break;
		case 6:
			system("cls");
			break;
		case 0:
			exit = false;
			break;
		default:
			std::cout << "Wrong number!\n";
			break;
		delete[] arr;
		};
	}
//	system("pause");
}