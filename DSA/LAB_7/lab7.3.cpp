/*program to implement Queue ADT using an integer linked list using the following operations
1.Enqueue
2.Dequeue
3.Peek
4.Exit*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    // Function to enqueue an element
    void enqueue(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;  
            rear = newNode;        
        }
        cout << "Successfully enqueued: " << value << endl;
    }

    // Function to dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Successfully dequeued: " << front->data << endl;
        front = front->next; 

        if (front == nullptr) { 
            rear = nullptr;
        }

        delete temp; 
    }

    // Function to peek at the front element
    void peek() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty! Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Function to display the queue elements
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function for menu-driven execution
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations using Linked List:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
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
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
