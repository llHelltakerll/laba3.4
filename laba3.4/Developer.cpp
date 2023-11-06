#include "Developer.h"
#include "Check.h"


void Developer::doTask(Product& product) {
	product.setProductStatus(completed);
}

void Developer::chooseTask(vector<Product>& product_arr) {
	int comd;
	int prod_id{};
	int val_prod_el{};
	int time;
	while (1) {
		bool change_prod_id = false;
		if (checkEmptyIdVec()) {
			cout << "No products to this developer\n";
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
		if (product_arr[val_prod_el].getProductDeadlineTaskStatus() == not_set) {
			cout << "No deadline to this task\n";
			return;
		}
		while (1) {
			if (change_prod_id) {
				break;
			}
			cout << "1 - complete task\n"
				"2 - change product id\n"
				"3 - exit\n";
			comd = pos_check();
			switch (comd)
			{
			case 1:
				doTask(product_arr[val_prod_el]);
				break;
			case 2:
				change_prod_id = true;
				break;
			case 3:
				return;
			}
		}
	}
}
