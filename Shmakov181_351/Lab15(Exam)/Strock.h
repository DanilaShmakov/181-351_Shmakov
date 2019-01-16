#ifndef STROCK_H
#define STROCK_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
class Strock
{
private:
	char *buffer = nullptr;
	int len;
public:
	~Strock();
	Strock();
	Strock(char *arr);
	Strock(Strock &arr);
	Strock(std::string *arr);
	void clear();
	void add(std::string arr);
	int insert(int pos, char * arr);
	int cut(int pos, int num);
	friend Strock operator +(Strock str1, Strock str2 );
	friend std::ostream & operator << (std::ostream & os, Strock & r);
	int find(char * posl);
	void save(Strock str1, std::string path);
	void load(std::string path);
};
#endif