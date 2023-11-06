#include "TaskTime.h"

void TaskTime::countdown() {
    this_thread::sleep_for(chrono::seconds(time)); // СПИТ
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << endl;
    cout << "Task deadline: " << this->task_name << " passed!\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    this->is_passed.store(true, std::memory_order_relaxed);
}

void TaskTime::setTime(int time) {
    this->time = time;
}


void TaskTime::setTaskName(string task_name) {
    this->task_name = task_name;
}

bool TaskTime::getDeadlineStatus() {
    return is_passed.load(memory_order_relaxed);
}

TaskTime::TaskTime(const TaskTime& other) {
    time = other.time;
    task_name = other.task_name;
    is_passed.store(other.is_passed.load());
}

TaskTime::TaskTime() {
    time = 0;
    task_name = "";
    is_passed.store(false);
}

void TaskTime::create_task(int time, Product& p_product) {

    this->setTime(time);
    this->setTaskName(p_product.getProductTask());
    thread t1(&TaskTime::countdown, this); // Создаем новый поток t1
    t1.detach(); // Дожидаемся завершения потока t1
}