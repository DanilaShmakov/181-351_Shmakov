#include "Strock.h"
int main()
{
	std::string g;
	std::cin >> g;
		Strock a(&g);
		Strock b;
		Strock c((char *) "Hello");
		Strock d(c);
		c.save(c, "file.txt");
		c.load("file.txt");
		//c.add(g);
		//std::cout << "'Hell' in Strock " << c <<" "; // проверка перегруженного оператора <<
		//c.find((char*)"Hell");
		//std::cout << "'Help' in Strock " << c <<" ";
		//c.find((char*)"Help");
		//c.insert(2, (char*)"freed");
		//c.cut(2, 5);
		//c.clear();
	system("pause");
}