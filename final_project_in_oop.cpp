#include <iostream>
#include <queue>
#include "sales.h"
#include "engineer.h"
#include "admin.h"
using namespace std;

// دوال لإنشاء الموظفين
sales create_sales() {
    string name;
    int id;
    float salary, gross_sales, commission_rate;

    cout << "Enter Sales Employee Details:\n";
    cout << "Name: "; cin >> name;
    cout << "ID: "; cin >> id;
    cout << "Salary: "; cin >> salary;
    cout << "Gross Sales: "; cin >> gross_sales;
    cout << "Commission Rate: "; cin >> commission_rate;

    return sales(name, id, salary, gross_sales, commission_rate);
}

engineer create_engineer() {
    string name, specialty;
    int id, experience, overtime_hours;
    float salary, overtime_rate;

    cout << "Enter Engineer Employee Details:\n";
    cout << "Name: "; cin >> name;
    cout << "ID: "; cin >> id;
    cout << "Salary: "; cin >> salary;
    cout << "Specialty: "; cin >> specialty;
    cout << "Experience (years): "; cin >> experience;
    cout << "Overtime Hours: "; cin >> overtime_hours;
    cout << "Overtime Rate: "; cin >> overtime_rate;

    return engineer(name, id, salary, specialty, experience, overtime_hours, overtime_rate);
}

admin create_admin() {
    string name;
    int id, working_hours;
    float salary, hourly_rate;

    cout << "Enter Admin Employee Details:\n";
    cout << "Name: "; cin >> name;
    cout << "ID: "; cin >> id;
    cout << "Salary: "; cin >> salary;
    cout << "Working Hours: "; cin >> working_hours;
    cout << "Hourly Rate: "; cin >> hourly_rate;

    return admin(name, id, salary, working_hours, hourly_rate);
}

void delete_employee(queue<employee*>& employees, int id) {
    queue<employee*> temp_queue;

    bool found = false;
    while (!employees.empty()) {
        employee* emp = employees.front();
        employees.pop();
        if (emp->get_id() == id) {
            delete emp;  // حذف الموظف
            found = true;
            cout << "Employee with ID " << id << " deleted.\n";
        }
        else {
            temp_queue.push(emp);  // نقل الموظفين الآخرين إلى الطابور المؤقت
        }
    }

    if (!found) {
        cout << "Employee ID not found!\n";
    }

    employees = temp_queue;  // إعادة الطابور بعد الحذف
}

int main() {
    queue<employee*> employees;
    char choice;

    do {
        cout << "Choose Employee Type to Add (S for Sales, E for Engineer, A for Admin): ";
        cin >> choice;

        if (choice == 'S' || choice == 's') {
            employees.push(new sales(create_sales()));
        }
        else if (choice == 'E' || choice == 'e') {
            employees.push(new engineer(create_engineer()));
        }
        else if (choice == 'A' || choice == 'a') {
            employees.push(new admin(create_admin()));
        }
        else {
            cout << "Invalid choice!\n";
        }

        cout << "Add another employee? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\nAll Employees:\n";
    queue<employee*> temp = employees;
    while (!temp.empty()) {
        temp.front()->print();
        cout << "-------------------\n";
        temp.pop();
    }

    cout << "Delete an employee? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        int id;
        cout << "Enter Employee ID to Delete: ";
        cin >> id;
        delete_employee(employees, id);
    }

    cout << "\nRemaining Employees:\n";
    while (!employees.empty()) {
        employees.front()->print();
        cout << "-------------------\n";
        employees.pop();
    }

    return 0;
}
