#include <iostream>
#include <cstring> // ���������� ��� ������ � �� ��������
#include <string>
#include <fstream>
using namespace std;

// ������ � �����

/*
C����� ������� ��-���� ������������ �� ���� ����� ���� ������
�������� � ������� ����������:
char cstr1[] = "C-style string1";
char cstr2[] = { 'C', '-', 's', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '1', '\0' };
char cstr3[] = {'\67', '\0'};
string cppstr1 = "C++ - style string 1";
string cppstr2 = "";
 � ���� char �� ����� ���� �������� �������� ����� �����. ��� ����� ����������, ��������, �������� � ������
 */

 /*
  ������� ��� ������ � �-��������
  ����� �� ������:
  printf(char[], , ,)
  ���
  printf(* char, ...)
  */

  /*
 %f - ��� float � double
 %s - ��� �����
 %d - ��� ����� (int, long, long long)
 %e - ��� ���������������� ����
 */

 /*
 ���� �������:
 ����������� (������������) ����� - strcat (*char, *char):
 ����������� �� ����� ������ � ������ - strcpy():
 char cstr3[255];
 strcpy_s(cstr3, 255, cstr2);
 ��������� - strcmp():
 int i = strcmp(cstr1, cstr2);
 ����� ������ - strlen():
 int lngth = strlen(cstr1);
 ������� ������ � ��������� ������������ � ��������� ��������
 */

 /*
 ������ � �������:
 1) ��������� ���������� �� ����
 2) ��� ������ � �++ - ������� ������ ��� ������ � ������
 3) �������� �����
 4) ������ � ������ (������, ������, �����)
 5) �������� �����
 fstream - ������������� ����� ��� ����� � ��� ������ (������ �� ����� � ������ � ����)
 (if/of)stream - ����� ��� �����/������
 fstream -�����, ��������������� ��� �����/������ �/�� �����
 */

 /*
 �������� �����:
 fs.open("Some text file.txt", fstream::in | fstream::out | fstream::trunc);
 ������ ��������:
 fs.open("Some text file.txt", - ��� �������� ����� ���������� ������� ��� �����,
 � ����� ����� �������� � ����������� ��� ���
 */



int main()
{
	fstream fs;
	fstream text;
	text.open("Text.txt", fstream::in);
	fs.open("Some text.txt", fstream::out);

	string user_str;
	getline(text, user_str);
	string user_str2;
	getline(text, user_str2);

	cout << "input string: " << endl;
	cout << user_str << endl;

	cout << "input underline: " << endl;
	cout << user_str2 << endl;


	int pos = 0;
	while (pos != string::npos) {
		pos = user_str.find(user_str2, pos);
		if (pos == string::npos) {
			break;
		}
		fs << pos + 1 << '\t';

		pos++;
	}

	text.close();
	fs.close();
}