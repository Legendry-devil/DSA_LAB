#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class ListADT {
private:
    Node* head;

    Node* gethead() {
        return head;
    }

public:
    ListADT() {
        head = nullptr;
    }

    // Insert in Ascending Order
    void insertAscending(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Merge two lists into a third list in Ascending Order
    void merge(ListADT& list1, ListADT& list2) {
        Node* p1 = list1.gethead();
        Node* p2 = list2.gethead();
        while (p1 != nullptr || p2 != nullptr) {
            if (p1 == nullptr) {
                insertAscending(p2->data);
                p2 = p2->next;
            } else if (p2 == nullptr) {
                insertAscending(p1->data);
                p1 = p1->next;
            } else if (p1->data < p2->data) {
                insertAscending(p1->data);
                p1 = p1->next;
            } else {
                insertAscending(p2->data);
                p2 = p2->next;
            }
        }
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif
