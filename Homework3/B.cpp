#include<bits/stdc++.h>
using namespace std;
#define N 205
#define pb push_back
vector<int> g[N];
int dist[N];
int main(){
   int t, v, e, a, b, CC, B, total;
   scanf("%d ",&t);
   while(t--){
       scanf("%d %d",&v,&e);
       if(!e){
           printf("%d\n",v);
           continue;
       }
       memset(g, 0, sizeof g);
       for(int i = 0; i < e;i++){
           scanf("%d %d",&a,&b);
           g[a].pb(b);
           g[b].pb(a);
       }
       CC = B = total = 0;
       bool F = 0;
       queue<int> cola;
       memset(dist, -1, sizeof dist);
       for(int i = 0; i < v; i++){
           if(dist[i] == -1){
               int par = 1,impar = 0;
               cola.push(i);
               dist[i] = 0;
               bool bipartito = true;
               while(!cola.empty()){
                   int U = cola.front(); cola.pop();
                   for(auto X: g[U]){
                       if(dist[X] == -1){
                           dist[X] = dist[U]+1;
                           if(dist[X]&1)impar++;
                           else par++;
                           cola.push(X);
                       }else if(dist[X]%2 == dist[U]%2) bipartito = false;
                   }
               }
               if(bipartito){
                   if(par == 1)total++;
                   else total += min(par, impar);
               }else{
                   printf("-1\n");
                   F = 1;
                   break;
               }
           }
       }
       if(!F)printf("%d\n",total);
   }
}
