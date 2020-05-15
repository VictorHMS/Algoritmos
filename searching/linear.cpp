#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll nelm, des;
    int res = -2;
    cin >> nelm >> des;
    for(int i=0; i<nelm; i++){
        ll a; cin >> a;
        if(a == des)res = i;
    }
    cout << res+1 << endl;
    return 0;
}