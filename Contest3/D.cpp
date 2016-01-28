#include<bits/stdc++.h>
using namespace std;
#define N 1002
#define f first
#define s second
#define MP(i,j) make_pair(i,j)
typedef pair<int,int> PII;
typedef pair<double, PII> DP;
int id[N];
int rango[N];
inline int find(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}
inline bool unir(int p, int q){
    int i = find(p);
    int j = find(q);
    if(i == j)return 0;
    if(rango[i] < rango[j]) id[i] = j;
    else if(rango[j] > rango[i])id[j] = i;
    else id[j] = i, rango[i]++;
    return 1;
}
double D(PII x, PII y){
    double X = (double)x.f;
    double Y = (double)x.s;
    double A = (double)y.f;
    double B = (double)y.s;
    return sqrt((X-A)*(X-A) + (Y-B)*(Y-B));
}
int main(){
    int V;
    while(scanf("%d",&V),(V)){
        vector< DP> adj;
        PII point[V];
        for(int i = 0; i < V; i++){
            scanf("%d %d",&point[i].f,&point[i].s);
            id[i] = i;
            rango[i] = 0;
        }
        for(int i = 0; i < V; i++){
            for(int j = i+1; j < V; j++){
                adj.push_back(MP(D(point[i], point[j]),MP(i,j)));
            }
        }
        sort(adj.begin(), adj.end());
        double costo = 0.0;
        for(DP X : adj){
            if(unir(X.s.f, X.s.s)){
                costo += X.f;
                V--;
            }
            if(V == 1)break;
        }
        printf("%.2lf\n", costo);
    }
}
