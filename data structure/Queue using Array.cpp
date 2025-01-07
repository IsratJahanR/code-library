#include<bits/stdc++.h>
using namespace std;
class Queue
{
   int front = - 1, rear = - 1;
    int a[10];
    public:

        bool isEmpty()
        {
            if(front==-1)return true;
            else return false;
        }
        bool isFull()
        {
            if(rear==9)return true;
            else return false;
        }
        void EnQue(int val)
        {
            if(isFull())cout<<"Queue OVERFLOW"<<endl;

            else
            {
                if(front==-1)front=0;
                rear++;

                a[rear]=val;
            }
        }
        void DeQue()
        {
            if(front==-1 || rear<front)
            {
                cout<<"STACK UNDERFLOW"<<endl;
                return;
            }
            a[front]=0;
            front++;

        }
        void Display()
        {
            if(isEmpty()){cout<<"Queue is Empty"<<endl; return;}
            for (int i = front; i <= rear; i++)cout<<a[i]<<" ";

            cout<<endl;
        }

};
int main()
{
    Queue q;
    q.EnQue(1);
    q.EnQue(2);
    q.EnQue(3);
    q.Display();
    q.DeQue();
    q.Display();
}
