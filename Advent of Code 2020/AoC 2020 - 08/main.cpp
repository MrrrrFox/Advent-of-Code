#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#include "../readFromFile.h"

// function executing program instruction for the given number of loops, returning whether the program finished without breaking any loop and the acc value
tuple<bool,int> calculateAccInNumberOfLoops(vector<tuple<string,int>> data, int numOfLoops)
{
	int acc=0, index=0, value;
	string instruction;
	vector<int> doneInstructions;
	for(int i=0; i<data.size(); ++i)
		doneInstructions.push_back(0);
	bool executedWithoutBreak=true;;
	
	while(true)
	{
		if(index>=data.size())
			break;
		instruction = get<0>(data[index]);
		value = get<1>(data[index]);
		
		if(instruction.compare("acc") == 0)
		{
			if(doneInstructions[index]==numOfLoops)
			{
				executedWithoutBreak=false;
				break;
			}
			++doneInstructions[index];
			acc += value;
			++index;	
		}
		else if(instruction.compare("jmp") == 0)
		{
			if(doneInstructions[index]==numOfLoops)
			{
				executedWithoutBreak=false;
				break;
			}
			++doneInstructions[index];
			index += value;
		}
		else if(instruction.compare("nop") == 0) 
		{
			if(doneInstructions[index]==numOfLoops)
			{
				executedWithoutBreak=false;
				break;
			}
			++doneInstructions[index];
			++index;
		}
	}
	
	return tuple<bool,int>(executedWithoutBreak,acc);
}

// function changing the input data in given index and trying to loop through the program
tuple<bool,int> tryChangedData(vector<tuple<string,int>> data, int i)
{
	if(get<0>(data[i]).compare("acc") == 0)
		return tuple<bool,int>(false,0);
	if(get<0>(data[i]).compare("jmp") == 0)
		get<0>(data[i]) = "nop";
	else if(get<0>(data[i]).compare("nop") == 0)
		get<0>(data[i]) = "jmp";
	
	return calculateAccInNumberOfLoops(data,1);
}

// function finding one instruction-change so that the program does not loop anymore and returning the value of acc in such loopless program
int calculateAccInLooplessProgram(vector<tuple<string,int>> data)
{
	for(int i=0; i<data.size(); ++i)
	{
		tuple<bool,int> resultOfChange = tryChangedData(data,i);
		if(get<0>(resultOfChange))
			return get<1>(resultOfChange);
	}
	return -1;
}

int main()
{
	vector<tuple<string,int>> data = readStringIntTupleFromFile("data.txt");

	// first task
	cout << "The value of acc after the first loop:\t" << get<1>(calculateAccInNumberOfLoops(data,1)) << endl;
	
	// second task
	cout << "The value of acc in loopless program:\t" << calculateAccInLooplessProgram(data) << endl;

	return 0;
}
