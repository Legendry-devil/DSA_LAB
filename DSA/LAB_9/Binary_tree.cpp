#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

class Tree
{
private:
    Node* root;

    void preorder(Node* temp)
    {
        if(temp != nullptr)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void inorder(Node* temp)
    {
        if(temp != nullptr)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    void postorder(Node* temp)
    {
        if(temp != nullptr)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

public:
    Tree()
    {
        root = nullptr;
    }

    void constructExpressionTree(const string& postfix)
    {
        stack<Node*> st;
        for(char c : postfix)
        {
            if(isalnum(c))
            {
                Node* newNode = new Node();
                newNode->data = c;
                newNode->left = nullptr;
                newNode->right = nullptr;
                st.push(newNode);
            }
            else
            {
                Node* rightChild = st.top();
                st.pop();
                Node* leftChild = st.top();
                st.pop();
                Node* newNode = new Node();
                newNode->data = c;
                newNode->left = leftChild;
                newNode->right = rightChild;
                st.push(newNode);
            }
        }
        root = st.top();
        st.pop();
    }

    void display_pre()
    {
        if(root == nullptr)
            cout << "Tree is empty......\n";
        else
        {
            preorder(root);
            cout << "\n";
        }
    }

    void display_in()
    {
        if(root == nullptr)
            cout << "Tree is empty......\n";
        else
        {
            inorder(root);
            cout << "\n";
        }
    }

    void display_post()
    {
        if(root == nullptr)
            cout << "Tree is empty......\n";
        else
        {
            postorder(root);
            cout << "\n";
        }
    }
};

int main()
{
    Tree tree;
    int choice;
    string postfix;
    do
    {
        cout << "\t\tChoose your choice: \n";
        cout << "\t\t\t---------------------\n";
        cout << "\t\t\t MENU\n";
        cout << "\t\t\t---------------------\n";
        cout << "\t\t\t1. Postfix Expression\n";
        cout << "\t\t\t2. Construct Expression Tree\n";
        cout << "\t\t\t3. Preorder\n";
        cout << "\t\t\t4. Inorder\n";
        cout << "\t\t\t5. Postorder\n";
        cout << "\t\t\t6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter a valid postfix expression: ";
            cin >> postfix;
            break;
        case 2:
            if(postfix.empty())
                cout << "No postfix expression found. Please enter it first.\n";
            else
            {
                tree.constructExpressionTree(postfix);
                cout << "Expression Tree Constructed.\n";
            }
            break;
        case 3:
            tree.display_pre();
            break;
        case 4:
            tree.display_in();
            break;
        case 5:
            tree.display_post();
            break;
        case 6:
            cout << "Exiting......\n";
            break;
        default:
            cout << "Invalid choice.......\nPlease try again.\n";
            break;
        }
    }
    while(choice != 6);
    return 0;
}
