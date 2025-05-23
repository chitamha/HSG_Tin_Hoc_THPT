#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ill pair<int, ll>
using namespace std;

int n, m, s, t, d[300005], F[300005], color[300005], Topo[300005], cnt;
vector<ill> adj[300005];
ll MOD=1000000007;

void DFS(int u){
    color[u]=1;
    for (ill p:adj[u]){
        if (color[p.fi]==0)
            DFS(p.fi);
    }
    Topo[cnt--]=u;
}

void Dijkstra(){
    fill(d+1, d+n+1, 2e9);
    priority_queue<ill, vector<ill>, greater<ill>> pq;
    d[s]=0;
    pq.push({0, s});
    while (!pq.empty()){
        int u=pq.top().se; ll dis=pq.top().fi;
        pq.pop();
        if (dis>d[u]) continue;
        for (ill p:adj[u]){
            int v=p.fi, w=p.se;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    freopen("DAG.INP", "r", stdin);
    freopen("DAG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> s>> t;
    cnt=n;
    for (int i=1; i<=m; i++){
        int a, b, c;
        cin>> a>> b>> c;
        adj[a].push_back({b, -c});
    }
    Dijkstra();
    if (d[t]==2e9) cout<< "NO PATH"<< endl;
    else cout<< -d[t]<< endl;
    for (int i=1; i<=n; i++) if (color[i]==0) DFS(i);
    F[s]=1;
    for (int i=1; i<=n; i++){
        int u=Topo[i];
        for (ill p:adj[u]){
            int v=p.fi;
            F[v]=(F[v]+F[u])%MOD;
        }
    }
    cout<< F[t];
    return 0;
}
