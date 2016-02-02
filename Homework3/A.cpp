#include<bits/stdc++.h>
using namespace std;
#define N 200002
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair<int, PII> CII;
int id[N];
int rango[N];
inline int find(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}
inline bool unir(int p,int q){
    int i = find(p);
    int j = find(q);
    if(i == j)return 0;
    if(rango[i] < rango[j]) id[i] = j;
    else if(rango[j] < rango[i]) id[j] = i;
    else id[j] = i,rango[i]++;
    return 1;
}
int main(){
    int V, E,a,b,c,k,COSTO_TOTAL,COSTO;
    while(scanf("%d %d",&V,&E),(V+E)){
        CII adj[E];
        memset(rango, 0, sizeof rango);
        k = 0;
        COSTO_TOTAL = 0;
        for(int i = 0; i <= V; i++)id[i] = i;
        for(int i = 0; i < E; i++){
            scanf("%d%d%d",&adj[k].s.f,&adj[k].s.s,&adj[k].f);
            COSTO_TOTAL += adj[k++].f;
        }
        sort(adj, adj + E);
        COSTO = 0;
        for(CII X: adj){
            if(unir(X.s.f, X.s.s)){
                COSTO += X.f;
                V--;
            }
            if(V == 1)break;
        }
        printf("%d\n",COSTO_TOTAL - COSTO);
    }
}
