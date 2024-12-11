#ifndef SCHEDULE_ITEM_H
#define SCHEDULE_ITEM_H

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

class ScheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totEnrl;
    int capEnrl;
    std::string instructor;

public:
    ScheduleItem(std::string subj = "", std::string cat = "", std::string sec = "",
        std::string comp = "", std::string ses = "", int un = 0, int tot = 0,
        int cap = 0, std::string instr = "")
        : subject(subj), catalog(cat), section(sec), component(comp), session(ses),
        units(un), totEnrl(tot), capEnrl(cap), instructor(instr) {}

    std::string getSubject() const { return subject; }
    std::string getCatalog() const { return catalog; }
    std::string getSection() const { return section; }
    std::string getComponent() const { return component; }
    std::string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotEnrl() const { return totEnrl; }
    int getCapEnrl() const { return capEnrl; }
    std::string getInstructor() const { return instructor; }

    bool operator==(const ScheduleItem& other) const;
    bool operator!=(const ScheduleItem& other) const;
    bool operator>=(const ScheduleItem& other) const;

    bool loadFromStream(std::istream& stream);
    std::string getKey() const;

    void print() const;

    static std::string toLower(const std::string& str);
};

#endif // SCHEDULE_ITEM_H
