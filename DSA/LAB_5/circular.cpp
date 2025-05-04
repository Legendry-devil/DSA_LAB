#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insert_at_beginning(int value);
    void insert_at_end(int value);
    void insert_at_position(int value, int position);
    void delete_at_beginning();
    void delete_at_end();
    void delete_at_position(int position);
    bool search(int value);
    void display();
};

// Insert at beginning
void CircularLinkedList::insert_at_beginning(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    cout << "Inserted " << value << " at the beginning.\n";
}

// Insert at end
void CircularLinkedList::insert_at_end(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Insert at position
void CircularLinkedList::insert_at_position(int value, int position) {
    if (position == 1) {
        insert_at_beginning(value);
        return;
    }
    Node* temp = tail->next;
    for (int i = 1; temp != tail && i < position - 1; i++) 
        temp = temp->next;

    if (!temp || temp == tail) {
        cout << "Invalid position!\n";
        return;
    }

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
    cout << "Inserted " << value << " at position " << position << ".\n";
}

// Delete at beginning
void CircularLinkedList::delete_at_beginning() {
    if (!tail) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }
    Node* temp = tail->next;
    if (tail == tail->next) 
        tail = nullptr;
    else 
        tail->next = temp->next;
    
    cout << "Deleted " << temp->data << " from the beginning.\n";
    delete temp;
}

// Delete at end
void CircularLinkedList::delete_at_end() {
    if (!tail) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }
    Node* temp = tail->next;
    if (tail == tail->next) {
        cout << "Deleted " << tail->data << " from the end.\n";
        delete tail;
        tail = nullptr;
        return;
    }
    while (temp->next != tail) 
        temp = temp->next;
    
    temp->next = tail->next;
    cout << "Deleted " << tail->data << " from the end.\n";
    delete tail;
    tail = temp;
}

// Delete at position
void CircularLinkedList::delete_at_position(int position) {
    if (position == 1) {
        delete_at_beginning();
        return;
    }
    Node* temp = tail->next;
    Node* prev = nullptr;
    for (int i = 1; temp != tail && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp || temp == tail) {
        cout << "Invalid position!\n";
        return;
    }

    prev->next = temp->next;
    cout << "Deleted " << temp->data << " from position " << position << ".\n";
    delete temp;
}

// Search for a value
bool CircularLinkedList::search(int value) {
    if (!tail) {
        cout << "List is empty.\n";
        return false;
    }
    Node* temp = tail->next;
    do {
        if (temp->data == value) {
            cout << "Value " << value << " found in the list.\n";
            return true;
        }
        temp = temp->next;
    } while (temp != tail->next);
    
    cout << "Value " << value << " not found in the list.\n";
    return false;
}

// Display list
void CircularLinkedList::display() {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List: ";
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    CircularLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value to insert at beginning: ";
                cin >> value; 
                list.insert_at_beginning(value); 
                break;
            case 2: 
                cout << "Enter value to insert at end: ";
                cin >> value; 
                list.insert_at_end(value); 
                break;
            case 3: 
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insert_at_position(value, position); 
                break;
            case 4: 
                list.delete_at_beginning(); 
                break;
            case 5: 
                list.delete_at_end(); 
                break;
            case 6: 
                cout << "Enter position to delete: ";
                cin >> position;
                list.delete_at_position(position); 
                break;
            case 7: 
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value); 
                break;
            case 8: 
                list.display(); 
                break;
            case 9: 
                cout << "Exiting program...\n";
                return 0;
            default: 
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
}
