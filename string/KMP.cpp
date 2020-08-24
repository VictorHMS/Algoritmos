#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

// set que contem todos os caracteres da palavra a ser encontrada
set<char> lt;

// vetor que está guardando todas as ocorrências da palavra
vector<int> oc;

// matriz do automato
// deve ter uma linha para cada caracter possível
// o número de colunas deve ter no mínimo o tamanho da palavra a ser encontrada 
// a matriz serve como se fossem instruções do tipo "se encontrar esse caractere nessa coluna, vá para a coluna indicada nessa casa"
int dfa[127][512345];

// nessa função a dfa é grada
void make_dfa(string &des){

    // tamanho da palavra a ser encontrada
    int n = des.size();

    // coluna auxiliar
    int x=0;
    // ela utiliza a propria parte ja processada da dfa
    // ao ler instruçoes anteriores ele ajuda a não perder o processamento completo caso não encontre a palavra completa
    /*//////////Exemplo///////////
        Ao procurar a palavra "asdasf" no texto "asdasdasf"
        perceba que os 5 primeiros caracteres do texto são iguais ao da palavra, no entanto ele não encontra o f na quinta posição
        contudo ele encontra o d que é equivalente ao 3 caracter e logo antes tem os caracteres 'a' e 's' que são o 1 e o 2
        logo ele não precisa procurar a palavra do zero, ele pode continuar da 3 posição
    *////////////////////////////
    
    // aqui são inseridos todos os caracteres dessa palavra no set
    // os demais caracteres que não estão na palavra mas podem ser encontrados no texto devem ter suas linhas zeradas na dfa
    for(int i=0; i<n;i++){
        lt.insert(des[i]);
    }

    // inicializando a dfa
    // ao encontrar a primeira letra na primeira coluna, passe para a segunda
    dfa[des[0]][0] = 1;

    // preenchendo a dfa a partir da segunda coluna
    for(int j=1; j<n; j++){
    
        // copia a coluna auxiliar na atual
        for(auto &l : lt){    
            dfa[l][j] = dfa[l][x];
        }

        // avisa que se o caracter desejado for encontrado nessa coluna, pode passar para a próxima
        dfa[des[j]][j] = j+1;

        // atualiza qual a coluna da dfa será usada como auxiliar na próxima iteração 
        x = dfa[des[j]][x];
    }
}

int search(string &proc, string &des){
    
    // faz a dfa
    make_dfa(des);
    
    int ans = 0;
    
    // tamanho da palavra
    int m = des.size();

    // tamanho do texto 
    int n = proc.size();

    // segue as instruções da dfa
    // ao chegar num valor de coluna igual ao tamanho da palavra, significa que ela foi encontrada
    for(int i=0, j=0; i<n; i++){
        j = dfa[proc[i]][j];
        if(j == m){ans++;j=0;oc.push_back(i-m+1);}
    }

    // retorna o numero de ocorrências
    return ans;
}

int main(){
    string p,g;
    cin >> p >> g;
    int ans = search(g,p);
    cout << "foram encontradas " << ans << " ocorrencias nas posicoes\n";
    for(int i=0; i<oc.size(); i++){
        cout << oc[i] << " ";
    }
    cout << endl;
}
