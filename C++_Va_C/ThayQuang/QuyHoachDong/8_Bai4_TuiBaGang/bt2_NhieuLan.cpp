#include <bits/stdc++.h>
#define maxn 105
#define fi first
#define se second
using namespace std;

int n, m;
int F[maxn][maxn];
vector<pair<int, int>> v;

int main(){
    //freopen("CAYKHE.INP", "r", stdin);
    //freopen("CAYKHE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m; v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i].se>> v[i].fi;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            F[i][j]=F[i-1][j];
            if (j>=v[i].se) F[i][j]=max(F[i][j], F[i][j-v[i].se]+v[i].fi);
        }
    }
    cout<< F[n][m]<< endl;
    int i=n, j=m;
    int Count[n+1];
    memset(Count, 0, sizeof Count);
    while (F[i][j]!=0){
        if (F[i][j]==F[i-1][j]) i--;
        else{
            if (F[i][j]==F[i][j-v[i].se]+v[i].fi){
                Count[i]++;
                j-=v[i].se;
            }
        }
    }
    for (int i=1; i<=n; i++)
        if (Count[i]!=0)
            cout<< i<< " "<< Count[i]<< endl;
    return 0;
}
