#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#include "../readFromFile.h"


void GetGammaAndEpsilon(vector<vector<char>> &data, vector<char> &gamma, vector<char> &epsilon)
{
	for(int i=0; i<data[0].size(); ++i)
	{
		int ones=0, twos=0;
		for(int j=0; j<data.size(); ++j)
		{
			if(data[j][i] == '1')
				++ones;
			else
				++twos;
		}
		if(ones > twos)
		{
			gamma.push_back('1');
			epsilon.push_back('0');
		}
		else
		{
			gamma.push_back('0');
			epsilon.push_back('1');
		}
	}
}

int BinaryToDecimal(vector<char> v)
{
	int wynik=0;
	
	int p=0;
	for(int i=v.size()-1; i>=0; --i, ++p)
	{
		if(v[i] == '1')
		{
			wynik += pow(2, p);
		}
	}
	
	return wynik;
}


int main()
{
	vector<vector<char>> data = readCharMatrixFromFile("data.txt");
	
	vector<char> gamma;
	vector<char> epsilon;
	
	GetGammaAndEpsilon(data, gamma, epsilon);
	
	cout << "Gamma * Epsilon:\t" << BinaryToDecimal(gamma) * BinaryToDecimal(epsilon) << endl;
		
	return 0;
}
