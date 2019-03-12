#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	//This program will read in the number of seconds
	//and then calculating how far sound can travel in a specified medium in that many seconds.


	//output options for medium and ask for input
	//Use if - else statement to verify valid input
	//if input is valid then ask for time in seconds that it traveled
	// time must be between 0 and 30 (inclusive) if not output message
	// if input is valid then output value entered with 1 digit of precision (fixed)
	//calculate meters traveled with 2 digits of precision

	//declare variable medium and seconds
	unsigned int medium;
	double seconds;


	//output options for medium and ask for input
	cout << "Select the medium that sound is traveling through:" << endl;
	cout << "1 Carbon Dioxide"  << endl;
	cout << "2 Air"  << endl;
	cout << "3 Helium"  << endl;
	cout << "4 Hydrogen"  << endl;

	//accept input
	cin >> medium;

	//Use if - else statement to verify valid input (1-4)
	if (medium >=1 && medium <=4)
	{
		cout << "Enter time (in seconds)" << endl; //ask for input for seconds
		cin >> seconds;

	}
	else //output error message
	{
		cout << "The menu value is invalid. Please run the program again." << endl;
		return 0;
	}

	//verify input for seconds if medium is Carbon Dioxide
	if ((seconds >= 0.0) && (seconds <=30.0) && (medium == 1))
	{
		cout << setprecision(1) << fixed; //1 digit of precision for seconds (fixed)
		cout << "Carbon Dioxide: " << seconds << " seconds" << endl; //output seconds entered
		cout << setprecision(2) << fixed; //2 digit of precision for speed (fixed)
		cout << "Traveled " << (seconds * 258.0)   << " meters" << endl; //output distance traveled in meters( seconds times speed(m/s)

	}
	else if ((seconds >= 0.0) && (seconds <=30.0) && (medium == 2)) //if medium is air continue
	{
		cout << setprecision(1) << fixed; //1 digit of precision for seconds (fixed)
		cout << "Air: " << seconds << " seconds" << endl; //output seconds entered
		cout << setprecision(2) << fixed; //2 digit of precision for speed (fixed)
		cout << "Traveled " << (seconds * 331.5)   << " meters" << endl; //output distance traveled in meters
	}
	else if ((seconds >= 0.0) && (seconds <=30.0) && (medium == 3)) //if medium is Helium continue
	{
		cout << setprecision(1) << fixed; //1 digit of precision for seconds (fixed)
		cout << "Helium: " << seconds << " seconds" << endl; //output seconds entered
		cout << setprecision(2) << fixed; //2 digit of precision for speed (fixed)
		cout << "Traveled " << (seconds * 972.0)   << " meters" << endl; //output distance traveled in meters
	}
	else if ((seconds >= 0.0) && (seconds <=30.0) && (medium == 4)) //if medium is Hydrogen continue
	{
		cout << setprecision(1) << fixed; //1 digit of precision for seconds (fixed)
		cout << "Hydrogen: " << seconds << " seconds" << endl; //output seconds entered
		cout << setprecision(2) << fixed; //2 digit of precision for speed (fixed)
		cout << "Traveled " << (seconds * 1270.0)   << " meters" << endl; //output distance traveled in meters
	}
	else
	{
		cout << "The time must be between 0.0 and 30.0 (inclusive)" << endl;
	}

	return 0;
}




