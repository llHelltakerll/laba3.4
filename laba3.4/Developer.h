#pragma once
#include <vector>
#include <string>
#include "Employee.h"
#include "Product.h"



class Developer : public Employee {
public:
	Developer(string name, int id) : Employee(name, id, "Developer") {};
	void doTask(Product& product);
	void chooseTask(vector<Product>& product_arr);
};

