#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "../readFromFile.h"

// function checking whether given password is valid (old method)
bool isValidFirst(string s_min, string s_max, string letter, string password)
{
	int min=stoi(s_min), max=stoi(s_max);
	int numOfAppearance = 0;
	
	for(int i=0; i<password.length(); ++i)
		if(letter[0] == password[i])
			++numOfAppearance;
			
	if(min <= numOfAppearance && numOfAppearance <= max)
		return true;
	return false;
}

// function checking whether given password is valid (new method)
bool isValidSecond(string s_min, string s_max, string letter, string password)
{
	int first=stoi(s_min), second=stoi(s_max);
	
	if(password[first-1] == letter[0] ^ password[second-1] == letter[0])
		return true;
	return false;
}

// function checking how many passwords from given data is valid using given validation function
int numOfValidPasswd(const vector<string> data, bool (* func)(string s_min, string s_max, string letter, string password))
{
	int numOfCorrectPasswords = 0;

	for(int i=0; i<data.size(); i+=4)
		if(func(data[i], data[i+1], data[i+2], data[i+3]))
			++numOfCorrectPasswords;
			
	return numOfCorrectPasswords;
}





int main()
{
	vector<string> data = readStringDataFromFile("data.txt");

	// first task
	cout << "Number of correct passwords by old rules: " << numOfValidPasswd(data, &isValidFirst) << endl;
	
	// second task
	cout << "Number of correct passwords by new restrictions: " << numOfValidPasswd(data, &isValidSecond) << endl;

	return 0;
}
