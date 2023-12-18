#pragma once
#include <string>

namespace Records {

const int DEFAULT_STARTING_SALARY = 3000;

class Employee {
public:
  Employee() = default;
  Employee(const std::string &firstName, const std::string &lastName);

  void promote(int raiseAmount = 1000);
  void demote(int demeritAmount = 1000);
  void hire();
  void fire();
  void display() const;

  void setFirstName(const std::string &firstName);
  const std::string &getFirstName() const;

  void setLastName(const std::string &lastName);
  const std::string &getLastName() const;

  void setEmployeeNumber(int employeeNumber);
  const int getEmployeeNumber() const;

  void setSalary(int salary);
  const int getSalary() const;

  bool isHired() const;

private:
  std::string firstName;
  std::string lastName;
  int employeeNumber = -1;
  int salary = DEFAULT_STARTING_SALARY;
  bool hired = false;
};

} // namespace Records
