#include "engineer.h"
#include <iostream>

float engineer::get_total_salary() {
    return salary + (overtime_hours * overtime_rate);
}

void engineer::print() {
    employee::print();
    cout << "Specialty: " << specialty
        << "\nExperience: " << experience
        << "\nOvertime Hours: " << overtime_hours
        << "\nOvertime Rate: " << overtime_rate << endl;
}
