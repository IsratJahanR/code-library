
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
               // int ans =m[i+1][j]+(p[i-1])*(p[i])*(p[j]);
               int ans=INT_MAX;
                key[i][j]=i;
                for(int l=i+1;l<j;l++)
                {

                    int x = m[i][l]+m[l+1][j]+p[i-1]*p[l]*p[j];
                    if(x<ans)
                    {
                        ans=x;
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
            j=k;
            i=1;

        }


    }
    for(i=1;i<n;i++)
    {
       for(j=i;j<n;j++)cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)cout<<key[i][j]<<" ";
        cout<<endl;
    }





}
