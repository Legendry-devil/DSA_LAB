#include<iostream>
using namespace std;

struct Tree
{
    int data;
    Tree* left;
    Tree* right;
};

class Binary_Search_Tree
{
    private:
        Tree* root;

        Tree* insert(Tree* Node, int value)
        {
            if(Node==nullptr)
            {
                Tree* newnode = new Tree;
                newnode->data = value;
                newnode->left = nullptr;
                newnode->right = nullptr;
                root = newnode;
                return newnode;
            }
            if(value>Node->data)
            {
                Node->right = insert(Node->right,value);
            }
            else
            {
                Node->left = insert(Node->left, value);
            }
            return Node;
        }

        void preorder(Tree* Node)
        {
            if(Node==nullptr)
            {
                return;
            }
            cout << Node->data << " ";
            preorder(Node->left);
            preorder(Node->right);
            return;
        }

        void postorder(Tree* Node)
        {
            if(Node==nullptr)
            {
                return;
            }
            postorder(Node->left);
            postorder(Node->right);
            cout << Node->data << " ";
            return;
        }

        void inorder(Tree* Node)
        {
            if(Node==nullptr)
            {
                return;
            }
            inorder(Node->left);
            cout << Node->data << " ";
            inorder(Node->right);
            return;
        }

        void DestroyTree(Tree* temp) 
        {
            if (temp == nullptr) 
            {
                return;
            }
            DestroyTree(temp->left);
            DestroyTree(temp->right);
            cout << "Deleting node: " << temp->data << "\n";
            delete temp;
        }

        Tree* search(Tree* Node, int value)
        {
            if(Node==nullptr || Node->data==value)
            {
                return Node;
            }
            if (Node->data > value)
            {
                return search(Node->right,value);
            }
            else 
            {
                return search(Node->left,value);
            }
        }

    public:
        Binary_Search_Tree()
        {
            root=nullptr;
        }

        ~Binary_Search_Tree() 
        {
            DestroyTree(root);
            cout << "Tree destroyed.\n";
        }

        void search()
        {
            int value;
            cout << "Enter the value to search: ";
            cin >> value;
            Tree* result = search(root,value);
            if(result==nullptr)
            {
                cout << "Value " << value << " not found in the tree.\n";
            }
            else 
            {
                cout << "Value " << value << " found in the tree.\n";
            }
        }

        void insert()
        {
            int value;
            cout << "Enter the value to be inserted: ";
            cin >> value;
            root = insert(root, value);
        }

        void display_preorder()
        {
            if(root==nullptr)
            {
                cout << "Tree is empty..\n";
                return;
            }
            cout << "Preorder: ";
            preorder(root);
            cout << "\n";
            return;
        }

        void display_postorder()
        {
            if(root==nullptr)
            {
                cout << "Tree is empty..\n";
                return;
            }
            cout << "Postorder: ";
            postorder(root);
            cout << "\n";
            return;
        }

        void display_inorder()
        {
            if(root==nullptr)
            {
                cout << "Tree is empty..\n";
                return;
            }
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
            return;
        }



};

int main()
{
    Binary_Search_Tree T;
    int choice;
    do
    {
        cout << "Choose your choice: \n";
        cout << "\t\t\t-----------------------\n";
        cout << "\t\t\t         MENU\n";
        cout << "\t\t\t-----------------------\n";
        cout << "\t\t\t1.Insert\n";
        cout << "\t\t\t2.Preorder\n";
        cout << "\t\t\t3.Postorder\n";
        cout << "\t\t\t4.Inorder\n";
        cout << "\t\t\t5.Search\n";
        cout << "\t\t\t6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "You choose to insert an element.\n";
            T.insert();
            break;

        case 2:
            cout << "You choose to display Preorder.\n";
            T.display_preorder();
            break;

        case 3:
            cout << "You choose to display Postorder.\n";
            T.display_postorder();
            break;

        case 4:
            cout << "You choose to display Inorder.\n";
            T.display_inorder();
            break;
            
        case 5:
            cout << "You choose to Search an element.\n";
            T.search();
            break;
        
        case 6:
            cout << "You choose to exit your code: \n";
            cout << "Exiting....\n";
            break;
        
        default:
            cout << "Invalid choice please try again....\n";
            break;
        }
    } while (choice!=6);
    return 0;
}