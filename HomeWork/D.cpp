#include<bits/stdc++.h>
using namespace std;
string B[4], l;
bool BB[4][4];
bool F = 0;
int P[5] = {1, 1, 2, 3, 5};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool isvalid(int x, int y){
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}
void dfs(int u, int v, int pos){
    if(pos >= l.size()){
        F = 1;
        return;
    }
    if(l[pos] == B[u][v]){
        BB[u][v] = 1;
        for(int i = 0; i < 8; i++){
                int X = dx[i] + u;
                int Y = dy[i] + v;
                if(isvalid(X,Y)){
                    if(!BB[X][Y]) {
                        dfs(X, Y, pos+1);
                        BB[X][Y] = 0;
                    }else if(pos+1 >= l.size()){
                        F = 1;
                        return;
                    }

                }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int n, m, sum;
    cin>>n;
    for(int k = 1; k <= n; k++){
        for(int i = 0; i < 4; i++)cin>>B[i];
        cin>>m;
        sum = 0;
        while(m--){
            cin>>l;
            F = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(B[i][j] == l[0]){
                        dfs(i,j,0);
                        memset(BB, 0 ,sizeof BB);
                        if(F){
                            sum += 8 <= l.size()?11:P[l.size()-3];
                            break;
                        }
                    }
                }
                if(F)break;
            }
        }
        cout<<"Score for Boggle game #"<<k<<": "<<sum<<endl;
    }
}
