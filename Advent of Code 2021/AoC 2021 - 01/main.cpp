#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

int increasingValues(vector<int> &v)
{
	int res = 0;
	
	for(int i=0; i<v.size()-1; ++i)
	{
		if(v[i] < v[i+1])
			++res;
	}
	
	return res;
}

int increasingValuesOfThrees(vector<int> &v)
{
	int res = 0;
	for(int i=0; i<=v.size()-4; ++i)
	{
		if(v[i] < v[i+3])
			++res;
	}
	
	return res;
}

int main()
{
	vector<int> data = readIntDataFromFile("data.txt");
	
	cout << "Number of increasing values is equal to:\t" << increasingValues(data) << endl;
	
	cout << "Number of increasing values of 3-tuples is equal to:\t" << increasingValuesOfThrees(data) << endl;

	return 0;
}
