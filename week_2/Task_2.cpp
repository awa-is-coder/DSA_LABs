#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	virtual double calculateSalary() = 0;
};
class fullTimeEmployee :public Employee {
private:
	double salary;
public:
	 fullTimeEmployee(double s) {
		salary = s;
}
	double calculateSalary() {
		return salary;
	}
};
class partTimeEmployee :public Employee {
private:
	int hourRate;
	int HourOfWork;
	int MonthDays;
public:
	partTimeEmployee(int H,int h, int D) {
		hourRate = h;
		HourOfWork = H;
		MonthDays = D;
	}
	double calculateSalary() {
		return hourRate * HourOfWork * MonthDays;
	}
};
int main() {
	fullTimeEmployee f1(85000);
	cout << "the salary of Full Time Employee is: " << f1.calculateSalary() << endl;

	partTimeEmployee p1(5, 250,30);
	cout << "the salary of Part Time Employee Based on Hours of work: " << p1.calculateSalary();
	
	return 0;
}

