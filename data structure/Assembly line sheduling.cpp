#include<bits/stdc++.h>
using namespace std;
#define nofl 2
#define nofs 5
void printDirection(int l[][nofs])
{

   int k;
   int i= nofs-1;
   if(l[0][i]>0)k=1;
   else k=2;
   int ans[nofs];

   while(i>=0)
   {

       ans[i]=l[k-1][i];

       k=ans[i];
       i--;
   }
   for(i=0;i<nofs;i++)
   {
       if(i<nofs-1)cout<<ans[i]<<"->";
       else cout<<ans[i];
   }

   //for(int i=0;i<nofs;i++)cout<<l[1][i]<<" ";
   cout<<endl;
}
int carAssembly(int a[][nofs],int t[][nofs],int e[],int x[])
{
   int s1[nofs+1],s2[nofs+1],l[nofl][nofs];
   s1[0]=e[0]+a[0][0];
   s2[0]=e[1]+a[1][0];
   for(int i=1;i<=nofs;i++)
   {
       if(i==nofs)
       {
         s1[i]=s1[i-1]+x[0];
         s2[i]=s2[i-1]+x[1];
         l[0][i-1]=1;
         l[1][i-1]=2;
         if(s2<s1)l[0][i-1]=0;
         else l[1][i-1]=0;
         break;
       }
       int x=a[0][i]+s1[i-1];
       int y=a[0][i]+s2[i-1]+t[1][i];
       if(x<y)l[0][i-1]=1;
       else l[0][i-1]=2;
       s1[i]=min(x,y);


       x=a[1][i]+s1[i-1]+t[0][i];
       y=a[1][i]+s2[i-1];
       if(x<y)l[1][i-1]=1;
       else l[1][i-1]=2;
       s2[i]=min(x,y);


   }
   printDirection(l);
   //for(int i=0;i<=nofs;i++)cout<<s1[i]<<" "<<s2[i]<<endl;
   //for(int i=0;i<nofs;i++)cout<<l[0][i]<<" "<<l[1][i]<<endl;
   return min(s1[nofs],s2[nofs]);
}
int main()
{
    int a[][nofs] = {{8, 10, 4, 5, 9},
                            {9, 6, 7, 5, 6}};
    int t[][nofs] = {{0, 2, 3, 1, 3},
                            {0, 2, 1, 2, 2}};
    int e[] = {3, 5}, x[] = {2, 1};

    cout << carAssembly(a, t, e, x);

    return 0;
}
