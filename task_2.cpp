#include <iostream>
using namespace std;
class Employee {
public:
    virtual float calculateSalary() = 0; 
};

class FullTimeEmployee : public Employee {
private:
    float salary;

public:
    FullTimeEmployee(float s) {
        salary = s;
    }

    float calculateSalary() {
        return salary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hours;
    float rate;

public:
    PartTimeEmployee(int h, float r) {
        hours = h;
        rate = r;
    }

    float calculateSalary() {
        return hours * rate;
    }
};

int main() {
    FullTimeEmployee f(5000);
    PartTimeEmployee p(5, 20);   

    cout << "full Time Salary: " << f.calculateSalary() << endl;
    cout << "part Time Salary: " << p.calculateSalary() << endl;

    return 0;
}