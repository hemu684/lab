#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        head->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

int findDistance(Node* head, int val1, int val2) {
    if (!head) return -1;

    Node* temp = head;
    int index1 = -1, index2 = -1, index = 0, n = 0;
    
    do {
        if (temp->data == val1) index1 = index;
        if (temp->data == val2) index2 = index;
        temp = temp->next;
        index++;
    } while (temp != head);
    
    n = index; 

    if (index1 == -1 || index2 == -1) {
        cout << "One or both elements not found in the list.\n";
        return -1;
    }

    
    int cw_distance = (index2 - index1 + n) % n;
    int ccw_distance = (index1 - index2 + n) % n;

    return min(cw_distance, ccw_distance);
}


void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    //cout << "(back to head)\n";
}

// Main function
int main() {
    Node* head = nullptr;
    int n, val, val1, val2;
    
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    printList(head);

    cout << "Enter the two elements to find distance: ";
    cin >> val1 >> val2;

    int distance = findDistance(head, val1, val2);
    
    if (distance != -1) {
        cout << "Minimum distance between " << val1 << " and " << val2 << " is: " << distance << endl;
    }

    return 0;
}
