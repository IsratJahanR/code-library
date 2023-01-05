#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p[]={10,5,1,10,2,10};
    int n=6;
    int m[n][n],key[n][n];
    int i=1,j=1,k=1;
    while(k<n)
    {
        if(i==j)m[i][j]=0;
        else
        {

           int ans=m[i+1][j]+p[i-1]*p[i]*p[j];
           key[i][j]=1;
           for(int l=i;l<j;l++)
           {
               int temp=m[i][l]+m[l+1][j]+p[i-1]*p[l]*p[j];
               if(temp<ans)
               {
                   ans =temp;
                   key[i][j]=l;
               }
           }
           m[i][j]=ans;
        }
        i++;
        j++;
        if(j==n)
        {
            k++;
            i=1;
            j=k;

        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)cout<<m[i][j]<<" ";
        cout<<endl;
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)cout<<key[i][j]<<" ";
        cout<<endl;
    }

}
