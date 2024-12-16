#include "employee.h"
#include <iostream>

void employee::print() {
    cout << "Name: " << name << "\nID: " << emp_id << "\nBasic Salary: " << salary
        << "\nTotal Salary: " << get_total_salary() << endl;
}
