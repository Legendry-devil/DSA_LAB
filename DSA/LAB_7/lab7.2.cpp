/*program to implement Circular Queue ADT using an integer array of size 5 with following operations
1.Enqueue
2.Dequeue
3.Peek
4.Exit*/

#include<iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
private:
    int arr[SIZE]; 
    int front, rear; 

public:
    CircularQueue() : front(-1), rear(-1) {} // Constructor to initialize queue

    bool isFull() const {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() const {
        return front == -1;
    }

    // Function to insert an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Error: Queue is full! Cannot enqueue." << endl;
            return;
        }
        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % SIZE; 
        arr[rear] = value;
        cout << "Successfully enqueued: " << value << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Successfully dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; 
        }
    }

    // Function to view the front element of the queue
    void peek() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty! Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Function to display the queue elements
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;
    
    do {
        
        cout << "\nCircular Queue Operations:";
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