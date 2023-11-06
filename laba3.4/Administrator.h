#pragma once
#include <vector>
#include "Employee.h"
#include "Product.h"
#include "Manager.h"
#include "Developer.h"
#include "Tester.h"

class Administrator : public Employee {
public:
	Administrator(string name, int id) : Employee(name, id, "Administrator") {};

	void doTask(Product& product) override;

	void chooseTask(vector<Product>& product_arr,
		vector<Manager>& manager_arr, vector<Developer>& dev_arr, vector<Tester>& tester_arr);
	void addEmpsToProduct(vector<Product>& product_arr, vector<Manager>& manager_arr,
		vector<Developer>& dev_arr, vector<Tester>& tester_arr, int val_prod_element, int prod_id);
	void chooseNewEmp(vector<Manager>& manager_arr,
		vector<Developer>& dev_arr, vector<Tester>& tester_arr);

	void giveTask(Product& product, string task_name);

	template<typename T>
	void printAllEmps(T& emp_arr);

	template<typename T>
	int findElById(T& emp_arr, string role, int& emp_id);

	template <typename T>
	int checkById(T& manager_arr, int id);

	template <typename T>
	void newEmp(vector<T>& emp_arr, string role);

	void addExistedEmployee(vector<Product>& product_arr, vector<Manager>& manager_arr,
		vector<Developer>& dev_arr, vector<Tester>& tester_arr, int val_prod_element, int prod_id);
};

