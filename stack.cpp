#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack {
    Node* head;

public:
    Stack() { this->head = nullptr; }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int new_data) {
        Node* new_node = new Node(new_data);
        if (!new_node) {
            cout << "\nStack Overflow" << endl;
        }
        new_node->next = head;
        head = new_node;
    }

    void pop() {
        if (this->isEmpty()) {
            cout << "\nStack Underflow" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int peek() {
        if (!isEmpty())
            return head->data;
        else {
            cout << "\nStack is empty" << endl;
            return -1; // Using -1 to indicate stack is empty
        }
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Stack st;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout << "Top element is " << st.peek() << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
