#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n, k;
    cin>>n>>k;
    string arr[n];
    for(int i = 0; i < n; i++)cin>>arr[i];
    int mini = 1e9, menor = 1e8, mayor = -13, tmp;
    int perm[k];
    for(int i = 0; i < k; i++)perm[i] = i;
    do{
        for(int i = 0; i < n; i++){
            string N = "";
            for(int j = 0; j < k; j++){
                N += arr[i][perm[j]];
            }
            tmp = stoi(N);
            if(tmp > mayor)mayor = tmp;
            if(tmp < menor)menor = tmp;
        }
        mini = min(mini, mayor - menor);
        menor = 1e8; mayor = -13;
    }while(next_permutation(perm, perm+k));
    cout<<mini<<endl;
}
