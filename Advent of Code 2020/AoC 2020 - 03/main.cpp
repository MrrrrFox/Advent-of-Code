#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

// function showing the matrix
void showMatrix(vector<vector<char>> data)
{
	for(int i=0; i<data.size(); ++i)
	{
		for(int j=0; j<data[0].size(); ++j)
			cout << data[i][j];
		cout << endl;
	}
}

// function counting the number of trees while sliding through given data from position (0,0) by vector [right, down]
int countTreesWhileSlidingDown(vector<vector<char>> data, int right, int down)
{
	int j=0, treesNum=0;
	for(int i=0; i<data.size(); i+=down)
	{
		if(data[i][j] == '#')
			++treesNum;
		j = (j+right)%data[0].size();
	}
	return treesNum;
}

// function computing the multiplication of numbers of trees from data from numOfSlides slides each from position (0,0) by vector from arrayOfSlides
unsigned int countTreesWhileMultipleSlides(vector<vector<char>> data, int arrayOfSlides[][2], int numOfSlides)
{
	unsigned int result=1;
	for(int i=0; i<numOfSlides; ++i)
		result *= countTreesWhileSlidingDown(data,arrayOfSlides[i][0],arrayOfSlides[i][1]);
	return result;
}

int main()
{
	vector<vector<char>> data = readCharMatrixFromFile("data.txt");

	//showMatrix(data);

	// first task
	cout << "Number of trees while sliding by 3 right and 1 down:\t" << countTreesWhileSlidingDown(data,3,1) << endl;
	
	// second task
	int arrayOfSlides[][2] = {{1,1},{3,1},{5,1},{7,1},{1,2}};
	int numOfSlides = sizeof(arrayOfSlides)/sizeof(arrayOfSlides[0]);
	cout << "Numbers of trees after a few slides multiplied together:\t" << countTreesWhileMultipleSlides(data, arrayOfSlides, numOfSlides) << endl;

	return 0;
}
