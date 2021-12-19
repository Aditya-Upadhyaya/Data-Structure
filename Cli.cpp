#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class CList
{
    node *last;

public:
    int count;
    CList()
    {
        last = NULL;
    }
    void create();
    void display();
    void insertstart();
    void insertlast();
    void insertposition();
    void deletestart();
    void delelast();
    void deleafter();
    int counte();
};
int CList::counte()
{
    int count = 0;
    node *temp;
    if (last == NULL)
    {
        cout << "List is empty\n";
        return count;
    }
    else
    {
        temp = last->next;
        while (temp != last)
        {
            temp = temp->next;
            count++;
        }
        return count + 1;
    }
}
void CList::create()
{
    node *temp;
    temp = new node;
    int n;
    cout << "Enter an Element\n";
    cin >> n;
    temp->data = n;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void CList::display()
{
    int count = 0;
    node *temp;
    if (last == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        temp = last->next;
        cout << "\nElements are \n";
        while (temp != last)
        {
            cout << temp->data << "->";
            temp = temp->next;
            count++;
        }
        cout << temp->data << "->";
        cout << "\ncount = " << count + 1;
    }
}
void CList::insertstart()
{
    node *temp;
    temp = new node;
    int n;
    cout << "enter the element\n";
    cin >> n;
    temp->data = n;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
        return;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
}
void CList::insertlast()
{

    node *temp;
    temp = new node;
    int n;
    cout << "enter the element\n";
    cin >> n;
    temp->data = n;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
        return;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void CList::delelast()
{
    if (last == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        node *temp;
        temp = new node;
        node *cur = new node;
        node *pre = new node;
        temp = last;
        if (last->next == last)
        {
            cout << "Deleted node = " << temp->data;
            last = NULL;
            delete temp;
        }
        else
        {
            cur = last->next;
            while (cur->next != last)
            {
                cur = cur->next;
            }
            cur->next = last->next;
            cout << "deleted node = " << temp->data;
            last = cur;
            delete temp;
        }
    }
}
void CList::insertposition()
{
    node *pre = new node;
    node *cur = new node;
    node *temp = new node;
    int n, pos;
    cout << "enter position\n";
    cin >> pos;
    cout << "enter the element\n";
    cin >> n;
    int c;
    c = counte();
    temp->data = n;
    if (pos == 1)
    {
        temp->next = last->next;
        last->next = temp;
    }
    else if (pos > c)
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    else
    {
        cur = last->next;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = temp;
        temp->next = cur;
    }
}
void CList::deletestart()
{
    node *temp;
    temp = new node;
    if (last == NULL)
    {
        cout << "\nList is empty\n";
    }
    else
    {
        if (last->next == last)
        {
            cout << "Deleted Node=" << last->data;
            last = NULL;
        }
        else
        {
            temp = last->next;
            last->next = temp->next;
            cout << "Deleted Node=" << temp->data;
            delete temp;
        }
    }
}
void CList::deleafter()
{
    if (last == NULL)
    {
        cout << "\nList is empty\n";
    }
    else
    {
        node *temp;
        temp = new node;
        int n;
        node *cur = new node;
        int d;
        cout << "delete node after ";
        cin >> d;
        cur = last;
        do
        {
            if (cur->data==d)
            {
                temp=cur->next;
                if (cur->next==cur)
                {
                    last=NULL;
                }
                else
                {
                    cur->next=temp->next;
                    if (temp==last)
                    {
                        last=cur;
                    }
                    cout<<"Deleted node = "<<temp->data;
                    delete temp;
                }
                break;
            }
            cur=cur->next;
            
        } while (cur!=last);
    }
}
int main()
{
    CList l;
    int ch;
    while (1)
    {
        cout << "\n1 : Create\n2 :  Display\n3 : insert at start\n4 : insert at last\n5 : insert at position\n12 : counte\n6 : delete at start\n7 : delete at last\n8 : delete after\n11 : Exit\n";
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
        case 12:
            l.counte();
            int c;
            c = l.counte();
            cout << "Count = " << c;
            break;
        case 6:
            l.deletestart();
            break;
        case 7:
            l.delelast();
            break;
        case 8:
            l.deleafter();
            break;
        case 11:
            return 0;
        }
    }

    return 0;
}