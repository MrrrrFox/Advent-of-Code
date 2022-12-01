#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

// funtion checking whether two vectors contain equal values
bool checkVectorsEquality(vector<vector<char>> vec1, vector<vector<char>> vec2)
{
	if(vec1.size() != vec2.size())
		return false;
	for(int i=0; i<vec1.size(); ++i)
	{
		if(vec1[i].size() != vec2[i].size())
			return false;
		for(int j=0; j<vec1[i].size(); ++j)
		{
			if(vec1[i][j] != vec2[i][j])
				return false;
		}
	}
	return true;
}

// function showing the matrix of values
void showMatrix(vector<vector<char>> data)
{
	for(int i=0; i<data.size(); ++i)
	{
		for(int j=0; j< data[i].size(); ++j)
			cout << data[i][j];
		cout << endl;
	}
	cout << endl;
}

int findNumberOfOccureances(vector<vector<char>> data, char value)
{
	int num=0;
	
	for(int i=0; i<data.size(); ++i)
		for(int j=0; j< data[i].size(); ++j)
			if(data[i][j] == value)
				++num;
	
	return num;
}

// function counting how many neighbours of certain cell has the given value (in closest neighbourhood)
int countNeighbours(vector<vector<char>> dataPrev, int x, int y, char value)
{
	int neighbours=0;
	
	for(int i=x-1; i<=x+1; ++i)
	{
		for(int j=y-1; j<=y+1; ++j)
		{
			if(i>=0 && i<dataPrev.size() && j>=0 && j<dataPrev[i].size())
				if(dataPrev[i][j] == value)
					++neighbours;
		}
	}
	if(dataPrev[x][y] == value)
		--neighbours;
	return neighbours;
}

// function counting how many neighbours of certain cell has the given value (in neighbourhood of see-sight)
int countNeighboursSee(vector<vector<char>> dataPrev, int x, int y, char value)
{
	int neighbours=0, indX, indY;
	
	for(int i=-1; i<=1; ++i)
	{
		for(int j=-1; j<=1; ++j)
		{
			indX=x; indY=y;
			if(i==0 && j==0) {}
			else
			{
				while(true)
				{
					indX+=i; indY+=j;
					if(indX>=0 && indX<dataPrev.size() && indY>=0 && indY<dataPrev[indX].size())
					{
						if(dataPrev[indX][indY] == value)
						{
							++neighbours;
							break;
						}
						else if(dataPrev[indX][indY] != '.')
						{
							break;
						}
					}
					else
						break;

				}
			}
		}
	}
	return neighbours;
}

// function updating the state by appling the rules for one round (apllication)
void updateState(vector<vector<char>> dataPrev, vector<vector<char>> &dataNext, int (* countingFunc)(vector<vector<char>> dataPrev, int x, int y, char value), int minNeighboursToLeave)
{
	int neighbours;
	for(int i=0; i<dataPrev.size(); ++i)
	{
		for(int j=0; j< dataPrev[i].size(); ++j)
		{
			if(dataPrev[i][j] == 'L' && countingFunc(dataPrev, i, j, '#')==0)
				dataNext[i][j]='#';
			else if(dataPrev[i][j] == '#' && countingFunc(dataPrev, i, j, '#')>=minNeighboursToLeave)
				dataNext[i][j]='L';
		}
	}
}

// function copying values from one vector to the other
void copyValues(vector<vector<char>> copyFromVec, vector<vector<char>> &copyToVec)
{
	for(int i=0; i<copyFromVec.size(); ++i)
		for(int j=0; j< copyFromVec[i].size(); ++j)
			copyToVec[i][j] = copyFromVec[i][j];
}

// function returning the number of applications that are required to stabilize the state
vector<vector<char>> findStabilizedStage(vector<vector<char>> data, int (* countingFunc)(vector<vector<char>> dataPrev, int x, int y, char value), int minNeighboursToLeave)
{
	int numberOfRounds=0;
	
	vector<vector<char>> dataPrev, dataNext;
	vector<char> line;
	
	for(int i=0; i<data.size(); ++i)
	{
		dataPrev.push_back(line); 
		dataNext.push_back(line); 
		for(int j=0; j< data[i].size(); ++j)
		{
			dataPrev[i].push_back(data[i][j]); 
			dataNext[i].push_back(data[i][j]);
		}
	}
	
	do
	{
		cout << ++numberOfRounds << endl;
		copyValues(dataNext,dataPrev);
		updateState(dataPrev,dataNext, countingFunc, minNeighboursToLeave);
	} while(!checkVectorsEquality(dataPrev,dataNext));
	
	return dataNext;
}

int main()
{
	vector<vector<char>> data = readCharMatrixFromFile("data.txt");
	
	vector<vector<char>> stabilizedStage1 = findStabilizedStage(data, &countNeighbours, 4);
	
	cout << "1:\t" << findNumberOfOccureances(stabilizedStage1, '#') << endl;
	
	vector<vector<char>> stabilizedStage2 = findStabilizedStage(data, &countNeighboursSee, 5);
	
	cout << "2:\t" << findNumberOfOccureances(stabilizedStage2, '#') << endl;
	
	// first task
	//cout << "The number of 1-jolt differences multiplied by the number of " << maxOffset << "-jolt differences is equal to:\n" << vecOff[0]*vecOff[vecOff.size()-1] << endl;
	
	// second task
	//cout << fixed <<  "The number of distinct ways that the adapters can be arranged to connect the charging outlet is equal to:\n" << computeNumberOfCorrectArrangements(data, maxOffset) << endl;

	return 0;
}
