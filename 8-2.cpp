#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root, int x)
{
    if(root == NULL)
        return new Node(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}
void inorder(Node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, x, choice;

    do
    {
        cout << "\n----- MENU -----";
        cout << "\n1. Insert Book Code";
        cout << "\n2. Display Inorder";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "How many book codes? ";
                cin >> n;

                cout << "Enter book codes:\n";
                for(int i = 0; i < n; i++)
                {
                    cin >> x;
                    root = insert(root, x);
                }
                break;

            case 2:
                cout << "Inorder Sequence: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while(choice != 3);

    return 0;
}