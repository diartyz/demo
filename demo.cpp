#include <iostream>
#include <ostream>
#include <string>

#include "database.h"
#include "fmt/format.h"

int displayMenu();
void doHire(Records::DataBase &db);
void doFire(Records::DataBase &db);
void doPromote(Records::DataBase &db);
void doDemote(Records::DataBase &db);

int main()
{
    Records::DataBase db;
    bool done{false};
    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 0:
                done = true;
                break;
            case 1:
                doHire(db);
                break;
            case 2:
                doFire(db);
                break;
            case 3:
                doPromote(db);
                break;
            case 4:
                db.displayAll();
                break;
            case 5:
                db.displayCurrent();
                break;
            case 6:
                db.displayFormer();
                break;
            default:
                std::cerr << "Unknown command. Try again.\n";
                break;
        }
    }
}

int displayMenu()
{
    int selection;
    std::cout << "\n";
    std::cout << "Employee Database\n";
    std::cout << "-----------------\n";
    std::cout << "1. Hire a new employee\n";
    std::cout << "2. Fire an employee\n";
    std::cout << "3. Promote an employee\n";
    std::cout << "4. List all employees\n";
    std::cout << "5. List all current employees\n";
    std::cout << "6. List all former employees\n";
    std::cout << "0. Quit\n";
    std::cout << "\n";
    std::cout << "Enter your selection: ";
    std::cin >> selection;
    return selection;
}

void doHire(Records::DataBase &db)
{
    std::string firstName;
    std::string lastName;

    std::cout << "First name? ";
    std::cin >> firstName;
    std::cout << "Last name? ";
    std::cin >> lastName;
    auto &employee{db.addEmployee(firstName, lastName)};
    std::cout << fmt::format("Hired employee {} {} with employee number {}.", firstName, lastName,
                             employee.getEmployeeNumber())
              << "\n";
}

void doFire(Records::DataBase &db)
{
    int employeeNumber;
    std::cout << "Employee number? ";
    std::cin >> employeeNumber;

    try {
        Records::Employee &employee{db.getEmployee(employeeNumber)};
        employee.fire();
        std::cout << fmt::format("Employee {} terminated.", employeeNumber) << "\n";
    } catch (const std::logic_error &e) {
        std::cerr << fmt::format("Unable to terminate employee: {}", e.what()) << "\n";
    }
}

void doPromote(Records::DataBase &db)
{
    int employeeNumber;
    int raiseAmount;

    std::cout << "Employee number? ";
    std::cin >> employeeNumber;

    std::cout << "How much of a raise? ";
    std::cin >> raiseAmount;

    try {
        Records::Employee &employee{db.getEmployee(employeeNumber)};
        employee.promote(raiseAmount);
    } catch (const std::logic_error &e) {
        std::cerr << fmt::format("Unable to promote employee: {}", e.what()) << "\n";
    }
}
