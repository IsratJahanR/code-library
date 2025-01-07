#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int i=0;
    int s,e;
    int ans =0;
    while(i<n)
    {
        s=i;
        while(s<n && a[s]==0)s++;
        e=s;
        int sn=-1,en=-1;
        int cnt_neg=0;
        while(e<n && a[e]!=0)
        {
            if(a[e]<0)
            {
                if(sn==-1)sn=e;
                en=e;
                cnt_neg++;
            }
            e++;

        }
        e--;
        //cout<<s<<" "<<e<<endl;
        if(cnt_neg%2==0)ans = max(ans,e-s+1);
        else{
            ans = max(ans,max(en-s,e-sn));
        }
        i=e+1;


    }
    cout<<ans<<endl;



}
