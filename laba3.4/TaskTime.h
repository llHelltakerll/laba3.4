#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>
#include "Product.h"
#include <mutex>
#include <memory>
#include <atomic>
#include <future>
using namespace std;

class TaskTime : public std::enable_shared_from_this<TaskTime> {
    int time;
    string task_name;
    atomic<bool> is_passed;
public:
    TaskTime();
    TaskTime(const TaskTime& other);
    void countdown();
    bool getDeadlineStatus();
    void  create_task(int time, Product& product);
    void setTime(int time);
    void setTaskName(string task_name);
};






