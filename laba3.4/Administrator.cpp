#include "Administrator.h"
#include <string>
#include "Product.h"
#include "Check.h"

void Administrator::chooseTask(vector<Product>& product_arr,
	vector<Manager>& manager_arr, vector<Developer>& dev_arr, vector<Tester>& tester_arr) {
	int comd;
	int val_prod_element;
	string task_name;
	int prod_id;

	while (1) {
		bool change_prod_id = false;
		cout << "Existing id: ";
		printAllProducts(product_arr);
		cout << endl;
		cout << "Enter the product id: ";
		prod_id = pos_check();
		if (NULL_ID == (val_prod_element = checkProductById(product_arr, prod_id))) {
			system("cls");
			cout << "No such id!\n\n";
			continue;
		}
		cout << val_prod_element << endl;

		while (1) {
			if (change_prod_id) {
				break;
			}
			cout << "1 - change product status\n"
				"2 - assign workers to product development\n"
				"3 - create task, and give it to manager\n"
				"4 - change product id\n"
				"5 - exit\n";
			comd = pos_check();

			switch (comd) {
			case 1:
				doTask(product_arr[val_prod_element]);
				break;
			case 2:
				addEmpsToProduct(product_arr, manager_arr, dev_arr, tester_arr, val_prod_element, prod_id);
				break;
			case 3:
				cout << "Enter the task name: ";
				
				getline(cin, task_name);
				giveTask(product_arr[val_prod_element], task_name);
				break;
			case 4:
				change_prod_id = true;
				break;
			case 5:
				return;
			}
		}
	}
}

void Administrator::doTask(Product& product) {
	int comd;
	cout << "1 - in stock\n2 - out of stock\n3 - in development\n4 - in production\n";
	comd = pos_check();
	switch (comd) {
	case 1:
		product.status = in_stock;
		break;
	case 2:
		product.status = out_of_stock;
		break;
	case 3:
		product.status = in_development;
		break;
	case 4:
		product.status = in_production;
		break;
	}
}


void Administrator::addEmpsToProduct(vector<Product>& product_arr,
	vector<Manager>& manager_arr, vector<Developer>& dev_arr, vector<Tester>& tester_arr,
	int val_prod_element, int prod_id) {
	while (1) {
		int comd;
		cout << "1 - add new employees\n2 - add already existed employees\n"
			"3 - exit\n";
		comd = pos_check();
		switch (comd) {
		case 1:
			chooseNewEmp(manager_arr, dev_arr, tester_arr);
			break;
		case 2:
			addExistedEmployee(product_arr, manager_arr, dev_arr, tester_arr,
				val_prod_element, prod_id);
			break;
		case 3:
			return;
		}
	}
}

void Administrator::giveTask(Product& product, string task_name) {
	product.setProductTaskName(task_name);
}

void Administrator::addExistedEmployee(vector<Product>& product_arr,
	vector<Manager>& manager_arr, vector<Developer>& dev_arr, vector<Tester>& tester_arr
	, int val_prod_element, int prod_id) {
	int manager_id{};
	int val_emp_element;
	int developer_id{};
	int tester_id{};

	while ((val_emp_element = findElById(manager_arr, "manager", manager_id)) ==
		NULL_ID) {
		cout << "No such manager ID\n";
	}
	manager_arr[val_emp_element].addId(prod_id);

	while ((val_emp_element = findElById(dev_arr, "developer", developer_id)) ==
		NULL_ID) {
		cout << "No such developer ID\n";
	}
	dev_arr[val_emp_element].addId(prod_id);

	while ((val_emp_element = (findElById(tester_arr, "tester", tester_id))) ==
		NULL_ID) {
		cout << "No such developer ID\n";
	}
	tester_arr[val_emp_element].addId(prod_id);

	product_arr[val_prod_element].setProductEmployees(manager_id, developer_id, tester_id);
}

template <typename T>
void Administrator::newEmp(vector<T>& emp_arr, string role) {
	int id;
	string name;
	cout << "Enter id of the new " << role << ": ";
	id = pos_check();
	cout << "Enter name of the new " << role << ": ";
	name = pos_check();
	T new_emp(name, id);
	emp_arr.push_back(new_emp);
}

void Administrator::chooseNewEmp(vector<Manager>& manager_arr,
	vector<Developer>& dev_arr, vector<Tester>& tester_arr) {
	int comd;
	while (1) {
		cout << "What employee you want to add\n"
			"1 - manager\n2 - developer\n3 - tester\n4 - exit\n";
		comd = pos_check();
		switch (comd) {
		case 1:
			newEmp(manager_arr, "manager");
			break;
		case 2:
			newEmp(dev_arr, "developer");
			break;
		case 3:
			newEmp(tester_arr, "tester");
			break;
		case 4:
			return;
		}
	}
}

template <typename T>
int Administrator::checkById(T& emp_arr, int id) {
	for (int i = 0; i < emp_arr.size(); i++) {
		if (emp_arr[i].getEmpId() == id)
			return i;
	}
	return NULL_ID;
}

template <typename T>
void Administrator::printAllEmps(T& emp_arr) {
	for (int i = 0; i < emp_arr.size(); i++) {
		cout << "|(ID: ";
		cout << emp_arr[i].getEmpId() << ") (Name: ";
		cout << emp_arr[i].getEmpName() << ")|";
	}
	cout << endl;
}

template <typename T>
int Administrator::findElById(T& emp_arr, string role, int& emp_id) {
	int emp_val_id;
	cout << "Existed " << role << ": ";
	printAllEmps(emp_arr);
	cout << endl;
	cout << "Enter " << role << " id: ";
	emp_id = pos_check();
	if (NULL_ID == (emp_val_id = checkById(emp_arr, emp_id))) {
		return NULL_ID;
	}
	return emp_val_id;
}

