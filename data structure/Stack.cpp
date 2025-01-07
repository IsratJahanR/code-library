#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>mystack;
    int s=mystack.size();
    cout<<s<<endl;
    mystack.push(1);
    mystack.push(3);
    mystack.push(5);
    mystack.pop();
    s=mystack.size();
    cout<<s<<endl;
    while(!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout<<endl;
}
