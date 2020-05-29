#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()

typedef struct ponto{
    double x;
    double y;
}ponto;
vector <ponto> poli;
vector <ponto> orpoli;
vector <ponto> chull;
map <int, int> cusd;
double piu = acos(-1);

double norm(ponto a){
    double n = sqrt((a.x*a.x) + (a.y*a.y));
    return n;
}

ponto vetor(ponto a, ponto b){
    ponto vet;
    vet.x = a.x-b.x;
    vet.y = a.y-b.y;
    return vet;
}

ponto normal(ponto a){
    double no = norm(a);
    ponto vet;
    vet.x = a.x/no;
    vet.y = a.y/no;
    return vet;
}

bool same(ponto a, ponto b){
    return (a.x == b.x && a.y == b.y);
}

int cmpy(ponto a, ponto b){
    if(a.y < b.y)return 1;
    if(a.y > b.y)return 0;
    if(a.x < b.x)return 1;
    return 0;
}

double macos(ponto a){
    a = normal(a);
    double ans = acos(a.x);
    if(a.y < 0){
        ans = (2*piu) - ans;
    }
    return ans;
}

double difang(double a, double b){
    if(a < b){
        return a + (2*piu) - b;
    }
    return a-b;
}

void cvxh(ponto a, ponto ant, int id){
    chull.pb(a);
    //cusd[id] = 1;
    ponto vet = normal(vetor(ant,a));
    double ang = macos(vet);
    //cout << "ang " << ang << endl;
    int tst = 0;
    double bst;
    ponto atu;
    int ind;
    for(int i=0; i<poli.size(); i++){
        if(i == id || cusd[i])continue;
        ponto veta = normal(vetor(poli[i],a));
        //cout << "veta: " << veta.x << " " << veta.y << endl;
        double nang = macos(veta);
        double angat = difang(nang,ang);
        //cout << "nang " << nang << endl;
        //cout << "angat entre: " << a.x << " " << a.y << " e " << poli[i].x << " " << poli[i].y << " = " << angat << endl;
        if(!tst){
            atu = poli[i];
            bst = angat;
            ind = i;
            tst = 1;
        }else{
            if(angat > bst){
                atu = poli[i];
                bst = angat;
                ind = i;
            }
        }
    }
    cusd[ind] = 1;
    if(same(poli[ind], poli[0])){
        return;
    }
    cvxh(poli[ind], a, ind);
    return;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0)break;
        poli.clear();
        orpoli.clear();
        cusd.clear();
        chull.clear();
        for(int i=0; i<n; i++){
            ponto a;
            cin >> a.x >> a.y;
            poli.pb(a);
            orpoli.pb(a);
        }
        double t1=0,t2=0;
        for(int i=0; i<n; i++){
            double a1 = poli[i%n].x * poli[(i+1)%n].y;
            double a2 = poli[i%n].y * poli[(i+1)%n].x;
            t1 += a1;
            t2 += a2;
        }
        double area = (t1 - t2)/2.0;
        sort(all(poli),cmpy);
        ponto aux = poli[0];
        aux.x += 1;
        cvxh(poli[0],aux,0);
        /*/
        for(int i=0; i<chull.size(); i++){
            cout << chull[i].x << " " << chull[i].y << endl;
        }
        /**/
        int index;
        for(int i=0; i<n; i++){
            if(same(orpoli[i],chull[0])){
                index = i;
                break;
            }
        }
        int delindex = 0;
        for(int i=0; i<n; i++){
            if(same(orpoli[(i+index)%n],chull[delindex])){
                delindex++;
            }
        }
        if(delindex == chull.size()){
            printf("CW ");
        }else{
            printf("CCW ");
        }
        printf("%.1lf\n",abs(area));
    }
    return 0;
}
