#include <iostream>
using namespace std;
int n;
int main(){
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==0 || i==n-1 || j==0 || j==n-1) cout<< A[i][j]<< " ";
            else cout<< " ";
        }
        cout<< endl;
    }
    return 0;
}
