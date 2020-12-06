#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

// function returning the number of questions that anyone in the given group has answered
int countQuestionsAnsweredByAnyoneInGroup(vector<string> data)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int questionsAnsweredByGroup = 0;
	
	for(int i=0; i<alphabet.length(); ++i)
		for(int j=0; j<data.size(); ++j)
			if(data[j].find(alphabet.at(i)) != string::npos)
			{
				++questionsAnsweredByGroup;
				break;
			}
	
	return questionsAnsweredByGroup;
}

// function returning the number of questions that everyone in the given group has answered
int countQuestionsAnsweredByEveryoneInGroup(vector<string> data)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int questionsAnsweredByGroup = 0;
	bool everyoneAnswered = true;
	
	for(int i=0; i<alphabet.length(); ++i)
	{
		everyoneAnswered = true;
		for(int j=0; j<data.size(); ++j)
			if(data[j].find(alphabet.at(i)) == string::npos)
			{
				everyoneAnswered = false;
				break;
			}
		if(everyoneAnswered)
			++questionsAnsweredByGroup;
	}
			
	return questionsAnsweredByGroup;
}

// function returning the sum of questions answered (counted by specified counting function) by all given groups
int sumAllAnswers(vector<vector<string>> data, int (* func)(vector<string> group))
{
	int sumOfQuestionsAnswered = 0;
	
	for(int i=0; i<data.size(); ++i)
		sumOfQuestionsAnswered += func(data[i]);
		
	return sumOfQuestionsAnswered;
}

int main()
{
	vector<vector<string>> data = readPersonalDataFromFile("data.txt");

	// first task
	cout << "The sum of questions answered by anyone in group for all groups is:\t" << sumAllAnswers(data, &countQuestionsAnsweredByAnyoneInGroup) << endl;
	
	// second task
	cout << "The sum of questions answered by everyone in group for all groups is:\t" << sumAllAnswers(data, &countQuestionsAnsweredByEveryoneInGroup) << endl;

	return 0;
}
