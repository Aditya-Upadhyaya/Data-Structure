#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL; //creating an empty tree
class BST
{
public:
    node *create(node *, int);
    node *Delete(node *, int);
    void search(node *, int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    node *FindMin(node *);
};
struct node *BST::FindMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct node *BST::create(struct node *root, int d)
{
    if (root == NULL)
    {
        root = new (struct node);
        root->left = root->right = NULL;
        root->data = d;
    }
    else if (d < root->data)
        root->left = create(root->left, d);
    else if (d > root->data)
        root->right = create(root->right, d);
    else if (d == root->data)
    {
        cout << "duplicate\n";
    }

    return (root);
}
void BST::search(node *root, int d)
{
    if (root == NULL)
        cout << "empty tree\n";
    else if (d == root->data)
        cout << endl
             << "Number is" << d;
    else if (d < root->data)
        search(root->left, d);
    else
        search(root->right, d);
}
void BST::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << endl
             << root->data;
        inorder(root->right);
    }
}
void BST::preorder(node *root)
{
    if (root != NULL)
    {
        cout << endl
             << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void BST::postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << endl
             << root->data;
    }
}
struct node *BST::Delete(struct node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    // Wohoo... I found you, Get ready to be deleted
    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {

            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;

            delete temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;

            delete temp;
        }
        // case 3: 2 children
        else
        {
            struct node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            cout << "Deleted = " << temp->data;
        }
    }
    return root;
}
int main()
{
    BST l;
    int ch;
    while (1)
    {
        cout << "\n1 : Create\n2 :  Inorder\n3 : preorder\n4 : postorder\n5 : delete\n6 : search\n7 : Exit\n";
        cout << "Enter Operation\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int d;
            cout << "enter value" << endl;
            cin >> d;
            root = l.create(root, d);
            break;
        case 2:
            l.inorder(root);
            break;
        case 3:
            l.preorder(root);
            break;
        case 4:
            l.postorder(root);
            break;
        case 6:
            int c;
            cout << "enter value\n";
            cin >> c;
            l.search(root, c);
            break;
        case 5:
            int r;
            cout << "enter element to be deleted\n";
            cin >> r;
            root = l.Delete(root, r);
            break;
        case 7:
            return 0;
        }
    }

    return 0;
}