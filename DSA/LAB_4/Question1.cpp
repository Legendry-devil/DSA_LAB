#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class ListADT
{
private:
    Node* head;
    
public:
    ListADT()
    {
        head = nullptr;
    }

    // Insert at the beginning
    void insertBeginning(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a given position
    void insertPosition(int value, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(value);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from the end
    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from a given position
    void deletePosition(int pos)
    {
        if (pos < 0 || head == nullptr)
        {
            cout << "Invalid position or List is empty\n";
            return;
        }

        if (pos == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search for an element
    void search(int value)
    {
        Node* temp = head;
        int position = 0;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << "Element " << value << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element not found\n";
    }

    // Display the list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list in reverse order (without changing the structure)
    void displayReverse()
    {
        displayReverseHelper(head);
        cout << endl;
    }

    // Helper function to display reverse using recursion
    void displayReverseHelper(Node* node)
    {
        if (node == nullptr)
            return;

        displayReverseHelper(node->next);
        cout << node->data << " ";
    }

    // Reverse the entire linked list
    void reverseLink()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main()
{
    ListADT list;
    int choice, value, pos;

    while (true)
    {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse Link\n11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertPosition(value, pos);
            break;

        case 4:
            list.deleteBeginning();
            break;

        case 5:
            list.deleteEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deletePosition(pos);
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
            list.displayReverse();
            break;

        case 10:
            list.reverseLink();
            break;

        case 11:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
