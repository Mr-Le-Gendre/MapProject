#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleItem.h"
#include <string>
#include <map>
#include <fstream>

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

public:
    bool initSchedule(std::ifstream& file); // Changed return type to bool
    void addEntry(const ScheduleItem& item);
    void print() const;
    void printHeader() const;
    void findBySubject(const std::string& subject) const;
    void findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const;
    void findByInstructor(const std::string& lastName) const;
};

#endif // SCHEDULE_H
