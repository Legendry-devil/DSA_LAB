#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;

    Node* createNode(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    void insert(Node*& current) {
        if (current == nullptr) {
            char value;
            cout << "Enter character to insert: ";
            cin >> value;
            current = createNode(value);
            cout << "'" << value << "' inserted.\n";
            return;
        }

        char direction;
        cout << "At node '" << current->data << "'. Insert Left (L) or Right (R)? ";
        cin >> direction;

        if (direction == 'L' || direction == 'l')
            insert(current->left);
        else if (direction == 'R' || direction == 'r')
            insert(current->right);
        else
            cout << "Invalid direction.\n";
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    bool search(Node* node, char key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        return search(node->left, key) || search(node->right, key);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert() {
        insert(root);
    }

    void displayPreorder() {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << "\n";
    }

    void displayInorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << "\n";
    }

    void displayPostorder() {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << "\n";
    }

    void searchElement(char key) {
        if (search(root, key))
            cout << "Element '" << key << "' found in the tree.\n";
        else
            cout << "Element '" << key << "' not found in the tree.\n";
    }
};

int main() {
    BinaryTree tree;
    int choice;
    char key;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert\n";
        cout << "2. Preorder\n";
        cout << "3. Inorder\n";
        cout << "4. Postorder\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tree.insert();
            break;
        case 2:
            tree.displayPreorder();
            break;
        case 3:
            tree.displayInorder();
            break;
        case 4:
            tree.displayPostorder();
            break;
        case 5:
            cout << "Enter character to search: ";
            cin >> key;
            tree.searchElement(key);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
