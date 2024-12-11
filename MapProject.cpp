#include <iostream>
#include <fstream>
#include "Schedule.h"

int main() {
    Schedule schedule;

    // Automatically open the file
    std::string fileName = "Summer 2022 Schedule.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return 1;
    }

    schedule.initSchedule(file);
    file.close();

    int choice = 0;
    do {
        std::cout << "Menu:\n"
            << "1. Print All Schedule Items\n"
            << "2. Find by Subject\n"
            << "3. Find by Subject and Catalog\n"
            << "4. Find by Instructor's Last Name\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.printHeader();
            schedule.print();
            break;
        case 2: {
            std::string subject;
            std::cout << "Enter Subject: ";
            std::cin >> subject;
            schedule.findBySubject(subject);
            break;
        }
        case 3: {
            std::string subject, catalog;
            std::cout << "Enter Subject: ";
            std::cin >> subject;
            std::cout << "Enter Catalog: ";
            std::cin >> catalog;
            schedule.findBySubjectAndCatalog(subject, catalog);
            break;
        }
        case 4: {
            std::string lastName;
            std::cout << "Enter Instructor's Last Name: ";
            std::cin >> lastName;
            schedule.findByInstructor(lastName);
            break;
        }
        case 5:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
