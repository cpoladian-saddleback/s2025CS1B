#include <iostream>
#include <vector>
#include <limits>

struct Employee {
    int id;
    std::string name;
    double salary;
};

// Function to print all employees
void printEmployees(const std::vector<Employee>& employees) {
    if (employees.empty()) {
        std::cout << "No employees found.\n";
        return;
    }
    std::cout << "\nEmployee List:\n";
    for (const auto& emp : employees) {
        std::cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << "\n";
    }
}

// Function to add a new employee
void addEmployee(std::vector<Employee>& employees) {
    Employee newEmp;
    std::cout << "Enter Employee ID: ";
    std::cin >> newEmp.id;
    std::cout << "Enter Name: ";
    std::cin >> newEmp.name;
    std::cout << "Enter Salary: ";
    std::cin >> newEmp.salary;

    employees.push_back(newEmp);
    std::cout << "Employee added successfully!\n";
}

// Function to update an employee by ID
void updateEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter Employee ID to update: ";
    std::cin >> id;

    for (auto& emp : employees) {
        if (emp.id == id) {
            std::cout << "Enter new name: ";
            std::cin >> emp.name;
            std::cout << "Enter new salary: ";
            std::cin >> emp.salary;
            std::cout << "Employee updated successfully!\n";
            return;
        }
    }
    std::cout << "Employee with ID " << id << " not found.\n";
}

// Function to remove an employee by ID
void removeEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter Employee ID to remove: ";
    std::cin >> id;

    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            employees.erase(employees.begin() + i);
            std::cout << "Employee removed successfully!\n";
            return;
        }
    }
    std::cout << "Employee with ID " << id << " not found.\n";
}

// Function to search for an employee by name
void searchEmployee(const std::vector<Employee>& employees) {
    std::string name;
    std::cout << "Enter employee name to search: ";
    std::cin >> name;

    for (const auto& emp : employees) {
        if (emp.name == name) {
            std::cout << "Found Employee -> ID: " << emp.id << ", Salary: $" << emp.salary << "\n";
            return;
        }
    }
    std::cout << "Employee not found.\n";
}

// Function to print the employee with the highest salary
void highestSalaryEmployee(const std::vector<Employee>& employees) {
    if (employees.empty()) {
        std::cout << "No employees available.\n";
        return;
    }

    Employee maxSalaryEmp = employees[0];
    for (const auto& emp : employees) {
        if (emp.salary > maxSalaryEmp.salary) {
            maxSalaryEmp = emp;
        }
    }

    std::cout << "Employee with Highest Salary: ID: " << maxSalaryEmp.id << ", Name: " << maxSalaryEmp.name << ", Salary: $" << maxSalaryEmp.salary << "\n";
}

// Menu function
void menu() {
    std::vector<Employee> employees;
    char choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "a. Print all employees\n";
        std::cout << "b. Add a new employee\n";
        std::cout << "c. Update an employee\n";
        std::cout << "d. Remove an employee\n";
        std::cout << "e. Search employee by name\n";
        std::cout << "f. Print employee with highest salary\n";
        std::cout << "g. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a': printEmployees(employees); break;
            case 'b': addEmployee(employees); break;
            case 'c': updateEmployee(employees); break;
            case 'd': removeEmployee(employees); break;
            case 'e': searchEmployee(employees); break;
            case 'f': highestSalaryEmployee(employees); break;
            case 'g': std::cout << "Exiting program...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 'g');
}

int main() {
    menu();
    return 0;
}
