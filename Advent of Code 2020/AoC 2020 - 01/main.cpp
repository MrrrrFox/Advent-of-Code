#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

int sumTwoToNum(const vector<int> dane, int num)
{
	int l1, l2;
	for(int i=0; i<dane.size()-1; ++i)
	{
		l1 = dane[i];
		for(int j=i+1; j<dane.size(); ++j)
		{
			l2=dane[j];
			if((l1+l2)==num)
				return l1*l2;
		}
	}
}

int sumThreeToNum(const vector<int> dane, int num)
{
	int l1, l2, l3;
	for(int i=0; i<dane.size()-2; ++i)
	{
		l1 = dane[i];
		for(int j=i+1; j<dane.size()-1; ++j)
		{
			l2=dane[j];
			for(int k=j+1; k<dane.size(); ++k)
			{
				l3 = dane[k];
				if((l1+l2+l3)==num)
					return l1*l2*l3;
			}
		}
	}
}

int main()
{
	vector<int> dane = readIntDataFromFile("data.txt");
	
	cout << "Multiplication of two numbers that sum up to 2020 is equal to:\t" << sumTwoToNum(dane,2020) << endl;
	
	cout << "Multiplication of three numbers that sum up to 2020 is equal to:\t" << sumThreeToNum(dane,2020) << endl;

	return 0;
}
