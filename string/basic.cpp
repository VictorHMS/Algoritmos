#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int tc;
    string a;
    cin >> tc;
    while(tc--){
        int ip,ep;
        cin >> a >> ip >> ep;
        sort(a.begin()+ip , a.begin()+ep+1, greater<char>());
        cout << a << endl;
    }
}