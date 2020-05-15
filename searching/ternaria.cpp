#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

double func(double x){
    return double((2*x*x) - (12*x) + 7);
}

double ternaria(double l, double r){
    double l1, l2;
    for(int i=0; i<200; i++){
        l1 = (2*l + r)/3;
        l2 = (2*r + l)/3;
        if(func(l1) < func(l2))r = l2;
        else l = l1;
    }
    return func(l);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        double a,b;
        cin >> a >> b;
        printf("%.0lf\n",ternaria(a,b));
    }
    return 0;
}