#include <iostream>

#include "employee.h"

namespace Records {

Employee::Employee(const std::string &firstName, const std::string &lastName)
    : firstName(firstName), lastName(lastName) {}

void Employee::promote(int raiseAmount) {
  setSalary(getSalary() + raiseAmount);
}
void Employee::demote(int demeritAmount) {
  setSalary(getSalary() - demeritAmount);
}

void Employee::hire() { hired = true; }
void Employee::fire() { hired = false; }

void Employee::display() const {
  std::cout << "Employee: " << firstName << " " << lastName << std::endl;
  std::cout << "Hired: " << hired << std::endl;
  std::cout << "Salary: $" << getSalary() << std::endl;
  std::cout << std::endl;
}

void Employee::setFirstName(const std::string &firstName) {
  this->firstName = firstName;
}
const std::string &Employee::getFirstName() const { return firstName; }

void Employee::setEmployeeNumber(int employeeNumber) {
  this->employeeNumber = employeeNumber;
}
const int Employee::getEmployeeNumber() const { return employeeNumber; }

void Employee::setLastName(const std::string &lastName) {
  this->lastName = lastName;
}
const std::string &Employee::getLastName() const { return lastName; }

void Employee::setSalary(int salary) { this->salary = salary; }
const int Employee::getSalary() const { return salary; }

bool Employee::isHired() const { return hired; }

} // namespace Records
