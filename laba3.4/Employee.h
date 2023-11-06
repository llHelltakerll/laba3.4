#pragma once

#include <vector>
#include "Product.h"
using namespace std;

class Product;


class Employee {
protected:
	int id;
	string name;
	string role;
	vector<int> prod_id_vec;
public:
	Employee(string name, int id, string role) : name(name), id(id), role(role) {};

	virtual void doTask(Product& product) = 0; // ◊»—“Œ ¬»–“”¿À‹Õ¿ﬂ ‘”Õ ÷»ﬂ 

	void printAllProducts(vector<Product>& product_arr);

	void addId(int prod_id);

	int getEmpId();
	string getEmpName();

	bool checkEmptyIdVec();

	int checkProductById(vector<Product>& product_arr, int id);
	void printIdVec();
	int checkProdIdVec(int id);

	string getEmpRole();
};

