#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// reading integers from file of given path and return the vector with values of these integers
vector<int> readIntDataFromFile(const char * path)
{
	ifstream f;
	f.open(path);
	
	int num;
	vector<int> data;

	while(f.eof()!=1)
	{
		f >> num;
		data.push_back(num);
	}
	f.close();
	
	return data;
}

// reading strings from file of given path and return the vector with values of these strings
vector<string> readStringDataFromFile(const char * path)
{
	ifstream f;
	f.open(path);
	
	string str;
	vector<string> data;
	
	while(f >> str)
	{
		data.push_back(str);
	}
	f.close();
	
	return data;
}

// reading lines from file of given path and return the vector with with values of these lines as strings
vector<string> readLineFromFile(const char * path)
{
	ifstream f;
	f.open(path);
	
	string line;
	vector<std::string> data;
	
	while(getline(f, line))
	{
		data.push_back(line);
	}
	f.close();
	
	return data;
}
