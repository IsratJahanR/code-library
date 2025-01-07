#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch)
{
    if(ch>='0' && ch<='9'){
        return true;
    }
    return false;
}
bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
        return true;
    }
    return false;
}
float Operation(float a,float b,char ch)
{
    if(ch=='+') return b+a;
    else if(ch=='-') return b-a;
    else if(ch=='*') return b*a;
    else if(ch=='/') return b/a;
    else if(ch=='^') return pow(b,a);
    else
      return INT_MIN;
}
float evaluatePostfix(string exp)
{
    stack<float>s;
    for(int i=0;exp[i]!='\0';i++){
        if(isOperand(exp[i])){
            float a=exp[i]-48;
            s.push(a);
        }
        else if(isOperator(exp[i])){
            float val1=s.top();
            s.pop();
            float val2=s.top();
            s.pop();
            s.push(Operation(val1,val2,exp[i]));
        }
    }
    return s.top();
}

int main()
{
    string exp;
    cout<<"enter your postfix expression: (ex:23*5/)\n" ;
    cin>>exp;
    float res=evaluatePostfix(exp);
    cout<<"The result is: "<<res<<endl;

    return 0;
}
