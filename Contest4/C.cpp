#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int t;
    string l;
    cin>>t;
    getline(cin,l);
    getline(cin,l);
    while(t--){
        vector<int> V;
        while(1){
            if(!getline(cin,l))break;
            if(!l.size())break;
            V.push_back(stoi(l));
        }
        int n = V.size(), mayor = 1;
        int arr[n];
        for(int i = 0; i < n; i++)arr[i] = 1;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(V[i] < V[j]){
                    if(arr[j] < arr[i] + 1) arr[j] = arr[i] + 1;
                    mayor = (mayor,arr[j]);
                }
        stack<int> pila;
        cout<<"Max hits: "<<mayor<<endl;
        for(int i = n-1; i >= 0 && mayor; i--){
            if(arr[i] == mayor){
                pila.push(V[i]);
                mayor--;
            }
        }
        while(!pila.empty()){
            cout<<pila.top()<<endl;
            pila.pop();
        }
        if(t)cout<<endl;
    }
}
