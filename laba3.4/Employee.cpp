#include "Employee.h"

int Employee::getEmpId() {
	return id;
}

string Employee::getEmpName() {
	return name;
}

string Employee::getEmpRole() {
	return role;
}

int Employee::checkProductById(vector<Product>& product_arr, int id) {
	for (int i = 0; i < product_arr.size(); i++) {
		if (product_arr[i].getProductId() == id)
			return i;
	}
	return NULL_ID;
}

void Employee::addId(int prod_id) {
	if (NULL_ID == checkProdIdVec(prod_id)) {
		this->prod_id_vec.push_back(prod_id);
	}
}

void Employee::printAllProducts(vector<Product>& product_arr) {
	for (int i = 0; i < product_arr.size(); i++) {
		cout << product_arr[i].getProductId() << " ";
	}
}

void Employee::printIdVec() {
	for (int i = 0; i < prod_id_vec.size(); i++) {
		cout << prod_id_vec[i] << " ";
	}
}

bool Employee::checkEmptyIdVec() {
	return prod_id_vec.empty();
}

int Employee::checkProdIdVec(int id) {
	for (int i = 0; i < prod_id_vec.size(); i++) {
		if (prod_id_vec[i] == id)
			return i;
	}
	return NULL_ID;
}
