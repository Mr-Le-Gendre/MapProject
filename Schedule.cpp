#include "Schedule.h"
#include <iostream>
#include <sstream>
#include <algorithm>

// Utility function to convert strings to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Initialize schedule from file
bool Schedule::initSchedule(std::ifstream& file) {
    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        ScheduleItem item;
        if (item.loadFromStream(stream)) {
            addEntry(item);
        }
        else {
            std::cerr << "Invalid schedule item: " << line << std::endl;
        }
    }

    return true;
}

// Add entry to schedule
void Schedule::addEntry(const ScheduleItem& item) {
    scheduleMap[item.getKey()] = item;
}

// Print all schedule items
void Schedule::print() const {
    for (const auto& entry : scheduleMap) {
        entry.second.print();
    }
}

// Print header
void Schedule::printHeader() const {
    std::cout << "Subject\tCatalog\tSection\tComponent\tSession\tUnits\tTotEnrl\tCapEnrl\tInstructor" << std::endl;
}

// Find by subject
void Schedule::findBySubject(const std::string& subject) const {
    std::string lowerSubject = toLower(subject);
    bool found = false;
    for (const auto& entry : scheduleMap) {
        if (toLower(entry.second.getSubject()) == lowerSubject) {
            entry.second.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No schedule items found for Subject: " << subject << std::endl;
    }
}

// Find by subject and catalog
void Schedule::findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const {
    std::string lowerSubject = toLower(subject);
    std::string lowerCatalog = toLower(catalog);
    bool found = false;
    for (const auto& entry : scheduleMap) {
        if (toLower(entry.second.getSubject()) == lowerSubject &&
            toLower(entry.second.getCatalog()) == lowerCatalog) {
            entry.second.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No schedule items found for Subject: " << subject << " and Catalog: " << catalog << std::endl;
    }
}

// Find by instructor
void Schedule::findByInstructor(const std::string& lastName) const {
    std::string lowerLastName = toLower(lastName);
    bool found = false;
    for (const auto& entry : scheduleMap) {
        std::string instructorFullName = entry.second.getInstructor();
        std::string instructorLastName;

        // Split the instructor name by the comma to get the last name
        size_t commaPos = instructorFullName.find(',');
        if (commaPos != std::string::npos) {
            instructorLastName = instructorFullName.substr(0, commaPos);
        }
        else {
            instructorLastName = instructorFullName; // In case there's no comma
        }

        if (toLower(instructorLastName) == lowerLastName) {
            entry.second.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No schedule items found for Instructor: " << lastName << std::endl;
    }
}
