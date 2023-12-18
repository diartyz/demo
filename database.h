#pragma once
#include <iostream>
#include <vector>

#include "employee.h"

namespace Records {

const int FIRST_EMPLOYEE_NUMBER = 1000;

class DataBase {
public:
  Employee &addEmployee(const std::string &firstName,
                        const std::string &lastName);
  Employee &getEmployee(int employeeNumber);
  Employee &getEmployee(const std::string &firstName,
                        const std::string &lastName);

  void displayAll() const;
  void displayCurrent() const;
  void displayFormer() const;

private:
  std::vector<Employee> employees;
  int nextEmployeeNumber = FIRST_EMPLOYEE_NUMBER;
};

} // namespace Records
