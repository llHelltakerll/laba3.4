#include "Director.h"
#include "Check.h"

void Director::doTask(Product& product) {
	cout << "Product name: " << product.getProductName() << endl <<
		"Product id: " << product.getProductId() << endl <<
		"Product status: " << product.getProductStatus() << endl <<
		"Product manager id: " << product.getManagerId() << endl <<
		"Product developer id: " << product.getDeveloperId() << endl <<
		"Product tester id: " << product.getTesterId() << endl <<
		"Product task name: " << product.getProductTask() << endl <<
		"Product task status: " << product.getProductTaskStatus() << endl <<
		"Product deadline status: " << product.getStringDeadlineStatus() << endl;
	cout << "Product task noties: " << product.getProductTaskNoties() << endl;
}

void Director::chooseTask(vector<Product>& product_arr) {
	Product new_product;
	bool valid_id = false;
	int val_prod_element;
	int comd;
	int id;
	string name;
	cout << "What you want to do?\n1-create new product\n2-check product\n";
	comd = pos_check();
	switch (comd)
	{
	case 1:
		cout << "Enter name of the product: ";
		cin >> name;
		cout << "Enter id of the product: ";
		cin >> id;
		new_product.setProductName(name);
		new_product.setProductId(id);
		product_arr.push_back(new_product);
		break;
	case 2:
		cout << "Enter product id. Existing id: " << endl;
		printAllProducts(product_arr);
		cout << endl;
		id = pos_check();
		if (NULL_ID == (val_prod_element = checkProductById(product_arr, id)))
			cout << "No such id!\n";
		else
			doTask(product_arr[val_prod_element]);
		break;
	}
}

template <typename T>
void Director::printAllEmps(T& emp_arr) {
	for (int i = 0; i < emp_arr.size(); i++) {
		cout << "|(ID: ";
		cout << emp_arr[i].getEmpId() << ") (Name: ";
		cout << emp_arr[i].getEmpName() << ")|";
	}
	cout << endl;
}
