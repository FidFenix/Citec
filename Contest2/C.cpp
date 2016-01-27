#include<bits/stdc++.h>
using namespace std;
#define MP(i,j) make_pair(i,j)
#define pb(i) push_back(i);
#define f first
#define s second
int main(){
    int n, m, k, N,num,q;
    
   while(scanf("%d %d",&n,&q) != EOF){
    map<int,vector < int > > M;
    for(int i = 1; i <= n; i++){
        scanf("%d",&num);
        M[num].pb(i);
    }
    while(q--){
        scanf("%d %d",&k,&N);
        if(k > M[N].size())printf("0\n");
        else printf("%d\n",M[N][k-1]);
    }
   }
}
