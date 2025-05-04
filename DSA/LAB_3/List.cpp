#include <iostream>
using namespace std;

const int MAX = 5;

class ListADT {
private:
    int arr[MAX];
    int size;

public:
    ListADT() {
        size = 0;
    }

    void insertBeginning(int val) {
        if (size == MAX) {
            cout << "List is full!\n";
            return;
        }
        for (int i = size; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = val;
        size++;
    }

    void insertEnd(int val) {
        if (size == MAX) {
            cout << "List is full!\n";
            return;
        }
        arr[size++] = val;
    }

    void insertPosition(int pos, int val) {
        if (size == MAX || pos < 1 || pos > size + 1) {
            cout << "Invalid position or list full!\n";
            return;
        }
        for (int i = size; i >= pos; i--)
            arr[i] = arr[i - 1];
        arr[pos - 1] = val;
        size++;
    }

    void deleteBeginning() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    void deleteEnd() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        size--;
    }

    void deletePosition(int pos) {
        if (size == 0 || pos < 1 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = pos - 1; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    void search(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                cout << "Element found at position " << (i + 1) << "\n";
                return;
            }
        }
        cout << "Element not found!\n";
    }

    void display() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        cout << "List: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    // Rotate using O(1) space (reverse method)
    void rotate(int k) {
        if (size == 0) return;
        k = k % size;

        reverse(0, size - 1);
        reverse(0, k - 1);
        reverse(k, size - 1);
    }

    // Helper reverse function
    void reverse(int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    // Alternate rotation using temp array (O(n) space)
    void rotateTemp(int k) {
        if (size == 0) return;
        k = k % size;
        int temp[MAX];
        for (int i = 0; i < size; i++)
            temp[(i + k) % size] = arr[i];
        for (int i = 0; i < size; i++)
            arr[i] = temp[i];
    }

    // Alternate rotation one by one (O(n*k) time)
    void rotateBrute(int k) {
        if (size == 0) return;
        k = k % size;
        while (k--) {
            int last = arr[size - 1];
            for (int i = size - 1; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = last;
        }
    }
};

int main() {
    ListADT list;
    int choice, val, pos, k;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Rotate\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertEnd(val);
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                list.insertPosition(pos, val);
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
                cin >> val;
                list.search(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Enter k: ";
                cin >> k;
                list.rotate(k); // Use reverse method
                // list.rotateTemp(k); // Uncomment to use temp array
                // list.rotateBrute(k); // Uncomment for brute force
                cout << "Array rotated.\n";
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
