#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define N 105
typedef pair<int,int> PII;
int V, E ,C;
vector<int> adj[N];
int id[N];
int rango[N];
bool mark[N*N];
bool marked[N];
int find(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}
bool unir(int p, int q){
    int i = find(p);
    int j = find(q);
    if(i == j)return false;
    if (rango[i]<rango[j]) id[i] = j;
    else if (rango[i] > rango[j]) id[j] = i;
    else id[j] = i,rango[i]++;
    return true;
}
void res(){
   for(int i = 0;i <= V; i++)id[i] = i;
   memset(rango, 0 ,sizeof rango);
}
void dfs(int u, int p){
    for(auto X: adj[u]){
        if(X == p)continue;
        if(!marked[X]){
            marked[X] = 1;
            dfs(X,u);
        }
    }
}
int CC(){
    int c = 0;
    memset(marked,0,sizeof marked);
    for(int i = 0; i < V; i++){
        if(!marked[i]){
            dfs(i,i);
            c++;
        }
    }
    return c;
}
int main(){
   int t, a, b, c;
   scanf("%d",&t);
   for(int T = 1; T <= t; T++){
       scanf("%d %d",&V,&E);
       pair<int,PII> G[E];
       memset(adj, 0, sizeof adj);
       memset(mark, 0, sizeof mark);
       for(int i = 0 ; i < E; i++){
           scanf("%d %d %d",&a,&b,&c);a--;b--;
           G[i].f   = c;
           G[i].s.f = a;
           G[i].s.s = b;
           adj[a].push_back(b);
           adj[b].push_back(a);
       }
       sort(G, G+E);
       int mst = 0, mst_t = 0;
       res();
       if(CC() > 1){
           printf("Case #%d : No way\n",T);
           continue;
       }
       a = 0;
       for(int i = 0; i < E; i++){
           if(unir(G[i].s.f, G[i].s.s)){
               mst += G[i].f;
               mark[i] = 1;
               a++;
           }
           if(a == V-1)break;
       }
       if(E == 0){
           printf("Case #%d : No second way\n",T);
           continue;
       }
       int minimo = 2147383647;
       for(int i = 0; i < E; i++){
           if(mark[i]){
               a = 0;
               mst_t = 0;
               res();
               for(int j = 0; j < E; j++){
                  if(j != i){
                    if(unir(G[j].s.f, G[j].s.s)){
                        mst_t += G[j].f;
                        a++;
                        if(a == V-1){
                            minimo = min(mst_t,minimo);
                            break;
                        }
                    }
                  }
               }
           }
       }
       if(minimo == 2147383647)printf("Case #%d : No second way\n",T);
       else if(minimo >= mst)printf("Case #%d : %d\n",T,minimo);
   }
}
