#include <iostream>
using namespace std;
#define size 5
class CQueue
{
    int front, rare, arr[size];
    int count;

public:
    CQueue()
    {
        front = -1;
        rare = -1;
        count = 0;
    }
    void Enqueue();
    void display();
    void dequeue();
};
void CQueue::Enqueue()
{
    if ((front == 0 && rare == size - 1) || (((rare + 1) % size)==front))
    {
        cout << "Oveflow\n";
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        int value;
        cout << "Enter value\n";
        cin >> value;
        rare = (rare + 1) % size;
        arr[rare] = value;
        count++;
        cout << endl;
    }
}
void CQueue::dequeue()
{
    if (front == -1 && rare == -1)
    {
        cout << "Underflow\n";
    }
    else
    {
        int element;
        element = arr[front];
        if (front == rare)
        {
            front = rare = -1;
        }
        else
        {
            front = (front + 1) % size;
            count--;
        }
        cout << "Deleted Element =" << element << endl;
        ;
    }
}
void CQueue::display()
{
    if (front == -1 && rare == -1)
    {
        cout << "Underflow\n";
    }
    else
    {
        if (front <= rare)
        {
            for (int i = front; i <= rare; i++)
            {
                cout << arr[i] << "  ";
            }
            cout<<endl;
            cout<<"count = "<<count<<endl;;
            cout<<"Rare = "<<rare<<endl;
            cout<<"Front = "<<front<<endl;
        }
        else
        {
            int i = front;
            while (i < size)
            {
                cout << arr[i] << "  ";
                i++;
            }
            i = 0;
            while (i <= rare)
            {
                cout << arr[i] << "  ";
                i++;
            }
            cout<<endl;
            cout<<"count = "<<count<<endl;;
            cout<<"Rare = "<<rare<<endl;
            cout<<"Front = "<<front<<endl;
        }
    }
}
int main()
{
    CQueue q;
    int ch;
    while (1)
    {
        cout << "enter operation\n";
        cout << "1 : Enqueue\n2 : Delete\n3 : Display\n4 : exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.Enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            return 0;
        }
    }

    return 0;
}