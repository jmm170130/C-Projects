#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Employee.h"

using namespace std;

void readFile(int&, Employee *[]); //this function will check to see if Employee.txt exist and read info from the file
void displayMenu(); //this function will display the menu to the user
int inputValidation(int, bool ); //this function will validate input
void newEmployee(int &employeeCount, Employee * []); //this function will add a new employee
void displayInfo(int count, Employee * []); //this function will display info of all employees
void sortArray(int , Employee * []); //this function will sort the employee array
void lookUpEmployee(int, Employee *[]);
void saveData(int , Employee *[]); //this function will save the data to Employee.txt
void removeEmployee(int&, Employee * []); //this function will remove an employee from the array

int main()
{
	const int MAX = 100; //total max number of employees
	Employee *array[MAX]; //array of pointers to objects
	bool bFail = true; //used for input validation
	int menuSelection = 0; //variable will hold menu selection from user
	int count = 0; //keep track of number of employees in array

	readFile(count, array); //call function to read info from a file


	do
	{
		displayMenu();
		cin >> menuSelection; //get input
		bFail = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		menuSelection = inputValidation(menuSelection, bFail); //call input validation function


		//call desired function
		if (menuSelection == 1)//if user selected function 1 execute code. Create new employee
		{
			newEmployee(count, array); //call function to create an new employee object
		}

		else if (menuSelection == 2) //if user selected function 2 execute code. Display all employee information
		{
			if(count == 0) //if count is 0 output error message
			{
				cout << "There is no employee information yet" << endl;
				cout << endl;
			}
			else
			{
				displayInfo(count , array); //call function to display all employee info
			}
		}

		else if (menuSelection == 3) //if user selected function 3 execute code. Look up an employee
		{
			if(count == 0)
			{
				cout << "There is no employee information" << endl;
				cout << endl;
			}
			else
			{
				lookUpEmployee(count, array); //call function to look up an employee
			}
		}

		else if (menuSelection == 4) //if user selected function 4 execute code. Remove an employee
		{
			if(count == 0)
			{
				cout << "There is no employee information" << endl;
				cout << endl;
			}
			else
			{
				removeEmployee(count, array); //call function to remove an employee
			}
		}

		else if (menuSelection == 5) //if user selected function 5 execute code. Save all data and exit
		{
			saveData(count, array); //call function to save all data to Employee.txt
		}
	}
	while(menuSelection != 5); //repeat while menu selection isn't 5
	return 0;
}


void displayMenu() //this function will display the menu to the user
{

	//output menu
	cout << "1. Enter new employee" << endl;
	cout << "2. Display all employee information in alphabetical order" << endl;
	cout << "3. Look up an employee by ID " << endl;
	cout << "4. Remove an employee " << endl;
	cout << "5. Save all data to Employee.txt and exit " << endl;

	cout << endl;
	//request input
	cout << "Please select a function (1-5)" << endl;

}

int inputValidation(int input, bool xFail) //this function will validate input
{
	while(xFail == true || input< 1 || input > 5) //input must be a number and between 1 and 5.
	{
		cout << "Invalid Input" << endl; //output error message
		cout << endl;

		displayMenu();
		cin >> input; //gets the input from user

		xFail = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return input;
}

void newEmployee(int &employeeCount, Employee *arr[]) //this function will add a new employee
{
	bool used = false;
	string id;

	if(employeeCount < 100) // company can't have more than 100 employees
	{

		//ask for ID  of new employee
		cout << "Enter new employee ID" << endl;
		getline(cin,id);

		if(employeeCount > 0) //only compare employee ID's if there is more than one employee
		{
			//make sure id is not in use for other employees.
			for(int ix = 0; ix < employeeCount; ix++ )
			{

				if(id.compare(arr[ix]->getEmployeeId()) == 0) //if the id is already in use output error message and set used to true
				{
					//output error message
					cout << "This ID is already in use for another employee" << endl;
					cout << endl;
					used = true; //set used to true
				}
			}
		}
		if(used == false) //if the id is not already in use then request the rest of the info and create a new employee object
		{
			//variables needed to hold info
			string firstName;
			string lastName;
			string birthDate;
			char gender;
			string startDate;
			double salary;

			//request the rest of info
			cout << "Please enter employees last name: " << endl;
			getline(cin, lastName);

			cout << "Please enter employees first name: " << endl;;
			getline(cin, firstName);

			cout << "Please enter employees birth date (MM/DD/YYYY): " << endl;
			getline(cin, birthDate);

			cout << "Please enter employees gender (M or F) : " << endl;
			cin.get(gender);
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Please enter employees start date: " << endl;
			getline(cin, startDate);

			cout << "Please enter employees salary per year: " << endl;
			cin >> salary;

	      	//dynamic allocation of rectangle
			Employee *ptr;
			ptr = new Employee(id, lastName, firstName, birthDate, gender, startDate, salary);

			arr[employeeCount]= ptr;
			++employeeCount; //increment total number of employees
		}
	}
	else
	{
		cout << "Company can't have more than 100 employees" << endl;
		cout << endl;
	}
}

void displayInfo(int  count, Employee *arr []) //this function will sort and display all employee info
{


	//output headers
	cout << setw(20) << left << "Employee ID" << "|";
	cout << setw(20) << left << "Last Name" << "|";
	cout << setw(20) << left << "First Name" << "|";
	cout << setw(15) << left << "Birth Date" << "|";
	cout << setw(11) << left << "Gender" << "|";
	cout << setw(15) << left << "Start Date" << "|" ;
	cout << setw(20) << left << "Salary" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------" << endl;

	//sort the employee array
	sortArray(count, arr);

	//output employee info
	for(int ix = 0; ix < count; ix++)
	{
		cout << setw(20) << arr[ix]->getEmployeeId() << "|";
		cout << setw(20) << arr[ix]->getLastName() << "|";
		cout << setw(20) << arr[ix]->getFirstName() << "|";
		cout << setw(15) << arr[ix]->getBirthDate() << "|";
		cout << setw(11) << arr[ix]->getGender()<< "|";
		cout << setw(15) << arr[ix]->getStartDate() << "|";

		cout << setprecision(0) << fixed; //round to the nearest dollar
		cout << setw(20) << arr[ix]->getSalaryPerYear();
		cout << endl;
	}
	cout << endl;
}

void sortArray(int count, Employee *sortedArr[]) //this function will sort the employee array
{
	bool swap;
	int iswap = 2; //amount of variables being sorted
	Employee *temp[iswap]; //array used to hold info temporarily
	do
	{
		swap = false;
		for(int ix = 0; ix < count-1; ix++)
		{
			//if the array is not in alphabetical order execute the following code
			if(sortedArr[ix]->getLastName().compare(sortedArr[ix+1]->getLastName()) > 0)
			{
				//save the objects to the temporary array
				int iteration = 0;
				temp[iteration] = sortedArr[ix];
				++iteration;
				temp[iteration] = sortedArr[ix +1];

				//swap the object in the array
				sortedArr[ix] = temp[iteration];
				--iteration;
				sortedArr[ix + 1] = temp[iteration];
				swap = true;

			}
		}

	}while(swap);
}

void lookUpEmployee(int employeeCount, Employee *arr[])
{
	string id; //stores input from user
	bool exist = false; //used for error message

	//ask for input
	cout << "Enter Employee ID: "<< endl;
	getline(cin, id);

	//compare the id entered to existing id's
	for(int ix = 0; ix < employeeCount; ix++ )
	{

		if(id.compare(arr[ix]->getEmployeeId()) == 0) //if the id exist show all the information
		{

			//output all of the employee info
			cout << "Employee ID: " << arr[ix]->getEmployeeId() << endl;
			cout << "Last Name: " << arr[ix]->getLastName()<< endl ;
			cout << "First Name: " << arr[ix]->getFirstName() << endl;
			cout << "Birth Date: " << arr[ix]->getBirthDate() << endl;
			cout << "Gender: " << arr[ix]->getGender()<< endl;
			cout << "Start Date: " <<arr[ix]->getStartDate() << endl;
			cout << "Salary: " << arr[ix]->getSalaryPerYear() << endl;
			cout << endl;
			exist = true; //assign exist to true
			break; //break out from loop

		}
	}
	if(!exist) //if the employee id does not exist output error message
	{
		cout << "There does not exist an employee with that ID" << endl;
		cout << endl;

	}
}

void saveData(int count , Employee *arr[]) //this file will save the data to Employee.txt
{
	ofstream outfile; //output file variable
	outfile.open("Employee.txt"); //open file

	//write to file. One employee per line
	for(int ix = 0; ix < count ; ix++)
	{

		outfile << arr[ix]->getEmployeeId() << '\t';
		outfile << arr[ix]->getLastName() << '\t';
		outfile << arr[ix]->getFirstName() << '\t';
		outfile << arr[ix]->getBirthDate() << '\t';
		outfile << arr[ix]->getGender() << '\t';
		outfile << arr[ix]->getStartDate()  << '\t';
		outfile  << arr[ix]->getSalaryPerYear();
		outfile << endl;
	}

	outfile.close();

}

void removeEmployee(int& count, Employee * arr[])//this function will remove an employee from the array
{
	string id; //stored input from user
	bool exist = false; //used for error message

	//ask for input
	cout << "Enter Employee ID: "<< endl;
	getline(cin, id);

	//compare the id entered to existing id's
	for(int ix = 0; ix < count; ix++ )
	{

		if(id.compare(arr[ix]->getEmployeeId()) == 0) //if the id exist delete employee
		{

			//remove employee object from memory and from the array
			delete arr[ix] ;

			//shift everything in the array down 1
			for(int i=ix;i<count;i++)
			{
				arr[i]=arr[i+1];
			}
			--count; //decrement count

			//validate success
			cout << "Employee has been removed" << endl;
			cout << endl;
			exist = true; //set exist to true
			break; //break from loop
		}
	}
	if(exist == false) //if the employee id does not exist output error message
	{
		cout << "There does not exist an employee with that ID" << endl;
		cout << endl;
	}
}

void readFile(int& count, Employee *arr[]) //this function will check to see if Employee.txt exist and read info from the file
{
	bool noSpace = false;

	//variables will hold employee info
	string employeeId = "";
	string firstName= "";
	string lastName = "";
	string birthDate = "";
	char gender = '\0';
	string startDate = "";
	double salary = 0;

	ifstream infile; //input file variable
	infile.open("Employee.txt"); //open txt file
	if(infile)//if file exist read in the information
	{
		//read from file
		  while (infile >> employeeId >> lastName >> firstName >> birthDate >> gender >> startDate >> salary )
		  {
			  //if there is more than 100 employees output error message and break
			  if(count >= 100)
			  {
				  cout << "Company can't have more than 100 employees" << endl;
				  cout << endl;
				  noSpace = true; //set no space to true
				  break; //break from loop
			  }
			  if(noSpace == false)//if there is space execute following code
			  {
				  // use the input to create a dynamically allocated object
				  Employee *ptr;
				  ptr = new Employee(employeeId, lastName, firstName, birthDate, gender, startDate, salary);

				  //put it in the array of pointers to objects
				  arr[count]= ptr;
				  ++count; //increment total number of employees
			  }
		  }
	}
	infile.close();

}
