#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}


void insert(int key) {
    int index = hashFunction(key);

    int i = 0;

    while (hashTable[(index + i*i) % SIZE] != -1 && hashTable[(index + i*i) % SIZE] != -2) {
        i++;
        if (i == SIZE) {
            cout << "Hash table is full!\n";
            return;
        }
    }
    hashTable[(index + i*i) % SIZE] = key;
}

void search(int key) {
    int index = hashFunction(key);

    int i = 0;

    while (hashTable[(index + i*i) % SIZE] != -1) {
        if (hashTable[(index + i*i) % SIZE] == key) {
            cout << "Key found at index " << (index + i*i) % SIZE << endl;
            return;
        }
        i++;
        if (i == SIZE) break;
    }
    cout << "Key not found.\n";
}

void deleteKey(int key) {
    int index = hashFunction(key);

    int i = 0;

    while (hashTable[(index + i*i) % SIZE] != -1) {
        if (hashTable[(index + i*i) % SIZE] == key) {
            hashTable[(index + i*i) % SIZE] = -2;
            cout << "Key deleted.\n";
            return;
        }
        i++;
        if (i == SIZE) break;
    }
    cout << "Key not found to delete.\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "]: ";
        if (hashTable[i] == -1)
            cout << "Empty";
        else if (hashTable[i] == -2)
            cout << "Deleted";
        else
            cout << hashTable[i];
        cout << endl;
    }
}

int main() {
    init();
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter key to insert: "; cin >> key; insert(key); break;
            case 2: cout << "Enter key to delete: "; cin >> key; deleteKey(key); break;
            case 3: cout << "Enter key to search: "; cin >> key; search(key); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
