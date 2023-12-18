#include <stdexcept>

#include "database.h"

namespace Records {

Employee &DataBase::addEmployee(const std::string &firstName,
                                const std::string &lastName) {
  Employee employee(firstName, lastName);
  employee.setEmployeeNumber(nextEmployeeNumber++);
  employee.hire();
  employees.push_back(employee);
  return employees.back();
}

Employee &DataBase::getEmployee(int employeeNumber) {
  for (auto &employee : employees) {
    if (employee.getEmployeeNumber() == employeeNumber) {
      return employee;
    }
  }
  throw std::logic_error("No employee found");
}

Employee &DataBase::getEmployee(const std::string &firstName,
                                const std::string &lastName) {
  for (auto &employee : employees) {
    if (employee.getFirstName() == firstName &&
        employee.getLastName() == lastName) {
      return employee;
    }
  }
  throw std::logic_error("No employee found");
}

void DataBase::displayAll() const {
  for (auto &employee : employees) {
    employee.display();
  }
}

void DataBase::displayCurrent() const {
  for (auto &employee : employees) {
    if (employee.isHired()) {
      employee.display();
    }
  }
}

void DataBase::displayFormer() const {
  for (auto &employee : employees) {
    if (!employee.isHired()) {
      employee.display();
    }
  }
}

} // namespace Records
