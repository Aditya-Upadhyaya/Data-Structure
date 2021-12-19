#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class List
{
    node *head, *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void create();
    void display();
    void insertstart();
    void insertlast();
    void insertposition();
    void deletestart();
    void delelast();
    void deleparticular();
    void sort();
    void search();
};
void List::create()
{
    node *temp;
    temp = new node;
    int n;
    cout << "Enter an Element\n";
    cin >> n;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void List::display()
{
    int count=0;
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "List is empty\n";
    }
    cout << "\nElements are \n";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        count++;
    }
    cout << "NULL";
    cout<<"\ncount = "<<count;
}
void List::insertstart()
{
    node *temp;
    temp = new node;
    int n;
    cout << "enter the element\n";
    cin >> n;
    temp->data = n;
    temp->next = head;
    head = temp;
}
void List::insertlast()
{
    node *temp;
    temp = new node;
    int n;
    cout << "enter the element\n";
    cin >> n;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void List::insertposition()
{
    node *pre = new node;
    node *cur = new node;
    node *temp = new node;
    int n, pos;
    cout << "enter position\n";
    cin >> pos;
    cout << "enter the element\n";
    cin >> n;
    cur = head;
    for (int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    temp->data = n;
    pre->next = temp;
    temp->next = cur;
}
void List::deletestart()
{
    if (head == NULL)
    {
        cout << "\nList is empty\n";
    }
    else
    {
        node *temp;
        temp = new node;
        temp = head;
        head = head->next;
        cout << "deleted node = " << temp->data;
        delete temp;
    }
}
void List::delelast()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        node *temp;
        temp = new node;
        node *cur = new node;
        node *pre = new node;
        cur = head;
        while (cur->next != NULL)
        {
            pre = cur;
            cur = cur->next;
        }
        tail = pre;
        pre->next = NULL;
        cout << "deleted node = " << cur->data;
        delete cur;
    }
}
void List::deleparticular()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        int pos;
        node *temp;
        temp = new node;
        node *cur = new node;
        node *pre = new node;
        cout << "enter postion\n";
        cin >> pos;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        cout << "deleted node =" << cur->data;
        delete cur;
    }
}
void List::sort()
{
    node *index = new node;
    node *cur = new node;
    cur = head;
    while (cur!=NULL)
    {
        int temp;
        index=cur->next;
        while (index!=NULL)
        {
            if (cur->data > index->data)
            {
                temp=cur->data;
                cur->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        cur=cur->next;
    } 
}
void List::search()
{
    int key, count=0;
    cout<<"enter key element\n";
    cin>>key;
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        if (temp->data==key)
        {
            cout<<"element found at \n";
            cout<<count;
            break;
        }  
        temp = temp->next;  
    }
}
int main()
{
    List l;
    int ch;
    while (1)
    {
        cout << "\n1 : Create\n2 :  Display\n3 : insert at start\n4 : insert at last\n5 : insert at position\n6 : delete at start\n7 : delete at last\n8 : delete at particular\n9 : Sorting\n10 : Search\n11 : Exit\n";
        cout << "Enter Operation\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.insertstart();
            break;
        case 4:
            l.insertlast();
            break;
        case 5:
            l.insertposition();
            break;
        case 6:
            l.deletestart();
            break;
        case 7:
            l.delelast();
            break;
        case 8:
            l.deleparticular();
            break;
        case 9:
            l.sort();
            break;
        case 10:
            l.search();
            break;
        case 11:
            return 0;
        }
    }

    return 0;
}