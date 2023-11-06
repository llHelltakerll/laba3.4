#pragma once
#include <vector>
#include "Employee.h"
#include "Product.h"
#include "TaskTime.h"

class Product;
class Employee;

class Manager : public Employee {
	vector<TaskTime> task_vector;
	shared_ptr<TaskTime> pTask = make_shared<TaskTime>(); // создаем умный указатель
public:
	Manager(string name, int id) : Employee(name, id, "Manager") {};

	void doTask(Product& product);

	void chooseTask(vector<Product>& product_arr);
	void setDeadline(Product& product, int time);
};

