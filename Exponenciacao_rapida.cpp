#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fexp(ll base, ll exp){
	ll ans = 1;
	while(exp){ // enquanto o exp > 0
		if(exp & 1){
			ans*=base;
		}
		base *= base;
		exp = exp >> 1;
	}
	return ans;
}

int main(){
	cout << fexp(3,7) << endl;
	return 0;
}
