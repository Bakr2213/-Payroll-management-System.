#pragma once
#include "employee.h"

class admin : public employee {
private:
    int working_hours;
    float hourly_rate;

public:
    admin(string n, int id, float s, int wh, float hr)
        : employee(n, id, s), working_hours(wh), hourly_rate(hr) {}

    float get_total_salary();
    void print();
    ~admin() { cout << "Admin " << name << " deleted.\n"; }
};
