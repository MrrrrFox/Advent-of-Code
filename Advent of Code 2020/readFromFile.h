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

// reading chars from file of given path and return the matrix with values of these chars
vector<vector<char>> readCharMatrixFromFile(const char * path)
{
	ifstream f;
	f.open(path);
	
	string line;
	vector<vector<char>> data;
	vector<char> row;
	int row_index = 0;
	while(getline(f, line))
	{
		data.push_back(row);
		for(int i=0; i<line.length(); ++i)
			data[row_index].push_back(line[i]);
		++row_index;
	}
	f.close();
	
	return data;
}

// reading personal data (sepereted with empty line) from file of given path and return the matrix with line-values of each person
vector<vector<string>> readPersonalDataFromFile(const char * path)
{
	ifstream f;
	f.open(path);
	
	string line;
	vector<vector<string>> data;
	vector<string> person;
	int person_index=0, pos=0;
	
	data.push_back(person);
	
	while(getline(f, line))
	{
		if(line.length()!=0)
		{
			pos=0;
			for(int i=0; i<line.length(); ++i)
				if(line.at(i)==' ')
				{
					data[person_index].push_back(line.substr(pos,i-pos));
					pos=i+1;
				}
			data[person_index].push_back(line.substr(pos, line.length()-pos));
		}
		else
		{
			data.push_back(person);
			++person_index;
		}
	}
	f.close();
	
	return data;
}
