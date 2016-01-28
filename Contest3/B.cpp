#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> P;
#define MP(i,j) make_pair(i,j)
#define f first
#define s second
#define N 8
int F = 8,C = 8;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int mark[N][N];
char l1[5];
char l2[5];
bool valid(int a, int b){
    return 0 <= a && a < F && 0 <= b && b < C;
}
int main(){
    int t,a,b,c,d;
    scanf("%d",&t);
    while(scanf("%s %s",l1,l2) != EOF){
        memset(mark,-1, sizeof mark);
        queue<P> cola;
        a = 8 - (l1[1] - '0');
        b = l1[0] - 'a';
        c = 8 - (l2[1] - '0');
        d = l2[0] - 'a';
        cola.push(MP(0, MP(a,b)));
        mark[a][b] = 0;
        while(!cola.empty()){
            P p = cola.front(); cola.pop();
            for(int i = 0; i < 8; i++){
                int X = dx[i] + p.s.f;
                int Y = dy[i] + p.s.s;
                if(valid(X,Y) && mark[X][Y] == -1){
                    cola.push(MP(p.f + 1, MP(X,Y)));
                    mark[X][Y] = p.f + 1;
                }
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n", l1, l2 , mark[c][d]);
    }
}
