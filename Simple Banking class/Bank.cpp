//implementation file for the Bank class, Savings class and Checking class
//implementation for the Bank class
#include "Bank.h"
#include <string>

//this is the default constructor
//assign default account number as 9999, an empty string to name variable and a balance of zero
Bank::Bank()
{
	accountNumber = 9999;
	name = "";
	balance = 0;
	accountType = 'B';
}

//this constructor will take all information
Bank::Bank(int accountNum, string accountName, double accountBalance)
{
	accountNumber = accountNum;
	name = accountName ;
	balance = accountBalance;
	accountType = 'B';
}


//mutator function for the withdraw function
double Bank::withdraw(double amount)
{

	//check if sufficient balance is in the account
	if(balance >= amount)
	{
	//if balance is sufficient withdraw specified amount from account and return balance as a string
		balance -= amount;       // string which will contain the result

	}

	return balance;
}

//mutator function for the deposit function
double Bank::deposit(double amount)
{
	//deposit specified amount to account
	balance += amount;
	//return the new balance as a double
	return balance;
}

//mutator function for Name
void Bank::setName(string accountName)
{
	//changes name on the account
	name = accountName;
}


//Accessor function for the Account Number
int  Bank::getAccountNumber() const
{
	return accountNumber;
}

//Accessor function for the Name
string  Bank::getName() const
{
	return name;
}

//Accessor function for the Balance
double  Bank::getBalance() const
{
	return balance;
}

//accessor for account type
char Bank::getAccountType() const
{
	return accountType;
}

//implementation of the savings class
//default constructor for Savings
Savings::Savings()
{
	interestRate = 0;
	compoundPeriod = 0;
	accountType = 'S';
}

//savings constructor will all data
Savings::Savings(int accountNum, string accountName, double accountBalance): Bank(accountNum,accountName, accountBalance)
{
	interestRate = 0;
	compoundPeriod = 0;
	accountType = 'S';
}

//mutator function for adding interest
double Savings::addInterest(int days)
{
	//set interest added to 0
	double interestAdded = 0;

	//calculate total amount of interest added
	interestAdded = interestRate * days* balance;
	balance += interestAdded; //add the interest to the balance
	return interestAdded;
}

//mutator function for setting the interest rate
void Savings::setInterest(double interest)
{
	interestRate = interest;
}

//mutator function for compound period
void Savings::setCompoundPeriod(int period)
{
	compoundPeriod = period;
}

//accesor function for interest rate
double Savings::getInterestRate() const
{
	return interestRate;
}

//accesor function for compoundPeriod
int Savings::getCompoundPeriod() const
{
	return compoundPeriod;
}

//implementation of the checking class
//default constructor for saving

Checking::Checking()
{
	minimumBalance = 0;
	monthlyFee = 0;
	accountType = 'C';
}

//Checking constructor will all data
Checking::Checking(int accountNum, string accountName, double accountBalance) : Bank(accountNum,accountName, accountBalance)
{
	minimumBalance = 0;
	monthlyFee = 0;
	accountType = 'C';
}

//mutator function for minimum balance
void Checking::setMinimumBalance(double amount)
{
	minimumBalance = amount;
}

//mutator function for monthly fee
void Checking::setMonthlyFee(double amount)
{
	monthlyFee = amount;
}


//accesor function for minimum balance
double Checking::getMinimumBalance() const
{
	return minimumBalance;
}

//accesor function for monthly fee
double Checking::getMonthlyFee() const
{
	return monthlyFee;
}
