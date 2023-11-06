#include "Product.h"

void Product::setProductStatus(productStatus new_status) {
	this->status = new_status;
}

void Product::setProductTaskStatus(taskStatus new_task_status) {
	product_task.task_status = new_task_status;
}

void Product::setProductTaskTime(int task_time) {
	this->product_task.task_time = task_time;
}

void Product::setProductTaskName(string task_name) {
	this->product_task.task_name = task_name;
}

void Product::setProductTaskNoties(string task_noties) {
	this->product_task.task_noties = task_noties;
}

void Product::setProductEmployees(int manager_id, int developer_id, int tester_id) {
	this->manager_id = manager_id;
	this->developer_id = developer_id;
	this->tester_id = tester_id;
}

int Product::getProductId() {
	return id;
}

string Product::getStringDeadlineStatus() {
	switch (product_task.deadline_status) {
	case not_passed:
		return "not passed";
	case passed:
		return "passed";
	case not_set:
		return "not set";
	}
}

int Product::getManagerId() {
	return manager_id;
}

int Product::getDeveloperId() {
	return developer_id;
}

int Product::getTesterId() {
	return tester_id;
}

string Product::getProductStatus() {
	switch (status) {
	case in_stock:
		return "in stock";
	case out_of_stock:
		return "out of stock";
	case in_development:
		return "in development";
	case in_production:
		return "in production";
	case no_status:
		return "no status";
	}
}

deadLineStatus& Product::getProductDeadlineTaskStatus() {
	return product_task.deadline_status;
}

string Product::getProductTaskNoties() {
	return product_task.task_noties;
}

void Product::setProductStatus(taskStatus new_status) {
	product_task.task_status = new_status;
}

void Product::setProductDeadlineTaskStatus(deadLineStatus new_deadline_status) {
	product_task.deadline_status = new_deadline_status;
}

string Product::getProductTaskStatus() {
	switch (product_task.task_status) {
	case completed:
		return "comleted";
	case not_completed:
		return "not comleted";
	}
}
string Product::getProductTask() {
	return product_task.task_name;
}

string Product::getProductName() {
	return name;
}

void Product::setProductName(string name) {
	this->name = name;
}

void Product::setProductId(int id) {
	this->id = id;
}
