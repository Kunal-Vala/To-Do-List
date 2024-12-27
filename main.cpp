#include <bits/stdc++.h>

using namespace std;

// Task class to handle individual task details
class Task {
    private:
        string task_name;
        string task_desc;
        string task_date;
        int task_id;
        bool task_status;

    public:
        // Default constructor
        Task() : task_name(""), task_desc(""), task_date(""), task_id(0), task_status(false) {}

        // Parameterized constructor
        Task(string name, string desc, string date, int id)
            : task_name(name), task_desc(desc), task_date(date), task_id(id), task_status(false) {}

        // Getter for task ID
        int getTaskId() const {
            return task_id;
        }

        // Getter for task status
        bool getTaskStatus() const {
            return task_status;
        }

        // Setter for task status
        void setTaskStatus(bool status) {
            task_status = status;
        }

        // Getter for task name
        string getTaskName() const {
            return task_name;
        }

        // Getter for task description
        string getTaskDesc() const {
            return task_desc;
        }

        // Getter for task date
        string getTaskDate() const {
            return task_date;
        }
};

// To-Do list class to manage multiple tasks
class To_Do_list {
    private:
        vector<Task> tasks;
        int task_count;  // To keep track of the number of tasks

    public:
        // Default constructor
        To_Do_list() : task_count(0) {}

        // Method to add a new task
        void add_task(string name, string desc, string date) {
            Task new_task(name, desc, date, task_count + 1);
            tasks.push_back(new_task);
            task_count++;
        }

        // Method to remove a task by ID
        void remove_task(int id) {
            auto it = find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
                return task.getTaskId() == id;
            });
            if (it != tasks.end()) {
                tasks.erase(it);
                cout << "Task removed successfully.\n";
            } else {
                cout << "Task ID not found.\n";
            }
        }

        // Method to mark a task as completed by ID
        void mark_task(int id) {
            auto it = find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
                return task.getTaskId() == id;
            });
            if (it != tasks.end()) {
                it->setTaskStatus(true);
                cout << "Task marked as completed.\n";
            } else {
                cout << "Task ID not found.\n";
            }
        }

        // Method to display all tasks
        void display_tasks() const {
            if (tasks.empty()) {
                cout << "No tasks available.\n";
                return;
            }
            for (const auto& task : tasks) {
                cout << "Task ID: " << task.getTaskId() << endl;
                cout << "Task Name: " << task.getTaskName() << endl;
                cout << "Task Description: " << task.getTaskDesc() << endl;
                cout << "Task Date: " << task.getTaskDate() << endl;
                cout << "Task Status: " << (task.getTaskStatus() ? "Completed" : "Incomplete") << endl;
                cout << "----------------------\n";
            }
        }
};

int main() {
    To_Do_list list;
    int choice;
    string name, desc, date;
    int id;

    do {
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Mark Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice) {
            case 1:
                cout << "Enter Task Name: ";
                getline(cin, name);
                cout << "Enter Task Description: ";
                getline(cin, desc);
                cout << "Enter Task Date: ";
                getline(cin, date);
                list.add_task(name, desc, date);
                break;
            case 2:
                cout << "Enter Task ID: ";
                cin >> id;
                list.remove_task(id);
                break;
            case 3:
                cout << "Enter Task ID: ";
                cin >> id;
                list.mark_task(id);
                break;
            case 4:
                list.display_tasks();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 5);

    return 0;
}