#include<iostream>
using namespace std;

bool CheckUnique(string s)
{
    int bits=0;
    for(int i=0;i<s.size();i++)
    {
        int val = s[i]-'a';
        if(bits & ( 1<<val ) )return false;
        bits = bits|(1<<val);
    }
    return true;
}

int main()
{
    string  s = "abcdea";
    if(CheckUnique(s))cout<<"All characters are unique."<<endl;
    else cout<<"There have duplicate character."<<endl;
}
