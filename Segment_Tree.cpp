#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 123456

ll st[2*maxn];
int n;

ll RSQ(int com, int fim){
	com+=n;
	fim+=n;
	ll res=0;
	while(com<=fim){
		if(com%2)res+=st[com++];
		if(!(fim%2))res+=st[fim--];
		com = com >> 1;
		fim = fim >> 1;
	}
	return res;
}

void add(int pos, ll val){
	pos+=n;
	st[pos]=val;
	for(pos = pos>>1; pos > 0; pos = pos>>1){
		st[pos] = st[pos<<1] + st[(pos<<1)+1];
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		ll a;
		cin >> a;
		add(i,a);
	}
	int qtd;
	cin >> qtd;
	while(qtd--){
		int op;
		cin >> op;
		if(op == 1){
			int l, r;
			cin >> l >> r;
			cout << RSQ(l,r) << endl;
		}else{
			int pos;
			ll val;
			cin >> pos >> val;
			add(pos,val);
		}
	}
	return 0;
}
