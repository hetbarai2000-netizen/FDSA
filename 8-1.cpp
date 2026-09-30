#include <iostream>
#include <queue>
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
Node* createTree()
{
    int x;
    cout << "Enter data (-1 for NULL): ";
    cin >> x;

    if(x == -1)
        return NULL;

    Node *root = new Node(x);

    cout << "Enter left child of " << x << endl;
    root->left = createTree();

    cout << "Enter right child of " << x << endl;
    root->right = createTree();

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

void preorder(Node *root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node *root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != NULL)
            q.push(temp->left);

        if(temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node *root;

    cout << "Create Binary Tree\n";
    root = createTree();

    int choice;

    do
    {
        cout << "\n\n----- MENU -----";
        cout << "\n1. Inorder";
        cout << "\n2. Preorder";
        cout << "\n3. Postorder";
        cout << "\n4. Level Order";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 2:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 3:
                cout << "Postorder: ";
                postorder(root);
                break;

            case 4:
                cout << "Level Order: ";
                levelorder(root);
                break;

            case 5:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    }while(choice != 5);

    return 0;
}