#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#include "../readFromFile.h"

// function decoding the binary space partitioning of given code using given parameters to take eiter lower or upper half
int decodePlace(string code, char lowerPart, char upperPart)
{
	int maxNum = pow(2,code.length())-1;
	int minIndex=0, maxIndex=maxNum;
	for(int i=0; i<code.length(); ++i)
	{
		if(code.at(i)==lowerPart)
			maxIndex=maxIndex-(maxIndex-minIndex)/2-1;
		else if(code.at(i)==upperPart)
			minIndex=minIndex+(maxIndex-minIndex)/2+1;
	}
	if(minIndex==maxIndex)
		return minIndex;
	return -1;
}

// function returning row of given ID
int rowOfID(int ID)
{
	return ID/8;
}

// function decoding the binary space partitioning into seats' IDs
vector<int> decodeSeatsIDs(vector<string> data)
{
	vector<int> IDs;
	int row, column;
	
	for(int i=0; i<data.size(); ++i)
	{
		row = decodePlace(data[i].substr(0,7), 'F', 'B');
		column = decodePlace(data[i].substr(7,3), 'L', 'R');
		IDs.push_back(row*8+column);
	}
	
	return IDs;
}

// function returning the ID of the first empty seat that is neither at the front nor at the back (task condition)
int searchForEmptySeat(vector<int> data)
{
	int rowMin=rowOfID(data[0]), rowMax=rowOfID(data[data.size()-1]);
	vector<int> missingIDs;
	
	for(int i=data[0]; i<=data[data.size()-1]; ++i)
		if(find(data.begin(),data.end(),i) == data.end())
			missingIDs.push_back(i);
	for(int i=0; i<missingIDs.size(); ++i)
		if(rowOfID(missingIDs[i])>rowMin && rowOfID(missingIDs[i])<rowMax)
			return missingIDs[i];
	
	return -1;
}


int main()
{
	vector<string> data = readStringDataFromFile("data.txt");
	
	vector<int> IDs = decodeSeatsIDs(data);
	sort(IDs.begin(), IDs.end());

	// first task
	cout << "The highest seat ID on a board pass is:\t" << IDs[IDs.size()-1] << endl;
	
	// second task
	cout << "My seat ID is:\t" << searchForEmptySeat(IDs) << endl;

	return 0;
}
