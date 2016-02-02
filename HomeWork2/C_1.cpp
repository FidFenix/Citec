#include<bits/stdc++.h>
using namespace std;
#define N 30004
int id[N];
int rango[N];
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
        if (rango[i] < rango[j]) id[i] = j;
        else if (rango[i] > rango[j]) id[j] = i;
        else id[j] = i,rango[i]++;
}
int main(){
    int n, m, dig, d, ant, FLAG, pacientes;
    while(scanf("%d %d",&n,&m),(n+m)){
        for(int i = 0; i <= n; i++){
            id[i] = i;
            rango[i] = 0;
        }
        while(m--){
            scanf("%d",&dig);
            FLAG = 0;
            while(dig--){
                scanf("%d",&d);
                if(!FLAG)FLAG = 1, ant = d;
                else unir(ant,d);
            }
        }
        pacientes = 1;
        for(int i = 1; i <= n; i++)
            if(conectado(0,i))pacientes++;
        printf("%d\n", pacientes);
    }
}
