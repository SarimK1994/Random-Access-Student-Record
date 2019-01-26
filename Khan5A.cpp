/**************************************************************************
*                                                                         *
*     Program Filename:  Khan5A.cpp                                       *
*     Author          :  Sarim Khan                                       *
*     Date Written    :  December 1, 2017                                 *
*     Purpose         :  Build random access student record file          *
*     Input from      :  Program5A.dat                                    *
*     Output to       :  random.dat                                       *
*                                                                         *
**************************************************************************/
#include <iostream>
using namespace std; 
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>

int main()
{
	string SR;
	ifstream InFile;
	fstream OutFile;
	int i, j; 
	int Hash = 0; 
	string HashString; 
	//declare variables 

	InFile.open("Program5A.dat", ios::in); //open input file 
	OutFile.open("random.dat", ios::in | ios::out); //open in and output for output file 

	for (i = 0; i < 60; i++)
	{
		OutFile << "*********                                          00.00" << endl;
	} //create blank records

	getline(InFile, SR); //get first line of input file 

	while (!InFile.eof())
	{
		for (j = 0; j < 9; j++)
		{
			Hash = Hash + SR[j]; 
		} //end for 

		Hash = Hash % 60;
		OutFile.seekg(58 * Hash, ios::beg);
		OutFile >> HashString; //hash lines and print to output 
		if (HashString == "*********")
		{
			OutFile.seekp(58 * Hash, ios::beg);
			OutFile << SR;
		} //if blank record 
		else
		{
			while (HashString != "*********")
			{
				Hash++;
				if (Hash == 60)
				{
					Hash = 0;
				}
				OutFile.seekg(58 * Hash, ios::beg);
				OutFile >> HashString;
			} //end while 
			OutFile.seekp(58 * Hash, ios::beg);
			OutFile << SR;
		} //end else 
		getline(InFile, SR);
	} //end while 

	InFile.close();
	OutFile.close(); //close input and output files 
}
//end main 