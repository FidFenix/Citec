#include<bits/stdc++.h>
using namespace std;
#define N 1000006
#define f first
#define s second
typedef pair<int,int> PII;
int id[N];
int rango[N];
PII P;
int find(int p){
        while(p != id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
}
bool conectado(int p, int q){
        return find(p) == find(q);
}
void unir(int p, int q){
        int i = find(p);
        int j = find(q);
        if(i == j)return;
        if (rango[i]<rango[j]) id[i] = j;
        else if (rango[i] > rango[j]) id[j] = i;
        else id[j] = i,rango[i]++;
}
void num(string l){
    int i = 2;
    string  NN = "";
    while(l[i] != ' ')NN += l[i++];
    P.f = stoi(NN);
    P.s = stoi(l.substr(i));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t,  n, m, k,a,b;
    cin>>t;
    string l;
    getline(cin, l);
    getline(cin, l);
    while(t--){
        int A = 0, B = 0;
        memset(rango, 0, sizeof rango);
        getline(cin,l);
        n = stoi(l);
        for(int i = 0; i <= n; i++) id[i] = i;
        while(1){
            if(!getline(cin,l))break;
            if(!l.size())break;
            num(l);
            if(l[0] == 'c')unir(P.f,P.s);
            else (conectado(P.f,P.s))?A++ : B++;
        }
        cout<<A<<","<<B<<endl;
        if(t)cout<<endl;
    }
}
