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

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        this->front = this->rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int new_data) {
        Node* new_node = new Node(new_data);
        if (rear == nullptr) {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peekFront() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "\nQueue is empty" << endl;
            return -1; // Using -1 to indicate queue is empty
        }
    }
    
    int peekRear() {
        if (!isEmpty()) {
            return rear->data;
        } else {
            cout << "\nQueue is empty" << endl;
            return -1; // Using -1 to indicate queue is empty
        }
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek Front\n";
    cout << "4. Peek Rear\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Queue q;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element is " << q.peekFront() << endl;
                break;
            case 4:
                cout << "Rear element is " << q.peekRear() << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
