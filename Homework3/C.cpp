#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef pair<int,int> PII;
#define MP(i,j) make_pair(i,j)
#define f first
#define s second
int n, m;
string arr[N];
bool mark[N][N];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1,-1, 1, -1 ,0 ,1};
bool valid(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m && arr[i][j] != '*' && !mark[i][j];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    while(1){
        int CC = 0;
        cin>>n>>m;
        if(!(n + m))break;
        for(int i = 0; i < n; i++) cin>>arr[i];
        m = arr[0].size();
        memset(mark, 0, sizeof mark);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!mark[i][j] && arr[i][j] != '*'){
                    mark[i][j] = 1;
                    queue<PII> cola;
                    cola.push(MP(i,j));
                    while(!cola.empty()){
                        PII U = cola.front(); cola.pop();
                        for(int i = 0; i < 8;i++){
                            int X = dx[i] + U.f;
                            int Y = dy[i] + U.s;
                            if(valid(X,Y)){
                                cola.push(MP(X,Y));
                                mark[X][Y] = 1;
                            }
                        }
                    }
                    CC++;
                }
            }
        }
        cout<<CC<<endl;
    }
}
