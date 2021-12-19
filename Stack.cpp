#include<iostream>
#define max 5
using namespace std;
class Stack
{
    private:
    int top;
    int arr[max];
    public:
    Stack()
    {
        top=-1;
    }
    
    void push();
    void pop();
    void display();
    bool isfull();
    void change();
    void sort();

};
void Stack::change()
{
    int pos, value;
    cout<<"enter position\n";
    cin>>pos;
    cout<<"enter value\n";
    cin>>value;
    arr[pos-1]=value;
}
bool Stack::isfull()
{
    return top==max-1;
}
void Stack::push()
{
    if (isfull())
    {
        cout<<"stack is overflow\n";
    }
    else
    {
        int n;
        cout<<"enter value\n";
        cin>>n;
        top++;
        arr[top]=n;
    }
}
void Stack::display()
{
    if (top==-1)
    {
        cout<<"stack is empty\n";
    }
    else
    {
        cout<<"Elementes are\n";
        for (int i = top; i>=0; i--)
        {
        cout<<arr[i]<<endl;
        }
    cout<<"top = "<<top<<endl;
    } 
}
void Stack::pop()
{ 
    if (top==-1)
    {
        cout<<"stack is empty\n";
    }
    else
    {
        int value;
        value=arr[top];
        top--;
        cout<<"deleted element = "<<value;
        cout<<endl;
    }  
}
void Stack::sort()
{
    for (int i = 0; i < top - 1; i++)
    {
        for (int j = i + 1; j < top; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main()
{
    Stack s;
    int ch;
    while (1)
    {
        cout<<"enter opereation\n";
        cout<<"1 : Push\n2 : Display\n3 : pop\n4 : change\n5 : sort\n6 : Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.display();
            break;
        case 3:
            s.pop();
            break;
        case 4:
            s.change();
            break;
        case 5:
            s.sort();
            break;
        case 6:
            return 0;
        }
    }
    
    return 0;
}