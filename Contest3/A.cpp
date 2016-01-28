#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> P;
#define MP(i,j) make_pair(i,j)
#define f first
#define s second
#define N 105
int F,C;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0 };
int mark[N][N];
int arr[N][N];
bool valid(int a, int b){
    return 0 <= a && a < F && 0 <= b && b < C;
}
int main(){
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&C, &F);
        for(int i = 0;i < F; i++){
            for(int j = 0;j < C; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        memset(mark,-1, sizeof mark);
        scanf("%d %d %d %d ",&a,&b,&c,&d);
        queue<P> cola;
        cola.push(MP(1, MP(b,a)));
        mark[b][a] = 1;
        while(!cola.empty()){
            P p = cola.front(); cola.pop();
            for(int i = 0; i < 4; i++){
                int X = dx[i] + p.s.f;
                int Y = dy[i] + p.s.s;
                if(valid(X,Y) && mark[X][Y] == -1 && arr[X][Y] != 1){
                    cola.push(MP(p.f + 1, MP(X,Y)));
                cout<<X<<" "<<Y<<endl;
                    mark[X][Y] = p.f + 1;
                }
            }
        }
        printf("%d\n", mark[d][c]);
    }
}
