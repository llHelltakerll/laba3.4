#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Product.h"

using namespace std;

class Director : Employee {
public:
	Director(string name, int id) : Employee(name, id, "Director") {};

	void chooseTask(vector<Product>& product_arr);
	void checkProdInfo(Product& product);
	void doTask(Product& product);
	template<typename T>
	void printAllEmps(T& emp_arr);
};

