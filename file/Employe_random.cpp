//Company maintains employee information such as employee ID, name, designation and salary. Allow the user to add, delete information of an employee. Display information of a particular employee. If an employee does not exist, an appropriate message is displayed. If the employee exists, then the system displays the employee details. Use a direct access file to maintain the data.

//use following as options to each other
//reinterpret_cast<char*>(&emp)
//(char*)&emp

//create file employees.dat if not automatically created

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int EMPLOYEE_SIZE = 60;  // Size of each employee record in bytes

// Employee structure represents the structure of an employee record
struct Employee {
    int emp_id;
    char name[20];
    char designation[20];
    double salary;
};

void addEmployee(fstream& file) {
    Employee emp;

    cout << "Enter Employee ID: ";
    cin >> emp.emp_id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    cin.getline(emp.name, 20);

    cout << "Enter Employee Designation: ";
    cin.getline(emp.designation, 20);

    cout << "Enter Employee Salary: ";
    cin >> emp.salary;

    file.seekp((emp.emp_id - 1) * EMPLOYEE_SIZE, ios::beg);
    file.write((char*)&emp, sizeof(emp));

    cout << "Employee added successfully!" << endl;
}

void deleteEmployee(fstream& file) {
    int emp_id;

    cout << "Enter Employee ID to delete: ";
    cin >> emp_id;

    file.seekp((emp_id - 1) * EMPLOYEE_SIZE, ios::beg);

    Employee emp;
    file.write((char*)&emp, sizeof(emp));

    cout << "Employee deleted successfully!" << endl;
}

void displayEmployee(fstream& file) {
    int emp_id;

    cout << "Enter Employee ID to display: ";
    cin >> emp_id;

    file.seekg((emp_id - 1) * EMPLOYEE_SIZE, ios::beg);

    Employee emp;
    file.read((char*)&emp, sizeof(emp));

    if (emp.emp_id == 0) {
        cout << "Employee not found!" << endl;
    } else {
        cout << "Employee ID: " << emp.emp_id << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Salary: " << emp.salary << endl;
    }
}

int main() {
    fstream file;
    file.open("employees.dat", ios::out | ios::in | ios::binary);

    if (!file) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    int choice;

    do {
        cout << "------ Employee Management System ------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                deleteEmployee(file);
                break;
            case 3:
                displayEmployee(file);
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 4);

    file.close();

    return 0;
}
