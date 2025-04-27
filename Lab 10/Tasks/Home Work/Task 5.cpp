#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool done;
};

vector<Task> readTasks(const string& filename) {
    vector<Task> tasks;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (line.substr(0, 1) == "1")
            tasks.push_back({line.substr(2), true});
        else
            tasks.push_back({line.substr(2), false});
    }
    file.close();
    return tasks;
}

void writeTasks(const string& filename, const vector<Task>& tasks) {
    ofstream file(filename);
    for (auto& task : tasks) {
        file << (task.done ? "1" : "0") << " " << task.description << endl;
    }
    file.close();
}

void addTask(const string& filename, const string& desc) {
    ofstream file(filename, ios::app);
    file << "0 " << desc << endl;
    file.close();
}

void viewTasks(const vector<Task>& tasks) {
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].done ? "X" : " ") << "] " << tasks[i].description << endl;
    }
}

void markTaskDone(const string& filename, int index) {
    vector<Task> tasks = readTasks(filename);
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].done = true;
        writeTasks(filename, tasks);
    }
}

int main() {
    string filename = "tasks.txt";
    int choice;
    while (true) {
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task Done\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cin.ignore();
            string desc;
            cout << "Enter task description: ";
            getline(cin, desc);
            addTask(filename, desc);
        } else if (choice == 2) {
            vector<Task> tasks = readTasks(filename);
            viewTasks(tasks);
        } else if (choice == 3) {
            vector<Task> tasks = readTasks(filename);
            viewTasks(tasks);
            cout << "Enter task number to mark done: ";
            int num;
            cin >> num;
            markTaskDone(filename, num);
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
