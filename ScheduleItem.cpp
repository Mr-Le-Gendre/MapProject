#include "ScheduleItem.h"

bool ScheduleItem::operator==(const ScheduleItem& other) const {
    return subject == other.subject && catalog == other.catalog && section == other.section;
}

bool ScheduleItem::operator!=(const ScheduleItem& other) const {
    return !(*this == other);
}

bool ScheduleItem::operator>=(const ScheduleItem& other) const {
    return subject >= other.subject && catalog >= other.catalog && section >= other.section;
}

bool ScheduleItem::loadFromStream(std::istream& stream) {
    std::string unitsStr, totEnrlStr, capEnrlStr;

    std::getline(stream, subject, ',');
    std::getline(stream, catalog, ',');
    std::getline(stream, section, ',');
    std::getline(stream, component, ',');
    std::getline(stream, session, ',');
    std::getline(stream, unitsStr, ',');
    std::getline(stream, totEnrlStr, ',');
    std::getline(stream, capEnrlStr, ',');
    std::getline(stream, instructor, ',');

    units = std::stoi(unitsStr);
    totEnrl = std::stoi(totEnrlStr);
    capEnrl = std::stoi(capEnrlStr);

    return !subject.empty() && !catalog.empty() && !section.empty();
}

std::string ScheduleItem::getKey() const {
    return subject + "_" + catalog + "_" + section;
}

void ScheduleItem::print() const {
    std::cout << subject << "\t" << catalog << "\t" << section << "\t" << component << "\t"
        << session << "\t" << units << "\t" << totEnrl << "\t" << capEnrl << "\t" << instructor << std::endl;
}

std::string ScheduleItem::toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
