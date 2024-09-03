#include "database.h"

#include <stdexcept>

namespace Records {

Employee &DataBase::addEmployee(const std::string &firstName, const std::string &lastName)
{
    Employee employee{firstName, lastName};
    employee.setEmployeeNumber(nextEmployeeNumber_++);
    employee.hire();
    employees_.push_back(employee);
    return employees_.back();
}

Employee &DataBase::getEmployee(int employeeNumber)
{
    for (auto &employee : employees_) {
        if (employee.getEmployeeNumber() == employeeNumber) {
            return employee;
        }
    }
    throw std::logic_error{"No employee found"};
}

Employee &DataBase::getEmployee(const std::string &firstName, const std::string &lastName)
{
    for (auto &employee : employees_) {
        if (employee.getFirstName() == firstName && employee.getLastName() == lastName) {
            return employee;
        }
    }
    throw std::logic_error{"No employee found"};
}

void DataBase::displayAll() const
{
    for (auto &employee : employees_) {
        employee.display();
    }
}

void DataBase::displayCurrent() const
{
    for (auto &employee : employees_) {
        if (employee.isHired()) {
            employee.display();
        }
    }
}

void DataBase::displayFormer() const
{
    for (auto &employee : employees_) {
        if (!employee.isHired()) {
            employee.display();
        }
    }
}

}  // namespace Records
