#define CURL_STATICLIB 
#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <iostream> 

#ifdef _WIN64 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#elif _WIN32 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#endif 

/*
https://github.com/curl/curl.git https://github.com/curl/curl
1. ��������� �� ������ ������ ������� ������������ VS (x64 Native tools)
2. � ������� CD /D <����> ������� � ����� curl
3. ��������� buildconf.bat (������� buildconf) - ��������������� ��������� ���������� ����� � ��������� ����������� ������
4. ������� � ������� CD � winbuild
5. ��������� ������ �� ����� ������� BUILD.WINDOWS.txt
*/

static int writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size * nmemb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
	CURL *curl = nullptr;
	std::string buffer, curs;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.banki.ru/products/currency/cash/moskva/" /* "https://mospolytech.ru/"*/);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	//std::cout << buffer << std::endl; //�������� ���� ��� ��������
	//i = buffer.find("currency__numbers_increase\">6"); //���������� ������ ��������� ������
	//���� ����� ������ ����� ������� ��� ������ �������� ����� ������� 
	i = buffer.find("<div class=\"currency-table__large-text\">");//���������� ������ ��������� ������
	i += 40;
	curs = buffer.substr(i, 5); //����� � i-���� �������� 5 �������
	std::cout << "USD\t" << curs << std::endl;
	i = buffer.rfind("<div class=\"currency-table__large-text\">");
	i += 40;
	curs = buffer.substr(i, 5);
	std::cout << "EUR\t" << curs;
	getchar();
	return 0;
}

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
