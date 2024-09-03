#include <string>

namespace Records {

const int DEFAULT_STARTING_SALARY = 3000;
const int DEFAULT_RAISE_AND_DEMERIT_AMOUNT = 1000;

class Employee {
public:
    Employee() = default;
    Employee(const std::string &firstName, const std::string &lastName);

    void promote(int raiseAmount = DEFAULT_RAISE_AND_DEMERIT_AMOUNT);
    void demote(int demeritAmount = DEFAULT_RAISE_AND_DEMERIT_AMOUNT);
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
    std::string firstName_;
    std::string lastName_;
    int employeeNumber_{-1};
    int salary_{DEFAULT_STARTING_SALARY};
    bool hired_{false};
};

}  // namespace Records
