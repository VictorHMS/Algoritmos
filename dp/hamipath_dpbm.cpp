#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define inf 11234567
typedef pair<int,int> pii;
typedef long long ll;
int n,m;
int ham;
ll ans;
ll dp[20][2040];
vector<pii> gra[30];
void adda(int x, int y, int z){
    gra[x].pb(make_pair(y,z));
    gra[y].pb(make_pair(x,z));
}
void init(){
    for(int i=0; i<n; i++){
        for(int j=0;j<2040; j++){
            dp[i][j] = inf;
        }
        dp[i][0]=0;
    }
    ans = inf;
}
void solve(int k,int mask){
    if(mask == ham){
        ans = min(ans,dp[k][mask]);
        return;
    }
    int tam = gra[k].size();
    for(int i=0; i<tam; i++){
        int x = gra[k][i].first;
        if(!(mask&(1<<x))){
            int val = dp[x][mask|(1<<x)];
            dp[x][mask|(1<<x)] = min(dp[x][mask|(1<<x)], dp[k][mask] + gra[k][i].second);
            if(dp[x][mask|(1<<x)] < val){
                solve(x,mask|(1<<x));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    ham = 0;
    for(int i=0; i<n; i++){
        ham = ham|(1<<i);
    }
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        adda(x-1,y-1,z);
    }
    init();
    for(int i=0; i<n; i++){
        int mask = 1<<i;
        dp[i][mask] = 0;
        solve(i,mask);
    }
    cout << ans << endl;
    return 0;
}