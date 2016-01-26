#include<bits/stdc++.h>
using namespace std;
int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool isvalid(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t, X, Y;
    cin>>t;
    while(t--){
        cin>>n>>m;
        string l[n];
        for(int i = 0; i < n; i++)cin>>l[i];
        bool F = 0, F1 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(l[i][j] != 'F'){
                    F1 = 0;
                    int count = 0;
                    for(int k = 0; k < 8; k++){
                        X = dx[k] + i;
                        Y = dy[k] + j;
                        if(isvalid(X, Y) && l[X][Y] == 'F')count++;
                    }
                    if(count != l[i][j] - '0'){
                        F = 1;
                        break;
                    }
                }
            }
            if(F)break;
        }
        F || F1?cout<<"Please sweep the mine again!"<<endl: cout<<"Well done Clark!"<<endl;
   }
}
