#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

#include "../readFromFile.h"


long long MultiplicationOfDepthAndForwardValue(vector<tuple<string, int>> data)
{
	int depth=0, forward=0;
	for(int i=0; i<data.size(); ++i)
	{
		if(get<0>(data[i]) == "forward")
		{
			forward += get<1>(data[i]);
		}
		else if(get<0>(data[i]) == "down")
		{
			depth += get<1>(data[i]);
		}
		else if(get<0>(data[i]) == "up")
		{
			depth -= get<1>(data[i]);
		}
	}
	return depth * forward;
}

long long MultiplicationOfDepthAndForwardValueWithAimConsideration(vector<tuple<string, int>> data)
{
	int depth=0, forward=0, aim=0;
	for(int i=0; i<data.size(); ++i)
	{
		if(get<0>(data[i]) == "forward")
		{
			forward += get<1>(data[i]);
			depth += aim * get<1>(data[i]);
		}
		else if(get<0>(data[i]) == "down")
		{
			aim += get<1>(data[i]);
		}
		else if(get<0>(data[i]) == "up")
		{
			aim -= get<1>(data[i]);
		}
	}
	return depth * forward;
}


int main()
{
	vector<tuple<string, int>> data = readStringIntTupleFromFile("data.txt");
	
	cout << "Depth and horizontal position multiplied:\t" << MultiplicationOfDepthAndForwardValue(data) << endl;
	
	cout << "Depth and horizontal position multiplied (modified by aim):\t" << MultiplicationOfDepthAndForwardValueWithAimConsideration(data) << endl;
	
	return 0;
}
