#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#include "../readFromFile.h"

// function returning the minimum value from vector between two given indexes (both indexes included)
double minValueFromVectorInRange(vector<double> data, int minIndex, int maxIndex)
{
	double minValue = data[minIndex];
	
	for(int i=minIndex+1; i<=maxIndex; ++i)
		if(minValue > data[i])
			minValue = data[i];
		
	return minValue;
}

// function returning the maximum value from vector between two given indexes (both indexes included)
double maxValueFromVectorInRange(vector<double> data, int minIndex, int maxIndex)
{
	double maxValue = data[minIndex];
	
	for(int i=minIndex+1; i<=maxIndex; ++i)
		if(maxValue < data[i])
			maxValue = data[i];
		
	return maxValue;
}

// function returning the first value from vetor that cannot be obtained by sum of two other values of it's preambule-values
int findFirstNotObtainable(vector<double> data, int preambule)
{
	bool correct = false;
	
	for(int i=preambule; i<data.size(); ++i)
	{
		correct = false;
		for(int j=i-preambule; j<i-1; ++j)
		{
			for(int k=j+1; k<i; ++k)
				if(data[i]==(data[j]+data[k]))
				{
					correct = true;
					break;
				}
			if(correct)
				break;
		}
		if(!correct)
			return data[i];
	}
	
	return -1;
}

// function returning the sum of max and min value of contiguous range which numbers sum up to the value from findFirstNotObtainable() function
int task09_2(vector<double> data, int num)
{
	double sum;
	int j;
	
	for(int i=0; i<data.size(); ++i)
	{
		sum=0;
		j=0;
		while(sum<num)
		{
			sum += data[i+j];
			++j;
		}
		if(sum==num)
			return minValueFromVectorInRange(data,i,i+j-1) + maxValueFromVectorInRange(data,i,i+j-1);
	}
	
	return -1;
}

int main()
{
	vector<double> data = readDoubleDataFromFile("data.txt");
	
	int preambule = 25;
	
	int notMatchingThePreambule = findFirstNotObtainable(data,preambule);

	// first task
	cout << fixed << "The first value that is not the sum of any two numbers from it's " << preambule <<"-preambule-numbers is equal to:\t" << notMatchingThePreambule << endl;
	
	// second task
	cout << fixed <<  "The sum of smallest and largest number in contiguous range in which values sum up to the number above is equal to:\t" << task09_2(data,notMatchingThePreambule) << endl;

	return 0;
}
