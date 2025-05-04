/*program to implement Queue ADT using an integer array of size 5 with following operations
1.Enqueue
2.Dequeue
3.Peek
4.Exit*/

#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
private:
    int arr[SIZE]; 
    int front, rear;  

public:
    // Constructor to initialize the queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    // Enqueue operation to add an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << ".\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation to remove an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Peek operation to get the front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
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

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
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
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
