#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;
list<int> hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}


void insert(int key) {
    int index = hashFunction(key);

    hashTable[index].push_back(key);
}

void search(int key) {
    int index = hashFunction(key);

    for (int x : hashTable[index]) {
        if (x == key) {
            cout << "Key found in bucket " << index << endl;
            return;
        }
    }
    cout << "Key not found.\n";
}

void deleteKey(int key) {
    int index = hashFunction(key);

    hashTable[index].remove(key);
    cout << "Key deleted from bucket " << index << " (if it existed).\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "]: ";
        for (int key : hashTable[i]) {
            cout << key << " -> ";
        }
        cout << "NULL\n";
    }
}

int main() {
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter key to insert: "; cin >> key; insert(key); break;
            case 2: cout << "Enter key to delete: "; cin >> key; deleteKey(key); break;
            case 3: cout << "Enter key to search: "; cin >> key; search(key); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
