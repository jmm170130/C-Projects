//Specification file for the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
	private:
		string employeeId;
		string firstName;
		string lastName;
		string birthDate;
		char gender;
		string startDate;
		double salaryPerYear;

	public:

		//constructors
		Employee();
		Employee(string);
		Employee(string, string, string, string, char, string, double);

		//mutators
		void setEmployeeId(string);
		void setLastName(string);
		void setFirstName(string);
		void setBirthDate(string);
		void setGender(char);
		void setStartDate(string);
		void setSalaryPerYear(double);

		//Accessors
		string getEmployeeId() const;
		string getLastName() const;
		string getFirstName() const;
		string getBirthDate() const;
		char getGender() const;
		string getStartDate() const;
		double getSalaryPerYear() const;
};
#endif


