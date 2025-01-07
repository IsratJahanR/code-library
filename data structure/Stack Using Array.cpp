#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int top=-1;
    int arr[10];
    public:

        bool isEmpty()
        {
            if(top==-1)return true;
            else return false;
        }
        bool isFull()
        {
            if(top==9)return true;
            else return false;
        }
        void push(int val)
        {
            if(isFull())cout<<"STACK OVERFLOW"<<endl;
            else
            {
                top++;
                arr[top]=val;
            }
        }
        void pop()
        {
            if(isEmpty())cout<<"STACK UNDERFLOW"<<endl;
            else
            {
                int topvalue = arr[top];
                arr[top]=0;
                top--;
            }
        }
        void Display()
        {
            cout<<"All Values in STACK are : ";
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};
int main()
{
    Stack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.Display();

    cout<<"Pop operation : ";
    obj.pop();
    obj.Display();

    if(obj.isEmpty())cout<<"STACK IS EMPTY"<<endl;
    else cout<<"STACK IS NOT EMPTY"<<endl;

    if(obj.isFull())cout<<"STACK IS FULL"<<endl;
    else cout<<"STACK IS NOT FULL"<<endl;


}
