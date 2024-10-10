#include "employee.h"

#include <iostream>

#include "fmt/format.h"

namespace Records {

Employee::Employee(const std::string &firstName, const std::string &lastName)
    : firstName_(firstName), lastName_(lastName)
{
}

void Employee::promote(int raiseAmount)
{
    setSalary(getSalary() + raiseAmount);
}
void Employee::demote(int demeritAmount)
{
    setSalary(getSalary() - demeritAmount);
}

void Employee::hire()
{
    hired_ = true;
}
void Employee::fire()
{
    hired_ = false;
}

void Employee::display() const
{
    std::cout << fmt::format("Employee: {}, {}", getFirstName(), getLastName()) << "\n";
    std::cout << (isHired() ? "Current Employee" : "Former Employee") << "\n";
    std::cout << fmt::format("Employee Number: {}", getEmployeeNumber()) << "\n";
    std::cout << fmt::format("Salary: ${}", getSalary()) << "\n";
    std::cout << "\n";
}

void Employee::setFirstName(const std::string &firstName)
{
    firstName_ = firstName;
}
const std::string &Employee::getFirstName() const
{
    return firstName_;
}

void Employee::setEmployeeNumber(int employeeNumber)
{
    employeeNumber_ = employeeNumber;
}
const int Employee::getEmployeeNumber() const
{
    return employeeNumber_;
}

void Employee::setLastName(const std::string &lastName)
{
    lastName_ = lastName;
}
const std::string &Employee::getLastName() const
{
    return lastName_;
}

void Employee::setSalary(int salary)
{
    salary_ = salary;
}
const int Employee::getSalary() const
{
    return salary_;
}

bool Employee::isHired() const
{
    return hired_;
}

}  // namespace Records
