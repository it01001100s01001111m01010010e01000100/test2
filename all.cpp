#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Employee {
private:
    
    string name;
    int id;
    double salary;
    
public:
    Employee() : name(""), id(0), salary(0.0) {}

    Employee(string name_, int id_, double salary_):
    name(name_), id(id_), salary(salary_) {};
    
    string getName() const {
        return name;
    };
    
    int getId() const {
        return id;
    };
    
    double getSalary() const {
        return salary;
    };
    
    void setSalary(double newSalary) {
        salary = newSalary;
    };
    
};


bool isValidEmployeeData(const std::string& name, int id, double salary) {
    return (name != "" and id>0 and salary>=0);
};


void saveToFile(const Employee employees[], int size, const string& filename) {
    ofstream outFile(filename);

    
    for (int i = 0; i < size; i++) {
        outFile << employees[i].getId() << " " 
        << employees[i].getName() << " " 
        << employees[i].getSalary() << endl;
    }
    
    outFile.close();
    }



int main() {
    Employee employees[5];
    string name;
    int id;
    double salary;
    int count = 0;
    
    while (count < 3) {
        cout << "Введите имя: " << endl;
        cin >> name;
        
        cout << "Введите ID: " << endl;
        cin >> id;
        
        cout << "Введите зарплату: " << endl;
        cin >> salary;
        if (isValidEmployeeData(name, id, salary)) {
            employees[count] = Employee(name,id,salary);
            count++;
        }
        
        else {
            cout << "Некорректные данные!!!" << endl;
        };
        
    };
    
    saveToFile(employees, 3, "employees.txt");

    
    
    for (int8_t i = 0; i<3; i++) {
        cout << "ID: " << employees[i].getId()<< ' ';

        cout << "Name: " << employees[i].getName() << ' ';
        
        cout << "Salary: " << employees[i].getSalary() << endl;
    };
    
}
