// Daniel Hall
// COSC 2030
// Lab 01

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

// Gets file name.
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
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;

	inName = PromptUser();

	// Opening file.
	inFile.open(inName);

	// Error handling for if the file could not be opened.
	if (!inFile.is_open())
	{
		cerr << "Could Not Open: " << inName << endl;
		return 1;
	}

	// Temporary variable for number at some position in the file.
	double tmp = 0;
	// Forced while loop to run infinitely until it hits a break in code.
	while (true)
	{
		// tmp becomes whatever is at this position in the file.
		inFile >> tmp;

		if (inFile.eof())
		{
			// while loop ends when end of file is reached.
			break;
		}

		if (counter == 0)
		{
			// Finds the first number.
			a = tmp;
			counter++;
			continue;
		}

		if (counter == 1)
		{
			// Finds the second number.
			b = tmp;
			counter++;
			continue;
		}

		// As the while loop iterates, c and d move through each position in
		// the file and eventually reach the two end values.
		c = d;
		d = tmp;

		// Iteration of counter.
		counter++;
	}

	// Final printed statement.
	cout << "The total numbers in the file is: " << counter << endl;
	cout << "The first number in the file is: " << a << endl;
	cout << "The second number in the file is: " << b << endl;
	cout << "The second to last number in the file is: " << c << endl;
	cout << "The last number in the file is: " << d << endl;

	system("pause");
	return 0;
}