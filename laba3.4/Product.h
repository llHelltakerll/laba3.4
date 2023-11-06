#pragma once

#include <iostream>


class Manager;

#define NULL_ID -99999

using namespace std;

enum taskStatus { completed, not_completed };
enum deadLineStatus { passed, not_passed, not_set };

struct task {
	int task_time = 0;
	string task_name = "";
	string task_noties = "";
	taskStatus task_status = not_completed;
	deadLineStatus deadline_status = not_set;
};

enum productStatus { in_stock, out_of_stock, in_development, in_production, no_status };


class Product {

	int id;
	string name;

	productStatus status;

	int manager_id;
	int developer_id;
	int tester_id;

	task product_task;

	friend class Administrator;
	friend class Director;

	void setProductName(string name); // only director
	void setProductId(int id); // only director
	void setProductStatus(productStatus new_status); // only admin
	void setProductTaskStatus(taskStatus new_task_status); // only admin


public:
	Product(string name = "", int id = 0) : name(name), id(id),
		manager_id(0), developer_id(0), tester_id(0), status(no_status) {}

	void setProductEmployees(int manager_id, int developer_id, int tester_id); // only director
	deadLineStatus& getProductDeadlineTaskStatus();
	void setProductTaskTime(int task_time); // manager preferred
	void setProductTaskName(string task_name); // administrator preferred
	void setProductTaskNoties(string task_noties); // tester preffered
	void setProductStatus(taskStatus new_status);
	void setProductDeadlineTaskStatus(deadLineStatus new_deadline_status);

	string getStringDeadlineStatus();
	int getProductId();
	int getManagerId();
	int getDeveloperId();
	int getTesterId();

	string getProductStatus();
	string getProductTask();
	string getProductTaskStatus();
	string getProductName();
	string getProductTaskNoties();
};

