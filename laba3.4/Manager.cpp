#include "Manager.h"
#include "Check.h"

void Manager::doTask(Product& product) {

}
void Manager::chooseTask(vector<Product>& product_arr) {
	int comd;
	int prod_id{};
	int val_prod_el{};
	int time;
	if (checkEmptyIdVec()) {
		cout << "No products to this manager\n";
		return;
	}
	cout << "Existed product id: ";
	printIdVec();
	cout << endl;
	cout << "Of what product you want to work? ";
	prod_id = pos_check();
	val_prod_el = checkProdIdVec(prod_id);
	if (product_arr[val_prod_el].getProductTask() == "") {
		cout << "No task in this product\n";
		return;
	}
	cout << "1 - set deadline\n2 - check deadline status\n3 - update status\n";
	comd = pos_check();
	switch (comd)
	{
	case 1:
		cout << "With what time you want to set deadline (sec)? ";
		time = pos_check();
		setDeadline(product_arr[val_prod_el], time);
		break;
	case 2:
		cout << "Deadline status: ";
		if (!pTask->getDeadlineStatus()) {
			cout << "Not passed" << endl;
		}
		else {
			cout << "passed" << endl;
		}
		break;
	case 3:
		if (!pTask->getDeadlineStatus()) {
			product_arr[val_prod_el].setProductDeadlineTaskStatus(not_passed);
		}
		else {
			product_arr[val_prod_el].setProductDeadlineTaskStatus(passed);

		}
		cout << "Status updated!\n";
	}
}

void Manager::setDeadline(Product& product, int time) {
	pTask->create_task(time, product);
	product.setProductDeadlineTaskStatus(not_passed);
}