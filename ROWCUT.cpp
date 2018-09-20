#include <bits/stdc++.h>

using namespace std;

ifstream fin("ROWCUT.INP");
ofstream fout("ROWCUT.OUT");
typedef long long ll;
const int SIZE = 3000 + 5 ;
const int BASE = 29;
const ll MOD = 1e9+7;
char a[SIZE][SIZE];
ll Hash[SIZE][SIZE];
int n,m;
void Input()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i] + 1;
}
ll Get_Hash(int h,int j)
{
    return (Hash[h][j] + MOD*MOD)%MOD;
}
void Init()
{
    for(int j=1; j<=m; j++)
        for(int i=1; i<=n; i++)
        {
            Hash[i][j]=(Hash[i-1][j]*BASE + a[i][j] -32 +1)%MOD;
        }
}
void Solve()
{
    vector <ll> Q;
    Q.clear();
    int Count=0;
    int h=n;
    while(h>=1)
    {
        for(int i=1; i<=m; i++)
            Q.push_back(Get_Hash(h,i));
        sort(Q.begin(),Q.end());
        for(int i=1; i<Q.size();i++)
            if(Q[i]==Q[i-1])
            {
                if(h==n)
                {
                    fout<<-1;
                    exit(0);
                }
                else
                {
                    fout << Count-1;
                    exit(0);
                }
            }
        Q.clear();
        Count++;
        h--;
    }
}
int main()
{
    Input();
    Init();
    Solve();
    return 0;
}
