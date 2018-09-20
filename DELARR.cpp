#include <bits/stdc++.h>


using namespace std;
ifstream fin("DELARR.INP");
ofstream fout("DELARR.OUT");
typedef long long ll;
const int SIZE = 1E5 +5 ;

ll a[SIZE],b[SIZE];
int n;

void Input_Init()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
}
void Solve()
{
    ll tong=b[n];
    int i=1;
    int j=n;
    int Count=0;
    while(tong!=0 && i<=j)
    {
        if(tong < 0)
        {
            tong-=a[i];
            i++;
            Count++;
        }
        else if(tong>0)
        {
            tong-=a[j];
            j--;
            Count++;
        }

    }
    fout<<Count;
}
int main()
{
    Input_Init();
    Solve();
    return 0;
}
