#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define N 1005
#define MP(i,j) make_pair(i,j)
typedef pair<int,int> PII;
typedef pair<int,PII> PD;
int V, E;
vector<PD> adj[N];
bool mark[N];
bool taken[N];
priority_queue<PD> pq;
void process(int v){
    taken[v] = 1;
    for(auto X : adj[v]){
        if(!taken[X.s.f])pq.push(MP(-X.f, MP(X.s.f, X.s.s)));
    }
}
int prim(){
    memset(taken, 0, sizeof taken);
    process(1);
    int mst = 0, cont = 1,f = 0;
    while(!pq.empty()){
        PD nodo = pq.top();pq.pop();
        int u = nodo.s.f, w = -nodo.f, id = nodo.s.s;
        if(!taken[u]){
            cont++;
            mark[id] = 1;
            mst += w;
            process(u);
        }
    }
    if(cont == V)return mst;
    return -1;
}

void process2(int v, int id){
    taken[v] = 1;
    for(auto X : adj[v]){
        if(!taken[X.s.f] && X.s.s != id){
            pq.push(MP(-X.f, MP(X.s.f, X.s.s)));
        }
    }
}
int prim2(int id){
    memset(taken, 0, sizeof taken);
    process2(1, id);
    int mst = 0, cont = 1;
    while(!pq.empty()){
        PD nodo = pq.top();pq.pop();
        int u = nodo.s.f , w = -nodo.f;
        if(!taken[u]){
            cont++;
            mst += w;
            process2(u, id);
        }
    }
    if(cont == V)return mst;
    return -1;
}
int solve(){
    int mst_t = 1e8;
    for(int i = 0; i < E; i++){
        if(mark[i]){
            int R = prim2(i);
            if(R != -1)mst_t = min(mst_t, R);
        }
    }
    if(mst_t == 1e8)return -1;
    return mst_t;
}
int main(){
   int t, a, b, c;
   scanf("%d",&t);
   for(int T = 1; T <= t; T++){
       scanf("%d %d",&V,&E);
       memset(adj, 0, sizeof adj);
       memset(mark, 0, sizeof mark);
       for(int i = 0 ; i < E; i++){
           scanf("%d %d %d",&a,&b,&c);
           adj[a].push_back(MP(c, MP(b,i)));
           adj[b].push_back(MP(c, MP(a,i)));
       }
       int mst = 0, mst_t = 0;
       mst = prim();
       if(mst == -1){
           printf("Case #%d : No way\n",T);
           continue;
       }
       if(E == 0){
           printf("Case #%d : No second way\n",T);
           continue;
       }
       mst_t = solve();
       if(mst_t == -1)printf("Case #%d : No second way\n",T);
       else printf("Case #%d : %d\n",T,mst_t);
   }
}
