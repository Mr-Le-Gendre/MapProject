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
    std::string unitsStr, totEnrlStr, capEnrlStr, acadOrg;

    std::getline(stream, subject, ',');       // Subject
    std::getline(stream, catalog, ',');      // Catalog
    std::getline(stream, section, ',');      // Section
    std::getline(stream, component, ',');    // Component
    std::getline(stream, session, ',');      // Session
    std::getline(stream, unitsStr, ',');     // Units
    std::getline(stream, totEnrlStr, ',');   // Total Enrollment
    std::getline(stream, capEnrlStr, ',');   // Capacity Enrollment
    std::getline(stream, acadOrg, ',');      // Discard AcadOrg field

    // Parse instructor name (handle escaped quotes)
    std::getline(stream, instructor, '"'); // Skip the first quote
    std::getline(stream, instructor, '"'); // Read until the second quote

    // Convert numeric fields
    units = std::stoi(unitsStr);
    totEnrl = std::stoi(totEnrlStr);
    capEnrl = std::stoi(capEnrlStr);

    // Ensure all required fields are present
    return !subject.empty() && !catalog.empty() && !section.empty();
}

std::string ScheduleItem::getKey() const {
    return subject + "_" + catalog + "_" + section;
}

void ScheduleItem::print() const {
    std::cout << subject << "\t" << catalog << "\t" << section << "\t" << component << "\t"
        << session << "\t" << units << "\t" << totEnrl << "\t" << capEnrl << "\t"
        << instructor << std::endl;
}

std::string ScheduleItem::toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
