#pragma once

#include "Employee.h"
#include "Product.h"

class Tester : public Employee {
public:
	Tester(string name, int id) : Employee(name, id, "Employee") {};
	void doTask(Product& product);
	void chooseTask(vector<Product>& product_arr);
};

