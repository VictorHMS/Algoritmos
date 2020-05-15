#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<ll> vet;

int bb(ll val,ll n){
    int high = n-1;
    int low = 0;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(vet[mid] > val){
            high = mid-1;
        }else if(vet[mid] < val){
            low = mid+1;
        }else{
            return mid+1;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll nelm, des, ns;
    int res = -2;
    cin >> nelm;
    for(int i=0; i<nelm; i++){
        ll a; cin >> a;
        vet.push_back(a);
    }
    sort(all(vet));
    cin >> ns;
    while(ns--){
        cin >> des;
        res = bb(des,nelm);
        cout << res << endl;
    }
    return 0;
}