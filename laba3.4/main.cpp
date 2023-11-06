#include "Administrator.h"
#include "Developer.h"
#include "Director.h"
#include "Employee.h"
#include "Manager.h"
#include "Product.h"
#include "Tester.h"
#include <iostream>
#include "TaskTime.h"
#include "Check.h"

using namespace std;

template <typename T>
int checkEmpArrId(T& emp_arr);

int main()
{
    int emp_id{};
    int emp_val_el{};
    vector<Product> product_arr;
    vector<Manager> manager_arr;
    vector<Developer> dev_arr;
    vector<Tester> tester_arr;
    Product product1("Smetana", 84);
    Director director("Peppa", 12);
    Administrator admin("Pig", 234);
    Manager manager1("Anna", 123);
    Developer developer1("Anger", 35);
    Tester tester1("Fag", 495);
    product_arr.push_back(product1);
    manager_arr.push_back(manager1);
    dev_arr.push_back(developer1);
    tester_arr.push_back(tester1);

    int comd;
    while (1) {
        bool valid_id = false;
        cout << "1 - director\n2 - admin\n3 - manager\n"
            "4 - developer\n5 - tester\n6 - exit\n";
        comd = pos_check();
        switch (comd) {
        case 1:
            director.chooseTask(product_arr);
            break;
        case 2:
            admin.chooseTask(product_arr, manager_arr, dev_arr, tester_arr);
            break;
        case 3:
            if (NULL_ID == (emp_val_el = checkEmpArrId(manager_arr))) {
                break;
            }
            manager_arr[emp_val_el].chooseTask(product_arr);
            break;
        case 4:
            if (NULL_ID == (emp_val_el = checkEmpArrId(dev_arr))) {
                break;
            }
            dev_arr[emp_val_el].chooseTask(product_arr);

            break;
        case 5:
            if (NULL_ID == (emp_val_el = checkEmpArrId(tester_arr))) {
                break;
            }
            tester_arr[emp_val_el].chooseTask(product_arr);
            break;
        case 6:
            exit(0);
        }
    }
}

template <typename T>
int checkEmpArrId(T& emp_arr) {
    int emp_id;
    int emp_val_el;
    bool valid_id = false;
    cout << "Existed " << emp_arr[0].getEmpRole() << " id: ";
    for (int i = 0; i < emp_arr.size(); i++) {
        cout << emp_arr[i].getEmpId() << " ";
    }
    cout << endl;
    cout << "Enter id of " << emp_arr[0].getEmpRole() << ": ";
    emp_id = pos_check();
    for (emp_val_el = 0; emp_val_el < emp_arr.size(); emp_val_el++) {
        if (emp_id == emp_arr[emp_val_el].getEmpId()) {
            valid_id = true;
            break;
        }
    }
    if (!valid_id) {
        cout << "No such id\n";
        return NULL_ID;
    }
    return emp_val_el;
}
