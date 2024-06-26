#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, ans=0, X[15];
vector<ll> A;

ll cnt=0;

void xuli(){
    ll tmpans=0, tich;
    X[0]=X[n]=1;
    /*
    cout<< ++cnt<< ": "<< A[1];
    for (int i=2; i<=n; i++){
        if (X[i-1]==1) cout<< "+"<< A[i];
        else if (X[i-1]==2) cout<< "-"<< A[i];
        else if (X[i-1]==3) cout<< "*"<< A[i];
    }
    cout<< "\n";
    */
    for (int i=1; i<=n; i++){
        if (X[i-1]!=3 && X[i]!=3){
            if (X[i-1]==1) tmpans=(tmpans+A[i]%m)%m;
            else if (X[i-1]==2) tmpans=(tmpans-A[i]%m)%m;
        } else{
            tich=A[i];
            if (X[i-1]==2) tich=-A[i];
            i++;
            while (i<=n && (X[i-1]==3 && X[i]==3)){
                tich=(tich*(A[i]%m))%m;
                i++;
            }
            tich=(tich*(A[i]%m))%m;
            tmpans+=tich;
        }
    }
    //cout<< tmpans<< "\n";
    ans+=tmpans%m==0;
}

void Try(ll i){
    //1: +; 2: -; 3: *
    for (ll j=1; j<=3; j++){
        X[i]=j;
        if (i==n-1) xuli();
        else Try(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    while (t--){
        cin>> n>> m;
        A.resize(n+1); ans=0;
        for (ll i=1; i<=n; i++) cin>> A[i];
        Try(1);
        cout<< ans<< "\n";
        A.clear();
    }
    return 0;
}
