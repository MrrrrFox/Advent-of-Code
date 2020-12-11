#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "../readFromFile.h"

// function returning a vector which represents the number of certain offset-value occurrence
vector<int> findOffsetNumbers(vector<int> data, int maxOffset)
{
	int adapterRating = 0;
	vector<int> offsetNumbers;
	for(int i=0; i<maxOffset; ++i)
		offsetNumbers.push_back(0);
	
	sort(data.begin(),data.end());
	for(int i=0; i<data.size(); ++i)
		if(data[i]-adapterRating<=maxOffset)
		{
			++offsetNumbers[data[i]-adapterRating-1];
			adapterRating = data[i];
		}
	
	return offsetNumbers;
}

// function computing the total number of distinct ways that the adapters can be arranged to connect the charging outlet
double computeNumberOfCorrectArrangements(vector<int> data, int maxOffset)
{
	double sum=0;
	vector<double> numberOfWays;
	for(int i=0; i<data.size(); ++i)
		numberOfWays.push_back(0);

	sort(data.begin(), data.end());
	numberOfWays[numberOfWays.size()-2] = numberOfWays[numberOfWays.size()-1] = 1;
	numberOfWays[numberOfWays.size()-3] = (data[numberOfWays.size()-1]-data[numberOfWays.size()-3] <= maxOffset ? 2 : 1);

	for(int i=data.size()-4; i>=0; --i)
		for(int j=i+1; j<=i+3; ++j)
			if(data[j]-data[i] <= maxOffset)
				numberOfWays[i]+=numberOfWays[j];
	
	for(int i=0; i<maxOffset; ++i)
		if(data[i] <= maxOffset)
			sum+=numberOfWays[i];
	
	return sum;
}

int main()
{
	vector<int> data = readIntDataFromFile("data.txt");
	
	int maxOffset=3, diff=3;
	
	vector<int> vecOff = findOffsetNumbers(data, maxOffset);
	++vecOff[diff-1];
	
	// first task
	cout << "The number of 1-jolt differences multiplied by the number of " << maxOffset << "-jolt differences is equal to:\n" << vecOff[0]*vecOff[vecOff.size()-1] << endl;
	
	// second task
	cout << fixed <<  "The number of distinct ways that the adapters can be arranged to connect the charging outlet is equal to:\n" << computeNumberOfCorrectArrangements(data, maxOffset) << endl;

	return 0;
}
