#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>q;
    q.push(5);
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(3);
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
}

