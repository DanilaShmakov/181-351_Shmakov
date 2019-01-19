#include <iostream>


#include <stack> // ���������� ���������� ��� ������������� ����� 
#include <queue> // ���������� ���������� ��� ������������� ������� 
#include <deque> // ���������� ���������� ��� ������������� ���� 
#include <string> 
#include <cstring> 
#include <list> // ���������� ���������� ��� ������������� ������
#include <set> // ���������� ���������� ��� ������������� ���������
#include <map> // ���������� ���������� ��� ������������� �������������� �������

using namespace std;



/*
	���� � ��� ��������� ������, ������� ��������
	�� �������� FILO(first in � last out; ������ ������ � ��������� ����).
	� ����� ��� ��������,�.�. ������ ���������� � ������������� ��������.
	������ ������� ����� ��������� �� ��������� �������.
	�������� ������� ��������� �� NULL.
	�����������: �������� �������� � ���������� �������� �������� �� const �����.

std::stack<int> stackInt;//stack <��� ������> <���>; -�������� �����
int i = 0, a = 0;
std::cout � "������� 5 ����� �����: " � std::endl;
while (i != 5) {
	std::cin � a;
	stackInt.push(a); // ��������� ��������� �����
	i++;
}
if (stackInt.empty()) // ��������� ���� �� ���� (���)
std::cout � "���� �� ����";
std::cout � "������� ������� �����: " � stackInt.top() � std::endl;
stackInt.pop(); // ������� ������� �������
std::cout � "����� ������� �������: " � stackInt.top()� std::endl;*/
/*
	������� � ��� ��������� ������, ������� ��������� �� ��������
	LILO (last in � last out: ��������� ������ � ��������� �����).
	*/

	/*std::queue <int> MyQueue; // ������� �������
	std::cout � "������� 7 �����: " � std::endl;
	for (i = 0; i < 7; i++) {
		std::cin � a;
		MyQueue.push(a); // ��������� � ������� ��������
	}
	std::cout � std::endl;
	std::cout � "������ ������� � �������: " � MyQueue.front() � std::endl;
	MyQueue.pop(); // ������� ������� �� �������
	std::cout � "������ ������� (����� ��������): " � MyQueue.front() � std::endl;
	if (!MyQueue.empty()) // ��������� ����� �� ������� (���)
		std::cout � "������� �� �����!";
	/*
	������� � ����������� (priority_queue) � ��� ������� �������,
	�� � ��� ����� ������� ����������� � ����� �����,
	����� ������� ���� ������������� �� ��������.
	*/

	/*	std::priority_queue <int> priority_q; // ��������� ������������ �������
		std::cout � "������� 7 �����: " � std::endl;
		for (i = 0; i < 7; i++) {
			std::cin � a;
			priority_q.push(a); // ��������� �������� � �������
			std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
		}
		// ������� ������
		std::cout � "������ ������� �������: " � priority_q.top();
		queue*/
int main()
{
	setlocale(LC_ALL, "rus");
	// ������� 1 ////////////////////////////////////////////////////////////////////////////////////////////
  /*{cout << "������� 1" << endl;
  stack <int> stack1;
  string s1;
  int i = 0;
  cout << "������� ���������" << endl;
  cin >> s1;
  while (s1[i])
  {
	  if (s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
	  {
		  stack1.push(s1[i]);
	  }
	  if ((!stack1.empty()) && // �������� ����� = true
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
	  cout << "������ �����������  ���������\n";
  }
  else
  {
	  cout << "������ ����������� �����������\n";

  }
  }*/
  // ������� 2 ////////////////////////////////////////////////////////////////////////////////////////////
 /*{
	 cout << "������� 2" << endl;
	 queue <string> nine;
	 queue <string> ten;
	 queue <string> eleven;
	 int n = 0;
	 int sizenine = 0;
	 int sizeten = 0;
	 int sizeeleven = 0;
	 string s2;// = { '\n' };
	 cout << "������� ���������� �������� " << endl;
	 cin >> n;
	 for (int i = 0; i < n + 1; i++)
	 {
		 if (i)
		 cout << i << "������ " << endl;
		 cout << "����� ������, ������, ������� " << endl;
		 s2.clear();
		 cin.clear();
	 //	while (cin.get() != '\n') {}; �������� ������� ������
		 cout << s2 << endl;
			 getline(cin, s2);  //cin >> s2; ��� ����� �������� ��� ������� �� ����� �������
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

	 cout << "9 �����" << endl;
	 for (int j = 0; j < sizenine; j++)
	 {
		 cout << nine.front() << endl;
		 nine.push(nine.front());
		 nine.pop();
	 };
	 cout << "10 �����" << endl;
	 for (int j = 0; j < sizeten; j++)
	 {
		 cout << ten.front() << endl;
		 ten.push(ten.front());
		 ten.pop();
	 };
	 cout << "11 �����" << endl;
	 for (int j = 0; j < sizeeleven; j++)
	 {
		 cout << eleven.front() << endl;
		 eleven.push(eleven.front());
		 eleven.pop();
	 };
 }*/

 // ������� 3 ////////////////////////////////////////////////////////////////////////////////////////////
/*
���������, �������� �� ��������� ������ �����������
(�������� ��������� ����� ������� � ������ ������). ������������ ���.
*/
/*
��������� ������ �����������. ������ ������ ��������� � ����� ����.
����� ���������� ������ � ��������� ������ ����.
*/
/*����� (����. deque � ������������ �� double-ended queue, ������������� �������)
���������� ��������� ������, � ������� �����
������� � ��������� ��������
��� � ������, ��� � � �����.
��� �������� � ������ ��� ��, ��� � �������.
*/

//{	
//	cout << "������� 3" << endl;
//	deque <char> poly;
//	char mos[] = { 0 };
//	int i = 0;
//	bool ok = true;
//	cout << "������� �����\n";
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
//		cout << "���������\n";
//	}
//	else
//		cout << "�� ���������\n";
//};
//������ 4 //////////////////////////////////////////////////////////////////////////////////////////////////////
/*
������� ��������� ������ List.
������������������ ������ � ���� ����������:
����, �����,
���������� �������� � ��������,
����������.
//*/
//	{
//		// ������� 4 (list) ////////////////////////////////////////////////////
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
		//������� 5 (set) ////////////////////////////////////////////////////////////
		//������ 5 
	/*
	������� ��������� ������ Set.
	������������������ ������ � ���� ����������:
	����, �����,
	���������� �������� � ��������.
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


		//������ 6 
		/*
		������� ��������� ������ map.
		������������������ ������ � ���� ����������:
		����, �����,
		���������� �������� � ��������.
		*/
		/*std::map � ��������������� ������������� ���������,
		������� �������� ���� ����-�������� � ���������������� �������.*/

		/*
		char c;
		std::map <char, int> myMap;
		std::map<char, int>::iterator mm;
		for (int i = 0, c = 'a'; i < 5; ++i, ++c)
		{
			myMap.insert(std::pair<char, int>(c, i));
		}
		///����� �� ���� ������������������ map �� �����
		for (auto it = myMap.begin(); it != myMap.end(); ++it)
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
		}
		std::cout << std::endl;
		mm = myMap.find('b');
		std::cout <<"������� �-� �������  " << std::endl;
		myMap.erase('c'); //��������
		myMap.insert(mm, std::pair<char, int>('c', 200)); //����������
		for (auto it = myMap.begin(); it != myMap.end(); ++it)
		{
			std::cout << (*it).first << " : " << (*it).second << std::endl;
		}*/

		// ������ 7 
		/*
		��������� ������� ��������� �� ������� ���������� ��������
		��� ����, �����, �������, ������, ���������, ������� �� n ���������.
		������ ��������:
		���������� � ������
		���������� � �����
		���������� � ��������
		�������� �� ������
		�������� � �����
		�������� �� ��������
		�������� �������� �� ������
		�������� �������� � �����
		�������� �������� �� ��������
		system("pause");
		return 0;
		}*/
		system("pause");
	}