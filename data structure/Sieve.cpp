#include <bits/stdc++.h>
using namespace std;

const int  M = 1e6;
bool prime[M];
vector<int>allPrime;
void Sieve()
{

    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= M; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= M; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= M; i++)
        if (prime[i])allPrime.push_back(i);

}
int main()
{
    int n = 30;
    Sieve();
    for(int i=0;i<allPrime.size();i++)
    {
        if(allPrime[i]<=n)cout<<allPrime[i]<<" ";
        else break;
    }
    return 0;
}
