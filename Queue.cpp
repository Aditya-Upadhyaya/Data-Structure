#include <iostream>
using namespace std;
#define max 5
class Queue
{
    int front, rare, arr[max];
    int count;

public:
    Queue()
    {
        front = -1;
        rare = -1;
        count = 0;
    }
    void Enqueue();
    void display();
    void dequeue();
};
void Queue::Enqueue()
{
    if (front == -1)
    {
        front++;
    }
    if (rare == max - 1)
    {
        cout << "Overflow\n";
    }
    else
    {
        int value;
        cout << "entre value\n";
        cin >> value;
        rare++;
        count++;
        arr[rare] = value;
    }
}
void Queue::dequeue()
{
    if (front == -1 && rare == -1)
    {
        cout << "Underflow\n";
    }
    else if (front > rare)
    {
        cout << "Underflow\n";
    }
    else
    {
        cout << "Deleted element = " << arr[front];
        arr[front]=NULL;
        front++;
        count--;
        cout << endl;
        
    }
}
void Queue::display()
{
    if (front == -1 && rare == -1)
    {
        cout << "Underflow\n";
    }
    else if (front > rare)
    {
        cout << "Underflow\n";
    }
    else
    {
        cout << "Elements are\n";
        for (int i = 0; i <= rare; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
        cout<<"count = "<<count<<endl;;
        cout<<"Rare = "<<rare<<endl;
        cout<<"Front = "<<front<<endl;
    }
}
int main()
{
    Queue q;
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