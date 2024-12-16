#pragma once
#include "employee.h"

class sales : public employee {
private:
    float gross_sales;
    float commission_rate;

public:
    sales(string n, int id, float s, float g, float c)
        : employee(n, id, s), gross_sales(g), commission_rate(c) {}

    float get_total_salary();
    void print();
    ~sales() { cout << "Sales employee " << name << " deleted.\n"; }
};
