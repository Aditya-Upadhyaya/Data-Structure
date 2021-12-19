#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
struct node *tree = NULL;
class BTree
{
    int count;

public:
    node *create(node *, int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    BTree()
    {
        int count = 1;
    }
};
struct node *BTree::create(node *tree, int d)
{
    if (tree == NULL)
    {
        tree = new (struct node);
        tree->left = tree->right = NULL;
        tree->data = d;
        count++;
    }
    else if (count % 2 == 0)
        tree->left = create(tree->left, d);
    else
        tree->right = create(tree->right, d);

    return (tree);
}
void BTree::inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        cout << endl
             << tree->data;
        inorder(tree->right);
    }
}
void BTree::preorder(node *tree)
{
    if (tree != NULL)
    {
        cout << endl
             << tree->data;
        preorder(tree->left);
        preorder(tree->right);
    }
}
void BTree::postorder(node *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout << endl
             << tree->data;
    }
}
int main()
{
    BTree l;
    int ch;
    while (1)
    {
        cout << "\n1 : Create\n2 :  Inorder\n3 : preorder\n4 : postorder\n5 : Exit\n";
        cout << "Enter Operation\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int d;
            cout << "enter value" << endl;
            cin >> d;
            tree = l.create(tree, d);
            break;
        case 2:
            l.inorder(tree);
            break;
        case 3:
            l.preorder(tree);
            break;
        case 4:
            l.postorder(tree);
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}