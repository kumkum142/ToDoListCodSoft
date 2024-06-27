#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

void displayMenu() {
    cout << "\n==== TO-DO LIST ====\n";
    cout << "1. Add Task\n";
    cout << "2. Remove Task\n";
    cout << "3. View Tasks\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Exit\n";
    cout << "====================\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added!\n";
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    int index;
    cout << "Enter index of task to remove: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks.\n";
    } else {
        cout << "\n--- Tasks ---\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
        }
        cout << "-------------\n";
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }
    int index;
    cout << "Enter index of task to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                removeTask(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                markTaskAsCompleted(tasks);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
