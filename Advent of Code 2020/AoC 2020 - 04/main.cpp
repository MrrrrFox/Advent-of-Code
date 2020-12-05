#include <iostream>
#include <vector>

using namespace std;

#include "../readFromFile.h"

// function checking whether given passport (vector of strings: fields+values) is basically valid
bool isPassportBasicallyValid(vector<string> passport)
{
	string obligatoryFields[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}; 	// cid is not generally obligatory
	int personValidationCounter=0, 
		obligatoryFieldsNum=sizeof(obligatoryFields)/sizeof(obligatoryFields[0]);
		
	for(int i=0; i<passport.size(); i+=2)
	{
		for(int j=0; j<obligatoryFieldsNum; ++j)
			if(passport[i].compare(obligatoryFields[j]) == 0)
				++personValidationCounter;				
	}
	return personValidationCounter==obligatoryFieldsNum;
}

// function counting the number of basically valid passports 
int countBasicallyValidPassports(vector<vector<string>> data)
{
	int validPassportsNum=0;
		
	for(int i=0; i<data.size(); ++i)
		if(isPassportBasicallyValid(data[i]))
			++validPassportsNum;
	
	return validPassportsNum;
}

// function checking whether given passport's values (vector of strings: fields+values) are value
bool isPassportDataValid(vector<string> passport, int passIND)
{	
	for(int i=0; i<passport.size(); i+=2)
	{
		if(passport[i].compare("byr")==0)
		{
			int num = stoi(passport[i+1], nullptr, 10);
				if(num<1920 || num>2002)
					return false;
		}
		else
		{
			if(passport[i].compare("iyr")==0)
			{
				int num = stoi(passport[i+1], nullptr, 10);
					if(num<2010 || num>2020)
						return false;
			}
			else
			{
				if(passport[i].compare("eyr")==0)
				{
					int num = stoi(passport[i+1], nullptr, 10);
						if(num<2020 || num>2030)
							return false;
				}
				else
				{
					if(passport[i].compare("hgt")==0)
					{
						if(passport[i+1].substr(passport[i+1].length()-2, 2).compare("cm") == 0)
						{
							int num = stoi(passport[i+1].substr(0,passport[i+1].length()-2), nullptr, 10);
							if(num<150 || num>193)
								return false;
						}
						else
						{
							if(passport[i+1].substr(passport[i+1].length()-2, 2).compare("in") == 0)
							{
								int num = stoi(passport[i+1].substr(0,passport[i+1].length()-2), nullptr, 10);
								if(num<59 || num>76)
									return false;
							}
							else
								return false;
						}
					}
					else
					{
						if(passport[i].compare("hcl")==0)
						{
							if(passport[i+1].at(0) != '#' || passport[i+1].length() != 7)
								return false;
							string value = passport[i+1].substr(1,passport[i+1].length()-1);
							string chars = "0123456789abcdef";
							bool valid;
							for(int j=0; j<value.length(); ++j)
							{
								valid = false;
								for(int k=0; k<chars.length(); ++k)
								{
									if(value.at(j)==chars.at(k))
									{
										valid = true;
										break;
									}
								}
								if(!valid)
									return false;
							}
						}
						else
						{
							if(passport[i].compare("ecl")==0)
							{
								string possibleColors[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
								int possibleColorsNum=sizeof(possibleColors)/sizeof(possibleColors[0]);
								bool validColor = false;
								for(int j=0; j<possibleColorsNum; ++j)
									if(passport[i+1].compare(possibleColors[j]) == 0)
									{
										validColor = true;
										break;
									}
								if(!validColor)
									return false;	
							}
							else
							{
								if(passport[i].compare("pid")==0)
								{
									if(passport[i+1].length()!=9)
										return false;
									else
									{
										for(int j=0; j<passport[i+1].length(); ++j)
											if(!isdigit(passport[i+1][j]))
												return false;
									}
								}
							}
						}
					}
				}
			}
		}		
	}
	return true;
}

// function counting the number of valid passports 
int countValidPassports(vector<vector<string>> data)
{
	int validPassportsNum=0;
		
	for(int i=0; i<data.size(); ++i)
		if(isPassportBasicallyValid(data[i]) && isPassportDataValid(data[i], i))
			++validPassportsNum;
	
	return validPassportsNum;
}





int main()
{
	vector<vector<string>> data = readPersonalDataFromFile("data.txt");

	// first task
	cout << "Number of basically valid passports:\t" << countBasicallyValidPassports(data) << endl;
	
	// second task
	cout << "Number of valid passports:\t" << countValidPassports(data) << endl;

	return 0;
}
