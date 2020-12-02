#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

// function returning the multiplication of two numbers from given data which sum is equal to given number
int sumTwoToNum(const vector<int> data, int num)
{
	int l1, l2;
	for(int i=0; i<data.size()-1; ++i)
	{
		l1 = data[i];
		for(int j=i+1; j<data.size(); ++j)
		{
			l2=data[j];
			if((l1+l2)==num)
				return l1*l2;
		}
	}
}

// function returning the multiplication of three numbers from given data which sum is equal to given number
int sumThreeToNum(const vector<int> data, int num)
{
	int l1, l2, l3;
	for(int i=0; i<data.size()-2; ++i)
	{
		l1 = data[i];
		for(int j=i+1; j<data.size()-1; ++j)
		{
			l2=data[j];
			for(int k=j+1; k<data.size(); ++k)
			{
				l3 = data[k];
				if((l1+l2+l3)==num)
					return l1*l2*l3;
			}
		}
	}
}





int main()
{
	vector<int> data = readIntDataFromFile("data.txt");
	
	cout << "Multiplication of two numbers that sum up to 2020 is equal to:\t" << sumTwoToNum(data,2020) << endl;
	
	cout << "Multiplication of three numbers that sum up to 2020 is equal to:\t" << sumThreeToNum(data,2020) << endl;

	return 0;
}
