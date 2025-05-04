#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct Queue
{
    Node* treenode;
    Queue* next;
};

class Queuenode
{
    private:
        Queue* front;
        Queue* rear;

    public:
        Queuenode()
        {
            front=nullptr;
            rear=nullptr;
        }

        void enqueue(Node* value)
        {
            Queue* newQueue = new Queue();
            newQueue->treenode=value;
            newQueue->next=nullptr;
            if(front==nullptr)
            {
                front=newQueue;
                rear=newQueue;
            }
            else
            {
                rear->next=newQueue;
                rear=newQueue;
            }
        }

        Node* dequeue()
        {
            if(front==nullptr)
            {
                return nullptr;
            }

            Queue* temp=front;
            Node* delvalue=front->treenode;
            front=front->next;
            delete temp;
            if(front==nullptr)
            {
                rear=nullptr;
            }
            return delvalue;
        }

        bool empty()
        {
            return front==nullptr;
        }
};

class Tree
{
    private:
        
        Node* root;
    
    public:
        Queuenode Q;

        Tree()
        {
            root=nullptr;
        }

        void Insert()
        {
            int value;
            cout << "Enter the value to be inserted: ";
            cin >> value;
            Node* newNode = new Node();
            newNode->data=value;
            newNode->left=nullptr;
            newNode->right=nullptr;
            if(root==nullptr)
            {
                root=newNode;
                return;
            }
            Q.enqueue(root);
            while (!Q.empty())  
            {
                Node* temp=Q.dequeue();
                if(temp->left==nullptr)
                {
                    temp->left=newNode;
                    return;
                }
                else
                {
                    Q.enqueue(temp->left);
                }
                if (temp->right==nullptr)
                {
                    temp->right=newNode;
                    return;
                }
                else
                {
                    Q.enqueue(temp->right);
                }
            }
        }

        void preorder(Node* root)
        {
            if(root != nullptr)
            {
                cout << root->data << " ";
                preorder(root->left);
                preorder(root->right);
            }
        }

        void inorder(Node* root)
        {
            if(root != nullptr)
            {
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);
            }
        }

        void postorder(Node* root)
        {
            if(root != nullptr)
            {
                postorder(root->left);
                postorder(root->right);
                cout << root->data << " ";
            }
        } 

        void display_post()
        {
            if(root==nullptr)
            {
                cout << "Tree is empty......\n";
            }
            else
            {
                postorder(root);
            }
        }

        void display_pre()
        {
            if(root==nullptr)
            {
                cout << "Tree is empty......\n";
            }
            else
            {
                preorder(root);
            }
        }

        void display_in()
        {
            if(root==nullptr)
            {
                cout << "Tree is empty......\n";
            }
            else
            {
                inorder(root);
            }
        }
};

int main()
{
    Tree tree;
    int choice;
    do{
        cout << "\t\tChoose your choice: \n";
        cout << "\t\t\t---------------------\n";
        cout << "\t\t\t MENU\n";
        cout << "\t\t\t---------------------\n";
        cout << "\t\t\t1.Insert\n\t\t\t2.Preorder\n\t\t\t3.Inorder\n\t\t\t4.Postorder\n\t\t\t5.Search\n\t\t\t6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                tree.Insert();
                break;
            case 2:
                tree.display_pre();
                break;
            case 3:
                tree.display_in();
                break;
            case 4:
                tree.display_post();
                break;
            case 5:
                //tree.search();
                break;
            case 6:
                cout << "Exiting......\n";
                break;
            default:
                cout << "Invalid choice.......\nPlease try again.\n";
                break;
        }
    } while(choice != 6);
    return 0;
}




