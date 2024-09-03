#include <iostream>
#include <ostream>
#include <string>

#include "database.h"

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
                std::cerr << "Unknown command. Try again." << std::endl;
                break;
        }
    }
}

int displayMenu()
{
    std::cout << "0. Quit\n";
    std::cout << "1. Hire\n";
    std::cout << "2. Fire\n";
    std::cout << "3. Promote\n";
    std::cout << "4. Display all\n";
    std::cout << "5. Display current\n";
    std::cout << "6. Display former\n";
    std::cout << "0. Quit\n";
    std::cout << "Enter your selection: ";
    int selection;
    std::cin >> selection;
    return selection;
}

void doHire(Records::DataBase &db)
{
    std::string firstName;
    std::string lastName;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    auto &employee{db.addEmployee(firstName, lastName)};
    std::cout << "Hired employee " << firstName << " " << lastName << " with employee number "
              << employee.getEmployeeNumber() << std::endl;
}

void doFire(Records::DataBase &db)
{
    int employeeNumber;
    std::cout << "Enter employee number: ";
    std::cin >> employeeNumber;

    try {
        Records::Employee &employee{db.getEmployee(employeeNumber)};
        employee.fire();
        std::cout << "Employee " << employeeNumber << " fired.\n";
    } catch (const std::logic_error &e) {
        std::cerr << "Unable to terminate employee: " << e.what() << std::endl;
    }
}

void doPromote(Records::DataBase &db)
{
    int employeeNumber;
    int raiseAmount;

    std::cout << "Enter employee number: ";
    std::cin >> employeeNumber;

    std::cout << "How much of a raise would you like to give? ";
    std::cin >> raiseAmount;

    try {
        Records::Employee &employee{db.getEmployee(employeeNumber)};
        employee.promote(raiseAmount);
        std::cout << "Employee " << employeeNumber << " promoted.\n";
    } catch (const std::logic_error &e) {
        std::cerr << "Unable to promote employee: " << e.what() << std::endl;
    }
}
