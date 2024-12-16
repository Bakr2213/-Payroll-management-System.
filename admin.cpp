#include "admin.h"
#include <iostream>

float admin::get_total_salary() {
    return salary + (working_hours * hourly_rate);
}

void admin::print() {
    employee::print();
    cout << "Working Hours: " << working_hours
        << "\nHourly Rate: " << hourly_rate << endl;
}
