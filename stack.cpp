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

    bool checkEmpty() {
        return head == nullptr;
    }

    void push(int new_data) {
        Node* new_node = new Node(new_data);
        if (!new_node) {
            cout << "\nStack Overflow" << endl;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    void pop() {
        if (this->isEmpty()) {
            cout << "\nStack Underflow" << endl;
            return;
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

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Check if Empty\n";
    cout << "5. Get Size\n";
    cout << "6. Exit\n";
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
                if (st.checkEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;
            case 5:
                cout << "Stack size is " << st.size() << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
