///Kadanes algorithm | Longest sum contiguous subarray

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    int tc=1;
    int k=t;
    while(t--)
    {


        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int mx=INT_MIN;
        int l=0,r=0;
        int l1=-1,r1=-1;
        int cur=0;
        for(int i=0;i<n;i++)
        {

            cur+=a[i];
            r=i;
            if(a[i]>cur)
            {
                cur=a[i];
                l=i;
                r=i;
            }
            if(cur>mx)
            {
                mx=cur;
                l1=l;
                r1=r;
            }

        }
        ///cout<<"Case "<<tc++<<":"<<endl;
        cout<<mx<<" "<<l1+1<<" "<<r1+1<<endl;
        //if(tc-1!=k)cout<<endl;
    }

}
