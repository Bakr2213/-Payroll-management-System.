#pragma once
#include "employee.h"

class engineer : public employee {
private:
    string specialty;
    int experience;
    int overtime_hours;
    float overtime_rate;

public:
    engineer(string n, int id, float s, string sp, int ex, int oh, float orate)
        : employee(n, id, s), specialty(sp), experience(ex), overtime_hours(oh), overtime_rate(orate) {}

    float get_total_salary();
    void print();
    ~engineer() { cout << "Engineer " << name << " deleted.\n"; }
};
