#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
private:
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted " << element << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int element = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        do {
            cout << items[i] << " ";
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);

        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                cq.enqueue(element);
                break;
            case 2:
                element = cq.dequeue();
                if (element != -1) {
                    std::cout << "Removed element: " << element << "\n";
                }
                break;
            case 3:
                cq.display();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
