//implementation file for the Employee class
#include "Employee.h"

//this is the default constructor
//assign empty string to string variable and assign 0 to salary variable
Employee::Employee()
{
	employeeId = "";
	firstName = "";
	lastName = "";
	birthDate= "";
	gender = '\0';
	startDate = "";
	salaryPerYear = 0;
}

//this constructor will take the employeeID as an argument
Employee::Employee(string id)
{
	employeeId = id;
	firstName = "";
	lastName = "";
	birthDate= "";
	gender = '\0';
	startDate = "";
	salaryPerYear = 0;

}


//this constructor will take all information
Employee::Employee(string id, string lastN, string firstN, string birthD, char gen, string startD, double salary)
{
	employeeId = id;
	firstName = firstN;
	lastName = lastN;
	birthDate= birthD;
	gender = gen;
	startDate = startD;
	salaryPerYear =  salary;

}

//mutator function for the employeeID
void Employee::setEmployeeId(string id)
{
	employeeId = id;
}

//mutator function for the firstName
void Employee::setFirstName(string firstN)
{
	firstName = firstN;
}

//mutator function for the lastName
void Employee::setLastName(string lastN)
{
	lastName = lastN;
}

//mutator function for the birthDate
void Employee::setBirthDate(string birthD)
{
	birthDate= birthD;
}
//mutator function for the gender
void Employee::setGender(char gen)
{
	gender = gen;
}

//mutator function for the start Date
void Employee::setStartDate(string startD)
{
	startDate = startD;
}

//mutator function for the salary

void Employee::setSalaryPerYear(double salary)
{
	salaryPerYear =  salary;
}

//Accessor function for the employeeID
string  Employee::getEmployeeId() const
{
	return employeeId;
}

//Accessor function for the firstName
string  Employee::getFirstName() const
{
	return firstName;
}

//Accessor function for the lastName
string  Employee::getLastName() const
{
	return lastName;
}

//Accessor function for the birthDate
string  Employee::getBirthDate() const
{
	return birthDate;
}
//Accessor function for the gender
char Employee::getGender() const
{
	return gender;
}

//Accessor function for the start Date
string Employee::getStartDate() const
{
	return startDate;
}

//Accessor function for the salary

double Employee::getSalaryPerYear() const
{
	return salaryPerYear;
}


