#include <bits/stdc++.h>
using namespace std;
#define tam 212345
typedef long long ll;
ll ft[tam]; //Minha BIT
int n;
int lso(int i){
    int least_significant_one = i & (-i);
    return least_significant_one;
    //retorna o numero que contem apenas o bit menos significante de i como 1;
}

void insert(int pos, int val){
    if(pos == 0)return;//não insira no 0;
    ft[pos]+=val;
    for(pos = pos+lso(pos); pos <= n; pos += lso(pos)){ // n é o tamanho da BIT que vai pode ser ate 212344
        ft[pos]+=val;                                   // Neste for eu fiz f[t]+=val, f[t']+=val, f[t'']+=val
    }                                                   // Sendo t o "pos" e t' é t+lso(t)
}

ll acumulado(int pos){
    ll ans = ft[pos];
    for(pos = pos-lso(pos); pos > 0; pos -= lso(pos)){
        ans += ft[pos];
    }
    return ans;
}

ll intervalo(int ini, int fim){
    ll res = acumulado(fim) - acumulado(ini-1);
    return res;
}

/*Testando ############ */

int main(){
    cin >> n;
    int a;
    cin >> a;
    while(a){
        if(a == 1){
            int pos, val;
            cin >> pos >> val;
            insert(pos,val);
        }
        if(a == 2){
            int des;
            cin >> des;
            cout << acumulado(des) << endl;
        }
        if(a == 3){
            int ini, fim;
            cin >> ini >> fim;
            cout << intervalo(ini,fim) << endl;
        }
        cin >> a;
    }
    return 0;
}
