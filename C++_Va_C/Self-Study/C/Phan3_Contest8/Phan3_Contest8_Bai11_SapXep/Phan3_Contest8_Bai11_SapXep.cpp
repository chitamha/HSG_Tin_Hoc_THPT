#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
        sort(A[i], A[i]+n);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}
