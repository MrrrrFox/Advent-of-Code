#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "../readFromFile.h"

// function counting the number of bags that may contain a bag of given color (directly or indirectly)
int countBagsThatMayContainColor(vector<string> data, string color)
{
	string currentlyConsideredColor = color;
	vector<string> colorsToConsider, colorsAccepted;
	
	colorsToConsider.push_back(color);

	while(!colorsToConsider.empty())
	{
		currentlyConsideredColor = colorsToConsider[0];
		colorsToConsider.erase(colorsToConsider.begin());
		for(int i=0; i<data.size(); ++i)
			if(data[i].find(currentlyConsideredColor) != string::npos && data[i].find(currentlyConsideredColor) != 0)
			{
				if(find(colorsAccepted.begin(),colorsAccepted.end(),currentlyConsideredColor) != colorsAccepted.end());
				{
					colorsToConsider.push_back(data[i].substr(0,data[i].find(" bags contain")));
					colorsAccepted.push_back(data[i].substr(0,data[i].find(" bags contain")));
				}
			}
	}
	
	sort( colorsAccepted.begin(), colorsAccepted.end() );
	colorsAccepted.erase( unique( colorsAccepted.begin(), colorsAccepted.end() ), colorsAccepted.end() );
	
	return colorsAccepted.size();
}

// function counting the number of bags that a bag of given color contains (directly and indirectly)
int countInnerBagsOfColor(vector<string> data, vector<string> possibleColors, string color)
{
	int innerBags = 0, pos, len, num;

	for(int i=0; i<data.size(); ++i)
		if(data[i].find(color) == 0)
			for(int j=0; j<possibleColors.size(); ++j)
				if(data[i].find(possibleColors[j]) != string::npos && data[i].find(possibleColors[j]) != 0)
				{
					pos=2; len=1;
					while(isdigit(data[i].at(data[i].find(possibleColors[j]))))
					{
						++pos;
						++len;
					}
					
					num = stoi(data[i].substr(data[i].find(possibleColors[j])-pos,len));
					innerBags += num + num * countInnerBagsOfColor(data, possibleColors, possibleColors[j]);
				}

	return innerBags;
}

int main()
{
	vector<string> data = readLineFromFile("data.txt");
	vector<string> possibleColors;
	for(int i=0; i<data.size(); ++i)
		possibleColors.push_back(data[i].substr(0,data[i].find(" bags contain")));
	
	string myBagColor="shiny gold";

	// first task
	cout << "The number of bags that may contain my " << myBagColor << " bag:\t" << countBagsThatMayContainColor(data, myBagColor) << endl;
	
	// second task
	cout << "The number of bags in my " << myBagColor << " bag:\t" << countInnerBagsOfColor(data, possibleColors, myBagColor) << endl;

	return 0;
}
