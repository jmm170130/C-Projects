//<Juan Marquez>

//This program will calculates a customer’s monthly bill for a fractional ownership jet service

// Ask for input of package purchased and output package purchased
//ask for flight hours used and output hours used
//if package a was purchased and flight hours is over 50 ask about weekend usage
//output if they receive discount
//display the cost for the package plus any extra hours
//display any possible savings for package a and b if another package were chosen

#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//declare package variable, flight hours variable and weekend usage variable
	char package; // Package type. character can only be A B or C
	short int flightHours; //amount of flight hours used. flight hours should be whole
	char weekendUsage; //if more than 50% of flight hours were used during the weekend. can only be Y or N

	//display packages and ask for input
	cout << "Enter A, B, or C to indicate the plan purchased by the user:" << endl;
																							//setw was used to align everything
	cout << setw(4) << "A" << " - $100,000.00 per month with 50 flight hours." << endl;
	cout << setw(7) << " " << "$4,000.00 per additional flight hour, but only" << endl;
	cout << setw(7) << " " << "$3,500.00 per additional flight hour if 50% or" << endl;
	cout << setw(7) << " " << "more of the flight hours was used on weekends." << endl;

	cout << setw(4) << "B" << " - $150,000.00 per month with 100 flight hours." << endl;
	cout << setw(7) << " " << "$3,500.00 per additional flight hour. " << endl;

	cout << setw(4) << "C" <<" - $250,000.00 per month for 200 flight hours." << endl;
	cout << setw(7) << " " << "$2,000.00 per additional flight hour." << endl;



	// get input for package. cin.get used to terminate program if "enter" is entered
	cin.get(package);	// accepts "Enter" as an input
	if( (package >= 'A' && package <= 'C' ) || (package >= 'a' && package <= 'c')) //if package is A - C then ignore anything after first character
	{
		cin.ignore(INT_MAX, '\n');//ignores everything after first letter
		cout << "You selected Package: " << package << endl; //output package selected
	}

	//If input is not a ,b or c then terminate program
	else
	{
		cout << "Sorry this is not a valid entry!" << endl;
		cout << "Run the program again and enter a valid entry( A, B or C)" << endl;
		return 0;
	}
	//ask for number of flight hours
	cout << "Please enter the number of flight hours used by the customer" << endl;
	cout << "(should be a whole, non-negative number): ";
	cin >> flightHours;
	cin.ignore(INT_MAX, '\n'); //ignores after decimal point

	//ignore decimals and round
	if( flightHours >= 0) // if flight hours is greater than 0 continue if not terminate program (validating input)
	{
		cout << "You entered: " << (flightHours) << " flight hours" << endl;   //truncates flight hours
	}
	else
	{
		cout << "This is not a valid entry." << endl;
		cout << "Run the program again and enter a valid entry" << endl;

		return 0;
	}
	//output question about weekend usage
	if (((package == 'a') || (package == 'A')) && flightHours > 50) //if package is A  and flight hours is greater than 50 continue.
	{
		cout << "Did the customer use 50% or more of the flight hours" << endl;
		cout <<	" on the weekend? (Y/N) ";
		cin >> weekendUsage;
		cin.ignore(INT_MAX, '\n');

		if (weekendUsage == 'Y' || weekendUsage == 'y') //if weekend usage is Y output that there will be a discount
		{
			cout << "Customer will receive a weekend discount: true" << endl;
		}
		else if (weekendUsage == 'N' || weekendUsage == 'n') //if weekend usage is N output that there will not be a discount
		{
			cout << "Customer will receive a weekend discount: false" <<endl;
		}
		else //if weekend usage is not Y or N terminate program
		{
			cout << "This is not a valid input" << endl;
			cout << "Run the program again and enter either enter  'Y' or 'N'" << endl;
			return 0;
		}
	}


	else //if package b or c were chosen then output no discount. or if less than or equal to 50 hours were used for package a then execute
	{
		cout << "Customer will receive a weekend discount: false" << endl;
	}
	//show only two decimal places
	cout << setprecision(2) << fixed;

	// output total cost for package A and any possible savings if package B or C were selected				//add discount true and false

	if (package == 'A' || package == 'a') //if package is A continue
	{
		if (flightHours <= 50 )//if flight hours is under 50 display cost of 100,000.00
		{
				cout << "The customer's cost for the month is $100000.00" << endl;
		}
			if (weekendUsage == 'N' || weekendUsage == 'n') // if their is no discount then continue
			{
				if( flightHours > 50) //if flight hours is over 50 hours calculate flight hours + extra hour cost ( no discount)
				{
					cout << "The customer's cost for the month is $" << (100000.00 + ((flightHours - 50) * 4000.00)) << endl;
				}
					if (flightHours >= 63 && flightHours <= 100) // savings for plan b when flight hours is more than or equal to 63 and less than or equal to 100
					{
						cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 4000)) - 150000) << " on Package B " << endl;
					}
					else if (flightHours > 100 ) // savings for plan b when flight hours is more than 100 ( extra cost for plan b)
					{
						cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 4000)) - (150000.00 + ((flightHours - 100) * 3500.00))) << " on Package B " << endl;
					}
						if( flightHours >= 88 && flightHours <= 200)//saving for plan c when flight hours is greater than or equal to 88 but less than or equal to 200
						{
							cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 4000)) - 250000) << " on Package C " << endl;
						}
						else if (flightHours > 200)//savings for plan c when flight hours is greater than 200
						{
							cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 4000)) - (250000.00 + ((flightHours - 200) * 2000.00))) << " on Package C " << endl;
						}
			}
		if (weekendUsage == 'Y' || weekendUsage == 'y') // if there is a discount then execute
		{
			if( flightHours > 50) //if flight hours is over 50 hours calculate flight hours + extra hour cost ( with discount)
			{
				cout << "The customer's cost for the month is $" << (100000.00 + ((flightHours - 50) * 3500.00)) << endl;
			}
				if ( flightHours >= 65 && flightHours <= 100) //savings for plan b if flight hours is greater than or equal to 65 and less than or equal to 100
				{
					cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 3500)) - 150000) << " on Package B " << endl;
				}
				else if ( flightHours > 100 ) // savings for plan b if flight hour is more than 100 ( extra cost for flight B)
				{
					cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 3500)) - (150000.00 + ((flightHours - 100) * 3500.00))) << " on Package B " << endl;
				}
					if ( flightHours >= 93 && flightHours <= 200) //savings for plan c if flight hours is greater than or equal to 93 and less than or equal to 200
					{
						cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 3500)) - 250000) << " on Package C " << endl;
					}
					else if (flightHours > 200)//savings for plan c when flight hours is greater than 200 ( extra hour cost for c)
					{
						cout << "Customer would have saved $" << ((100000 + ((flightHours - 50) * 3500)) - (250000.00 + ((flightHours - 200) * 2000.00))) << " on Package C " << endl;
					}
		}
	}
	// output total cost for package B and any possible savings if package C were selected

	if (package == 'B' || package == 'b') //if package is B continue
	{
		if( flightHours > 100) //if flight hours is over 100 calculate flight hours + extra hour cost
		{
			cout << "The customer's cost for the month is $" << (150000.00 + ((flightHours - 100) * 3500.00)) << endl;
		}
		else if (flightHours <= 100)//if flight hours is under 100 display cost of 150,000.00
		{
			cout << "The customer's cost for the month is $150000.00" << endl; //if flight hours is less than 100 hours output flat rate of 150000.00
		}
			if (flightHours >= 129 && flightHours <= 200) // calculate savings for package c if flight hours is more than or equal to 129 but less than 200 (Plan c with no extra hours)
			{
				cout << "Customer would have saved $" << ((150000 + ((flightHours - 100) * 3500)) - 250000) << " on Package C " << endl;
			}
			else if (flightHours > 200)// calculate savings if flight hours is more then 200 continue ( Plan C with extra hours)
			{
				cout << "Customer would have saved $" << ((150000 + ((flightHours - 100) * 3500)) - (250000.00 +((flightHours - 200)) * 2000) ) << " on Package C " << endl;
					// cost of plan B ( flat rate  + ( extra hours * extra hours cost )) minus ( plan c  flat rate + ( extra hours * extra hour cost ))
			}
	}

	// output total cost for package C
	if (package == 'C' || package == 'c') //if package is C continue
	{
		if( flightHours > 200) //if flight hours is over 200 hours calculate flight hours + extra hour cost
		{
			cout << "The customer's cost for the month is $" << (250000.00 + ((flightHours - 200) * 2000.00)) << endl;
			// flat fee of 250000.00 + (extra hours * extra hour cost of 2000.00)
		}
		else //if flight hours is under 200 display cost of 250,000.00
		{
			cout << "The customer's cost for the month is $250000.00" << endl;
		}
	}
	return 0;
}






