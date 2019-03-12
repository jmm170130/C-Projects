/******************************************************************************
* Simple Banking class
*
* This program will execute the function selected by the user from a menu:
*   First the program will display the function menu
*   After, the program will ask the user to select a function
*   After, the program will validate the input.
*   If the input is invalid it will ask for input again
*   Once valid input is entered the program will execute the function selected
*   It will repeat this process until the user enters 7

*  Written by Juan Marquez, starting April 2, 2018.
******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "Bank.h"

using namespace std;


void displayMenu(); //this function will display the menu to the user
int inputValidation(int, bool ); //this function will validate input
void createSavingsObject(Bank *[],Savings *[], int &); //this function will create a savings  object
void createCheckingAccount(Bank *[],Checking*[], int&); //this function will create a checking account
void createBankObject(Bank *[], int&); //this function will create a Bank object
void deposit(Bank *[], int); //this function will deposit money to an account
void withdraw(Bank *[], int); //this function will withdraw money from an account
void displayAllInfo(Bank *[],Savings *[], Checking*[], int); //this function will display all info for all accounts
void displayAccountInfo(Bank *object); //this info for a specific object

int main()
{
	const int MAX = 10; //total max number of account
	Bank *array[MAX]; //array of pointers to objects
	Savings *arraySavings[MAX]; //array of pointers to savings objects
	Checking *arrayChecking[MAX]; //array of pointers to checking object
	bool bFail = true; //used for input validation
	int menuSelection = 0; //variable will hold menu selection from user
	int acctsCount = 0; //keep track of total number of accounts created. Can't have more than 10 accounts

	do
	{
		displayMenu();
		cin >> menuSelection; //get input
		bFail = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		menuSelection = inputValidation(menuSelection, bFail); //call input validation function


		//call desired function
		if (menuSelection == 1)//if user selected function 1 execute code. Create savings account
		{
			if(acctsCount < 10) //Can't have more than 10 accounts
			{
				createSavingsObject(array, arraySavings, acctsCount); //call function to create savings account
			}
			else
			{
				cout << "Can't have more than 10 accounts" << endl;
			}
		}

		else if (menuSelection == 2) //if user selected function 2 execute code. Create checking account
		{
			if(acctsCount < 10) //Can't have more than 10 accounts
			{
				createCheckingAccount(array, arrayChecking, acctsCount); //call function to create checking account
			}
			else
			{
				cout << "Can't have more than 10 accounts" << endl;
			}
		}

		else if (menuSelection == 3) //if user selected function 3 execute code. Create bank object with no parameters
		{
			if(acctsCount < 10) //Can't have more than 10 accounts
			{
				createBankObject(array, acctsCount);

			}
			else
			{
				cout << "Can't have more than 10 accounts" << endl;
			}
		}

		else if (menuSelection == 4) //if user selected function 4 execute code. Deposit to account
		{
			if(acctsCount == 0) //if no accounts have been created output error
			{
				cout << "No accounts have been created" << endl;
			}
			else
			{
				deposit(array, acctsCount); //call function to deposit
			}
		}

		else if (menuSelection == 5) //if user selected function 5 execute code. Withdraw money from an account
		{
			if(acctsCount == 0)//if no accounts have been created output error
			{
				cout << "No accounts have been created" << endl;
			}
			else
			{
				withdraw(array, acctsCount); //call function to withdraw
			}
		}

		else if (menuSelection == 6) //if user selected function 6 execute code.Display all information for all accounts
		{
			if(acctsCount == 0)//if no accounts have been created output error
			{
				cout << "No accounts have been created" << endl;
			}
			else
			{
				displayAllInfo(array,arraySavings, arrayChecking, acctsCount); //call function to display all information
			}
		}


	}
	while(menuSelection != 7); //repeat while menu selection isn't 7
	return 0;
}


void displayMenu() //this function will display the menu to the user
{
	cout << endl;
	//output menu
	cout << "1. Create a Savings object" << endl;
	cout << "2. Create a Checking object" << endl;
	cout << "3. Create a Bank object " << endl;
	cout << "4. Deposit to Bank account" << endl;
	cout << "5. Withdraw from Bank account " << endl;
	cout << "6. Display information for all accounts " << endl;
	cout << "7. Exit Program" << endl;

	cout << endl;
	//request input
	cout << "Please select a function (1-7)" << endl;

}

int inputValidation(int input, bool xFail) //this function will validate input
{
	while(xFail == true || input< 1 || input > 7) //input must be a number and between 1 and 7
	{
		cout << "Invalid Input" << endl; //output error message

		displayMenu();
		cin >> input; //gets the input from user

		xFail = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return input;
}

//this will take a Bank object as a pointer variable to display info
void displayAccountInfo(Bank *object)
{
	cout << '\t' << "Account Number: " << object->getAccountNumber();//display account number
	cout << '\t' << " Name: " << object->getName(); //display name on account
	cout << '\t' << " Balance: " << object->getBalance() ; //display balance
}


void createSavingsObject(Bank *arr[], Savings *arrS[], int &count) //this function will create a savings  object
{
	bool used = false; //will be used to see if an account number is already in use
	bool inputError = false; //will be used to validate input

	//info needed
	int accountNum = 0;
	string name = "";
	double balance = 0;
	double interest = 0;
	int compoundP = 0;

	//ask for input
	cout << "Please enter Account Number: ";
	cin >> accountNum;

	//check for valid input
	inputError = cin.fail();
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	for(int ix = 0; ix < count; ix++)//check if the account number is already being used
	{
		if(accountNum == arr[ix]->getAccountNumber()) //if account number already exist output error message
		{
			cout << "Account Number already in use" << endl;
			cout << endl;
			used = true;
		}
	}
	if(!used && inputError == false) //if the account number is new and valid input is entered then request remaining info.
									//If invalid input is entered output error message.continue asking for input as long as inputError is false
	{
		cout << "Please enter customers Name: ";
		getline(cin, name);
		if(name == "") //check for empty string error
		{
			inputError = true;
		}

		if(inputError == false)
		{
			cout << "Please enter account balance: ";
			cin >> balance;

			//check for input error
			inputError = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if(inputError == false)
		{
			cout << "Please enter Interest Rate: ";
			cin >> interest;

			//check for input error
			inputError = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if(inputError == false)
		{
			cout << "Please enter compound Period: ";
			cin >> compoundP;

			//check for input error
			inputError = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if(inputError == false)
		{
			//create savings object and save it in the arrays
			Savings *ptr;
			ptr = new Savings(accountNum, name, balance);

			arr[count]= ptr;
			arrS[count] = ptr;
			++count; //increment total number of accounts

			//set interest rate and compounding period
			ptr->setInterest(interest);
			ptr->setCompoundPeriod(compoundP);
			cout << endl;
		}
		else if (inputError == true) //if invalid input is entered output error message
		{
			cout << "Invalid Input" << endl;
		}
	}
	else
	{
		cout << "invalid Input" << endl;
	}
}

void createCheckingAccount(Bank *arr[], Checking *arrC[], int& count) //this function will create a checking account
{
	bool used = false;
	bool inputError = false;

	//info needed
	int accountNum = 0;
	string name = "";
	double balance = 0;
	double minimumBalance = 0;
	double monthlyFee = 0;

	//ask for input
	cout << "Please enter account number: ";
	cin >> accountNum;

	//check for invalid input
	inputError = cin.fail();
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	for(int ix = 0; ix < count; ix++)//check is account number is already in use
	{
		if(accountNum == arr[ix]->getAccountNumber()) //if account number already exist output error message
		{
			cout << "Account Number already in use" << endl;
			cout << endl;
			used = true;
		}
	}
	if(!used && inputError == false)//if the account number is not is use and valid input is entered continue.
									//else output error message. Continue asking for input as long as valid input is entered
	{
		cout << "Please enter customers Name: ";
		getline(cin, name);
		if(name == "")
		{
			inputError = true;
		}

		if(inputError == false)
		{
			cout << "Please enter account balance: ";
			cin >> balance;

			//check for invalid input
			inputError = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if(inputError == false)
		{
			cout << "Please enter Minimum Balance: ";
			cin >> minimumBalance;

			//check for invalid input
			inputError = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if(inputError == false)
		{
			cout << "Please enter monthly Fee: ";
			cin >> monthlyFee;

			//check for invalid input
			inputError = cin.fail();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		if(inputError == false)
		{
			Checking *ptr;
			ptr = new Checking(accountNum, name, balance);

			arr[count]= ptr;
			arrC[count] = ptr;
			++count; //increment total number of accounts

			//set minimumBalance and monthly fee
			ptr->setMinimumBalance(minimumBalance);
			ptr->setMonthlyFee(monthlyFee);
			cout << endl;
		}
		else if(inputError == true)
		{
			cout << "Invalid Input" << endl;
		}
	}
	else
	{
		cout << "Input Error" << endl;
	}
}

void createBankObject(Bank *arr[], int& count) //this function will create a Bank object with no parameters
{
	bool inputError = false;
	//info needed
	string name = "";

	//ask for input
	cout << "Please enter customers Name: ";
	getline(cin, name);
	if(name == "") //check for empty string
	{
		inputError = true;
	}

	if(inputError == false) //if valid input is entered continue. Else output error message
	{
		//create a savings account object
		Bank *ptr;
		ptr = new Bank();

		arr[count]= ptr;
		++count; //increment total number of accounts

		ptr->setName(name);
		cout << endl;
	}
	else
	{
		cout << "Invalid Input" << endl;
	}

}

void deposit(Bank *arr[], int count) //this function will deposit money to an account
{
	bool exist = false;
	bool inputError = false; //used for input validation
	int accountN = 0;
	double amount = 0;
	int ix = 0;
	double newBalance;
	//ask for account number
	cout << "Please enter account number: ";
	cin >> accountN;

	//check for invalid input
	inputError = cin.fail();
	cin.clear();
	cin.ignore(INT_MAX, '\n');



	for(; ix < count; ix++)//check to see if account number exist
	{
		if(accountN == arr[ix]->getAccountNumber()) //if account exist set exist to true
		{
			exist = true;
			break;
		}
	}
	if(exist && inputError == false) //if account exist make deposit and valid input is entered then make deposit else output error message
	{
		//ask for amount being deposited
		cout << "Please enter the amount being deposited: ";
		cin >> amount;

		//check for invalid input
		inputError = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//if valid input is entered make deposit. Else output error message
		if(inputError == false)
		{
			newBalance = arr[ix]->deposit(amount);

			//output New balance
			cout << "New Balance: " << newBalance << endl;;
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
	}
	else
	{
		cout << "This account number does not exist " << endl;
	}
}

void withdraw(Bank *arr[], int count) //this function will withdraw money from an account
{
	bool exist = false;
	bool inputError = false;
	int accountN = 0;
	double amount = 0;
	int ix = 0;
	double newBalance;

	//ask for account number
	cout << "Please enter account number: ";
	cin >> accountN;

	//check for invalid input
	inputError = cin.fail();
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	for(; ix < count; ix++)//check if account exist
	{
		if(accountN == arr[ix]->getAccountNumber()) //if account exist set exist to true
		{
			exist = true;
			break;
		}
	}
	if(exist && inputError == false) //if account exist make deposit else output error message
	{
		//ask for amount being withdrawn
		cout << "Please enter the amount being withdrawn: ";
		cin >> amount;

		//check for invalid input
		inputError = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if(arr[ix]->getBalance() >= amount && inputError == false)//if the account has enough money continue else output error message
		{
			newBalance = arr[ix]->withdraw(amount);
			cout << "New Balance: " << newBalance << endl;

		}
		else
		{
			cout << "Insufficient Balance" << endl;
		}

	}
	else
	{
		cout << "This account number does not exist " << endl;
	}
}

void displayAllInfo(Bank *arr[], Savings *arrS[], Checking *arrC[], int count) //this function will display all info for all accounts
{
	for(int ix= 0; ix < count; ix++) //output the information for all the object created
	{
		if(arr[ix]->getAccountType() == 'S') //output saving object info. use savings array to output specific info from the savings objects
		{
			cout << "Account Type: " << arr[ix]->getAccountType();
			displayAccountInfo(arr[ix]); //pass bank object to display info for that specific object
			cout << '\t' <<" Interest: " << arrS[ix]->getInterestRate() ;
			cout << '\t' <<" Compounding Period: " << arrS[ix]->getCompoundPeriod() ;
			cout << endl;
		}
		else if(arr[ix]->getAccountType() == 'C')//output checking object info. Use the checking array to display specific info from the checking object
		{
			cout << "Account Type: " << arr[ix]->getAccountType();
			displayAccountInfo(arr[ix]); //pass bank object to display info for that specific object
			cout << '\t' <<" Minimum Balance: " << arrC[ix]->getMinimumBalance() ;
			cout << '\t' <<" Monthly Fee: " << arrC[ix]->getMonthlyFee() ;
			cout << endl;
		}
		else if(arr[ix]->getAccountType() == 'B')
		{
			cout << "Account Type: " << arr[ix]->getAccountType();
			displayAccountInfo(arr[ix]); //pass bank object to display info for that specific object
			cout << endl;
		}
	}
}
