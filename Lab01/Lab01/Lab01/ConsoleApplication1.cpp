#include "stdafx.h"
#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;

#include<string>
using std::string;

using namespace std;
using std::cerr;
using std::cout;
using std::cin;
using std::endl;



string PromptUser()
{
	string str;

	cout << "Enter the file you want to read numbers from:" << endl;
	getline(cin, str);

	return str;
}

int main()
{
	// Instream and outstream objects.
	string inName;
	string outName;
	ifstream inFile;

	// To determine total numbers.
	double counter = 0;

	// a = first #, b = second #, c = second to last #, d = last #
	double a;
	double b;
	double c;
	double d;

	inName = PromptUser();

	inFile.open(inName);

	if (!inFile.is_open())
	{
		cerr << "Could Not Open: " << inName << endl;
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		counter = 0;
	}
		
	// While not the end of file. (= .eof)
	while (!inFile.eof())
	{
		// While the current data being read is not an integer.
		double tmp;
		
		
		if (!(inFile >> tmp))
		{
			inFile.clear();
			inFile.ignore();
		}
		

		if (counter == 0)
		{
			inFile >> a;
		}
		
		if (counter == 1)
		{
			inFile >> b;
		}

		d = counter;
		c = (counter - 1);
		counter++;
	}

	// This is done because C++ reads until just before the end of the file.
	counter++;
	
	cout << "The total numbers in the file is: " << counter << endl;
	cout << "The first number in the file is: " << a << endl;
	cout << "The second number in the file is: " << b << endl;
	cout << "The second to last number in the file is: " << c << endl;
	cout << "The last number in the file is: " << d << endl;

	system("pause");
    return 0;
}

