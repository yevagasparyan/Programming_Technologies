#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}

    virtual void display() const = 0;

protected:
    std::string name;
    double salary;
};

class IndividualEmployee : public Employee {
public:
    IndividualEmployee(const std::string& name, double salary) : Employee(name, salary) {}

    void display() const override {
        std::cout << "Employee: " << name << ", Salary: " << salary << std::endl;
    }
};

class Department : public Employee {
public:
    Department(const std::string& name) : Employee(name, 0) {}

    void addSubordinate(Employee* subordinate) {
        subordinates.push_back(subordinate);
    }

    void display() const override {
        std::cout << "Department: " << name << ", Salary: " << salary << std::endl;
        for (const auto& subordinate : subordinates) {
            subordinate->display();
        }
    }

private:
    std::vector<Employee*> subordinates;
};

int main() {
    IndividualEmployee emp1("John", 50000);
    IndividualEmployee emp2("Alice", 60000);
    IndividualEmployee emp3("Bob", 55000);

    Department development("Development");
    development.addSubordinate(&emp1);
    development.addSubordinate(&emp2);

    Department marketing("Marketing");
    marketing.addSubordinate(&emp3);

    Department company("Company");
    company.addSubordinate(&development);
    company.addSubordinate(&marketing);

    company.display();

    return 0;
}

