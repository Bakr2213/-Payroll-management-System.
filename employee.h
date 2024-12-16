#pragma once
#include <iostream>
#include <string>
using namespace std;

class employee {
protected:
    string name;
    int emp_id;
    float salary;

public:
    employee() : name("unknown"), emp_id(0), salary(0.0) {}
    employee(string n, int id, float s) : name(n), emp_id(id), salary(s) {}

    virtual float get_total_salary() = 0;  // دالة افتراضية لحساب الراتب
    virtual void print();  // طباعة تفاصيل الموظف

    int get_id() const { return emp_id; }  // دالة لإرجاع ID الموظف
    string get_name() const { return name; }

    virtual ~employee() { cout << "Goodbye " << name << endl; }
};
