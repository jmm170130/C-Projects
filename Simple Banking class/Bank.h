//Specification file for the Bank class, Savings class, and checking class
//specification file for the Bank class
#ifndef BANK_H
#define BANK_H
#include <string>
using namespace std;

//base class Bank
class Bank
{
	private:
		int accountNumber;
		string name;

	protected:
		char accountType;
		double balance;
	public:

		//constructors
		Bank();
		Bank(int, string, double);

		//mutators
		double withdraw(double);
		double deposit(double);
		void setName(string);



		//Accessors
		int getAccountNumber() const;
		string getName() const;
		double getBalance() const;
		char getAccountType() const;
};

//derived class savings
class Savings: public Bank
{
	private:
		int compoundPeriod;

	protected:
		double interestRate;

	public:

		//constructors
		Savings();
		Savings(int, string, double);

		//mutators
		double addInterest(int);
		void setInterest(double);
		void setCompoundPeriod(int);

		//accesors
		double getInterestRate() const;
		int getCompoundPeriod() const;

};

//derived class checking
class Checking: public Bank
{
	private:
		double minimumBalance;
		double monthlyFee;

	public:

		//constructors
		Checking();
		Checking(int, string, double);

		//mutators
		void setMinimumBalance(double);
		void setMonthlyFee(double);

		//accesors
		double getMinimumBalance() const;
		double getMonthlyFee() const;

};



#endif





