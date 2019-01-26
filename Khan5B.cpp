/**************************************************************************
*                                                                         *
*     Program Filename:  Khan5B.cpp                                       *
*     Author          :  Sarim Khan                                       *
*     Date Written    :  December 7, 2017                                 *
*     Purpose         :  Edit random access file                          *
*     Input from      :  random.dat                                       *
*     Output to       :  random.dat                                       *
*                                                                         *
**************************************************************************/
#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>

int CalculateHash(string);

int main()
{
	fstream InputFile; 
	int Hash = 0; 
	string InputLine = " "; 
	string Character = " "; 
	char Option = ' '; 
	string AddSSN = " "; 
	string AddFN = " "; 
	string AddLN = " "; 
	string AddMajor = " "; 
	string AddCH = " "; 
	string AddGPA = " ";
	//string FileName; 

	cout << "Please enter the name of the file"; 
//	cin >> FileName; 

	InputFile.open("random.dat", fstream::in | fstream::out); 

	for (;;)
	{
		cout << "A. Add a record" << endl;
		cout << "D. Delete a record" << endl;
		cout << "S. Display a record" << endl;
		cout << "N. Change last name" << endl;
		cout << "M. Change major" << endl;
		cout << "H. Change hours" << endl;
		cout << "G. Change GPA" << endl;
		cout << "X. Stop the program" << endl << endl;
		
		cin >> Option; 
		Option = toupper(Option); 

		if (Option == 'A')
		{
			cout << "Please enter the SSN: ";
			cin >> AddSSN;
			Hash = CalculateHash(AddSSN);
			cout << "Please enter the first name: ";
			cin >> AddFN;
			cout << "Please enter the last name: ";
			cin >> AddLN;
			cout << "Please enter the major: ";
			cin >> AddMajor;
			cout << "Please enter the credit hours: ";
			cin >> AddCH;
			cout << "Please enter the GPA: ";
			cin >> AddGPA;
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine); 
			InputFile.seekp(58 * Hash, ios::beg); 
			Character = InputLine.substr(0, 1); 
			if (Character == "*" || Character == "+")
			{
				InputFile << AddSSN;
				InputFile.seekp(58 * Hash + 9, ios::beg);
				InputFile << AddLN;
				InputFile.seekp(58 * Hash + 19, ios::beg);
				InputFile << AddFN;
				InputFile.seekp(58 * Hash + 29, ios::beg);
				InputFile << AddMajor;
				InputFile.seekp(58 * Hash + 49, ios::beg);
				InputFile << AddCH;
				InputFile.seekp(58 * Hash + 52, ios::beg);
				InputFile << AddGPA;
			}
			else
			{
				do
				{
					do
					{
						Hash++; 
						if (Hash == 60)
						{
							Hash = 0; 
						}
						InputFile.seekg(58 * Hash, ios::beg); 
						getline(InputFile, InputLine); 
						InputFile.seekp(58 * Hash, ios::beg); 
						Character = InputLine.substr(0, 1); 
						if (Character == "*" || Character == "+")
						{
							InputFile << AddSSN;
							InputFile.seekp(58 * Hash + 9, ios::beg);
							InputFile << AddLN;
							InputFile.seekp(58 * Hash + 19, ios::beg);
							InputFile << AddFN;
							InputFile.seekp(58 * Hash + 29, ios::beg);
							InputFile << AddMajor;
							InputFile.seekp(58 * Hash + 49, ios::beg);
							InputFile << AddCH;
							InputFile.seekp(58 * Hash + 52, ios::beg);
							InputFile << AddGPA;
						}
					} while (Character != "*");
				} while (Character != "+");
			}
		}//end if A
		else if (Option == 'D')
		{
			cout << "Please enter the SSN of the person you want to delete: ";
			cin >> AddSSN;
			Hash = CalculateHash(AddSSN);
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine); 
			InputFile.seekp(58 * Hash, ios::beg); 
			Character = InputLine.substr(0, 9);
			if (Character == AddSSN)
			{
				InputFile << "+"; 
			}
			else
			{
				do
				{
					Hash++; 
					if (Hash == 60) 
					{
						Hash = 0; 
					}
					InputFile.seekg(58 * Hash, ios::beg); 
					getline(InputFile, InputLine); 
					InputFile.seekp(58 * Hash, ios::beg); 
					Character = InputLine.substr(0, 9); 
					if (Character == AddSSN)
					{
						InputFile << "+"; 
					}
				} while (Character != AddSSN); 
			}
		}//end D 

		else if (Option == 'S')
		{
			cout << "Please enter the SSN of the person you want to display: ";
			cin >> AddSSN;
			Hash = CalculateHash(AddSSN);
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine); 
			InputFile.seekp(58 * Hash, ios::beg); 
			Character = InputLine.substr(0, 9);
			if (Character == AddSSN)
			{
				cout << InputLine << endl;           
			}
			else
			{
				do
				{
					Hash++; 
					if (Hash == 60) 
					{
						Hash = 0; 
					}
					InputFile.seekg(58 * Hash, ios::beg); 
					getline(InputFile, InputLine); 
					InputFile.seekp(58 * Hash, ios::beg);
					Character = InputLine.substr(0, 9); 
					if (Character == AddSSN)
					{
						cout << InputLine << endl; 
					}
				} while (Character != AddSSN); 
			}
		}
		else if (Option == 'N')
		{
			cout << "Please enter the SSN of the person you want to change last name: ";
			cin >> AddSSN;
			Hash = CalculateHash(AddSSN);
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine); 
			InputFile.seekp(58 * Hash, ios::beg); 
			Character = InputLine.substr(0, 9);
			if (Character == AddSSN)
			{
				InputFile.seekp(58 * Hash + 9, ios::beg); 
				cout << "Please change the last name of this record: ";
				cin >> AddLN;
				InputFile << AddLN;
			}
			else
			{
				do
				{
					Hash++; 
					if (Hash == 60) 
					{
						Hash = 0;
					}
					InputFile.seekg(58 * Hash, ios::beg); 
					getline(InputFile, InputLine); 
					InputFile.seekp(58 * Hash, ios::beg); 
					Character = InputLine.substr(0, 9);
					if (Character == AddSSN)
					{
						InputFile.seekp(58 * Hash + 9, ios::beg); 
						cout << "Please change the last name of this record: ";
						cin >> AddLN;
						InputFile << AddLN;
					}
				} while (Character != AddSSN); 
			}
		}
		else if (Option == 'M')
		{
			cout << "Please enter the SSN of the person you want to change major: ";
			cin >> AddSSN;
			Hash = CalculateHash(AddSSN);
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine); 
			InputFile.seekp(58 * Hash, ios::beg); 
			Character = InputLine.substr(0, 9);
			if (Character == AddSSN)
			{
				InputFile.seekp(58 * Hash + 29, ios::beg); 
				cout << "Please change the major of this record: ";
				cin >> AddMajor;
				InputFile << AddMajor;
			}
			else
			{
				do
				{
					Hash++; 
					if (Hash == 60) 
					{
						Hash = 0; 
					}
					InputFile.seekg(58 * Hash, ios::beg);
					getline(InputFile, InputLine); 
					InputFile.seekp(58 * Hash, ios::beg); 
					Character = InputLine.substr(0, 9); 
					if (Character == AddSSN)
					{
						InputFile.seekp(58 * Hash + 29, ios::beg); 
						cout << "Please change the major of this record: ";
						cin >> AddMajor;
						InputFile << AddMajor;
					}
				} while (Character != AddSSN); 
			}
		}
		else if (Option == 'H')
		{
			cout << "Please enter the SSN of the person you want to change hours: ";
			cin >> AddSSN;
			Hash = CalculateHash(AddSSN);
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine); 
			InputFile.seekp(58 * Hash, ios::beg); 
			Character = InputLine.substr(0, 9);
			if (Character == AddSSN)
			{
				InputFile.seekp(58 * Hash + 49, ios::beg); 
				cout << "Please change the credit hours of this record: ";
				cin >> AddCH;
				InputFile << AddCH;
			}
			else
			{
				do
				{
					Hash++; 
					if (Hash == 60) 
					{
						Hash = 0; 
					}
					InputFile.seekg(58 * Hash, ios::beg);
					getline(InputFile, InputLine); 
					InputFile.seekp(58 * Hash, ios::beg); 
					Character = InputLine.substr(0, 9); 
					if (Character == AddSSN)
					{
						InputFile.seekp(58 * Hash + 49, ios::beg); 
						cout << "Please change the credit hours of this record: ";
						cin >> AddCH;
						InputFile << AddCH;
					}
				} while (Character != AddSSN);
			}
		}
		else if (Option == 'G')
		{
			cout << "Please enter the SSN of the person you want to change GPA: ";
			cin >> AddGPA;
			Hash = CalculateHash(AddSSN);
			InputFile.seekg(58 * Hash, ios::beg); 
			getline(InputFile, InputLine);
			InputFile.seekp(58 * Hash, ios::beg);
			Character = InputLine.substr(0, 9);
			if (Character == AddSSN)
			{
				InputFile.seekp(58 * Hash + 52, ios::beg); 
				cout << "Please change the GPA of this record: ";
				cin >> AddGPA;
				InputFile << AddGPA;
			}
			else
			{
				do
				{
					Hash++; 
					if (Hash == 60) 
					{
						Hash = 0; 
					}
					InputFile.seekg(58 * Hash, ios::beg); 
					getline(InputFile, InputLine);
					InputFile.seekp(58 * Hash, ios::beg); 
					Character = InputLine.substr(0, 9); 
					if (Character == AddSSN)
					{
						InputFile.seekp(58 * Hash + 52, ios::beg); 
						cout << "Please change the GPA of this record: ";
						cin >> AddGPA;
						InputFile << AddGPA;
					}
				} while (Character != AddSSN); 
			}
		}
		system("CLS");
}while (Option != 'X');
InputFile.close();
return 0;
}







int CalculateHash(string X)
{
	int sum = 0;
	for (int i = 0; i < X.size(); i++)
	{
		sum = sum + X[i];
	}
	return (sum % 60);
}
// end function CalculateHash