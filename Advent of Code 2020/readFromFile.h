#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

std::vector<int> readIntDataFromFile(char * path)
{
	ifstream f;
	f.open(path);
	
	int liczba;
	std::vector<int> dane;

	while(f.eof()!=1)
	{
		f >> liczba;
		dane.push_back(liczba);
	}
	f.close();
	
	return dane;
}
