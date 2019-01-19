#include <iostream>


#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 
#include <string> 
#include <cstring> 
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива

using namespace std;



/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).
	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.
	Достоинство: операции удаления и добавления элемента делаются за const время.

std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
int i = 0, a = 0;
std::cout « "Введите 5 целых чисел: " « std::endl;
while (i != 5) {
	std::cin » a;
	stackInt.push(a); // добавляем введенное число
	i++;
}
if (stackInt.empty()) // проверяем пуст ли стек (нет)
std::cout « "Стек не пуст";
std::cout « "Верхний элемент стека: " « stackInt.top() « std::endl;
stackInt.pop(); // удаляем верхний элемент
std::cout « "Новый верхний элемент: " « stackInt.top()« std::endl;*/
/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/

	/*std::queue <int> MyQueue; // создали очередь
	std::cout « "Введите 7 чисел: " « std::endl;
	for (i = 0; i < 7; i++) {
		std::cin » a;
		MyQueue.push(a); // добавляем в очередь элементы
	}
	std::cout « std::endl;
	std::cout « "Первый элемент в очереди: " « MyQueue.front() « std::endl;
	MyQueue.pop(); // удаляем элемент из очереди
	std::cout « "Первый элемент (после удаления): " « MyQueue.front() « std::endl;
	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
		std::cout « "Очередь не пуста!";
	/*
	Очередь с приоритетом (priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/

	/*	std::priority_queue <int> priority_q; // объявляем приоритетную очередь
		std::cout « "Введите 7 чисел: " « std::endl;
		for (i = 0; i < 7; i++) {
			std::cin » a;
			priority_q.push(a); // добавляем элементы в очередь
			std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
		}
		// выводим первый
		std::cout « "Первый элемент очереди: " « priority_q.top();
		queue*/
int main()
{
	setlocale(LC_ALL, "rus");
	// Задание 1 ////////////////////////////////////////////////////////////////////////////////////////////
  /*{cout << "Задание 1" << endl;
  stack <int> stack1;
  string s1;
  int i = 0;
  cout << "введите выражение" << endl;
  cin >> s1;
  while (s1[i])
  {
	  if (s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
	  {
		  stack1.push(s1[i]);
	  }
	  if ((!stack1.empty()) && // оечередь пуста = true
		  (((s1[i] == ')')  && (stack1.top() == '(')) ||
		  ((s1[i] == '}')   && (stack1.top() == '{'))  ||
		  ((s1[i] == ']')   && (stack1.top() == ']')))
		  )
	  {
		  cout << "Condition is true\n";
		  stack1.pop();
	  }
	  i++;
  };
  if (stack1.empty())
  {
	  cout << "скобки расставлены  правильно\n";
  }
  else
  {
	  cout << "скобки расставлены неправильно\n";

  }
  }*/
  // Задание 2 ////////////////////////////////////////////////////////////////////////////////////////////
 /*{
	 cout << "Задание 2" << endl;
	 queue <string> nine;
	 queue <string> ten;
	 queue <string> eleven;
	 int n = 0;
	 int sizenine = 0;
	 int sizeten = 0;
	 int sizeeleven = 0;
	 string s2;// = { '\n' };
	 cout << "введите количество учеников " << endl;
	 cin >> n;
	 for (int i = 0; i < n + 1; i++)
	 {
		 if (i)
		 cout << i << "ученик " << endl;
		 cout << "Номер класса, пробел, фамилия " << endl;
		 s2.clear();
		 cin.clear();
	 //	while (cin.get() != '\n') {}; возможно очистка потока
		 cout << s2 << endl;
			 getline(cin, s2);  //cin >> s2; при таком варианте эта бандура не берет пробелы
		 if (s2[0] == '1')
		 {
			 if (s2[1] == '0')
			 {
				 ten.push(s2);
				 sizeten++;

			 }
			 else
			 {
				 eleven.push(s2);
				 sizeeleven++;

			 }
		 }
		 if (s2[0] == '9')
		 {
			 nine.push(s2);
			 sizenine++;

		 }
	 }

	 cout << "9 класс" << endl;
	 for (int j = 0; j < sizenine; j++)
	 {
		 cout << nine.front() << endl;
		 nine.push(nine.front());
		 nine.pop();
	 };
	 cout << "10 класс" << endl;
	 for (int j = 0; j < sizeten; j++)
	 {
		 cout << ten.front() << endl;
		 ten.push(ten.front());
		 ten.pop();
	 };
	 cout << "11 класс" << endl;
	 for (int j = 0; j < sizeeleven; j++)
	 {
		 cout << eleven.front() << endl;
		 eleven.push(eleven.front());
		 eleven.pop();
	 };
 }*/

 // Задание 3 ////////////////////////////////////////////////////////////////////////////////////////////
/*
Проверить, является ли введенная строка палиндромом
(читается одинаково слева направо и справа налево). Использовать дек.
*/
/*
Считываем строку посимвольно. каждый символ добавляем в хвост дека.
Далее сравниваем первый и последний символ дека.
*/
/*Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
называется структура данных, в которую можно
удалять и добавлять элементы
как в начало, так и в конец.
Дек хранится в памяти так же, как и очередь.
*/

//{	
//	cout << "Задание 3" << endl;
//	deque <char> poly;
//	char mos[] = { 0 };
//	int i = 0;
//	bool ok = true;
//	cout << "Введите слово\n";
//	cin >> mos;
//	while (mos[i] != '\0') {
//		poly.push_back(mos[i]);
//		i++;
//	}
//	while (!poly.empty()) {
//		if ((poly.front() == poly.back()) && (poly.size() > 1))
//		{
//			poly.pop_front();
//			poly.pop_back();
//		}
//		else if (poly.front() == poly.back())
//		{
//			poly.pop_front();
//		}
//		else {
//			ok = false;
//			break;
//		}
//	}
//	if (ok)
//	{
//		cout << "Полиндром\n";
//	}
//	else
//		cout << "Не полиндром\n";
//};
//ЗАДАЧА 4 //////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Описать структуру данных List.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление,
сортировка.
//*/
//	{
//		// Задание 4 (list) ////////////////////////////////////////////////////
//		{std::list<int> myList;
//		int a;
//		for (int i = 0; i < 4; i++) {
//			std::cin >> a;
//			if (i == 0) {
//				myList.push_front(a);
//			}
//			else myList.push_back(a);
//		}
//		myList.sort();
//		myList.pop_front();
//		myList.pop_back();
//		for (std::list<int>::iterator i = myList.begin(); i != myList.end(); i++) {
//			std::cout << *i;
//
//			myList.clear();
//		}
//		}
		//Задание 5 (set) ////////////////////////////////////////////////////////////
		//ЗАДАЧА 5 
	/*
	Описать структуру данных Set.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление.
	//*/
	//	{	std::set<int> mySet;
	//	int a;
	//	for (int i = 0; i < 5; i++) {
	//		std::cin >> a;
	//		mySet.insert(a);
	//	}
	//	for (std::set<int>::iterator i = mySet.begin(); i != mySet.end(); i++) {
	//		std::cout << *i << ' ';
	//	}
	//	mySet.erase(3);
	//	std::cout << std::endl;
	//	for (std::set<int>::iterator i = mySet.begin(); i != mySet.end(); i++) {
	//		std::cout << *i << ' ';
	//	}
	//	}


		//ЗАДАЧА 6 
		/*
		Описать структуру данных map.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление.
		*/
		/*std::map — отсортированный ассоциативный контейнер,
		который содержит пары ключ-значение с неповторяющимися ключами.*/

		/*
		char c;
		std::map <char, int> myMap;
		std::map<char, int>::iterator mm;
		for (int i = 0, c = 'a'; i < 5; ++i, ++c)
		{
			myMap.insert(std::pair<char, int>(c, i));
		}
		///вывод не явно инициализированной map на экран
		for (auto it = myMap.begin(); it != myMap.end(); ++it)
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
		}
		std::cout << std::endl;
		mm = myMap.find('b');
		std::cout <<"заменим с-й элемент  " << std::endl;
		myMap.erase('c'); //удаление
		myMap.insert(mm, std::pair<char, int>('c', 200)); //добавление
		for (auto it = myMap.begin(); it != myMap.end(); ++it)
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
		}*/

		// ЗАДАЧА 7 
		/*
		Составить таблицу сравнения по времени выполнения операций
		для дека, стека, очереди, списка, множества, массива из n элементов.
		Список операций:
		добавление в начало
		добавление в конец
		добавление в середину
		удаление из начала
		удаление с конца
		удаление из середины
		значение элемента из начала
		значение элемента с конца
		значение элемента из середины
		system("pause");
		return 0;
		}*/
		system("pause");
	}