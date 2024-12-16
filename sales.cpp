#include "sales.h"
#include <iostream>

float sales::get_total_salary() {
    return salary + (gross_sales * commission_rate);
}

void sales::print() {
    employee::print();
    cout << "Gross Sales: " << gross_sales
        << "\nCommission Rate: " << commission_rate << endl;
}
