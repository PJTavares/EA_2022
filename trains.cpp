#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

std::vector<int> cores;
std::vector<vector<int>> adj;

int n,m,train1,train2;

int BFS(int vertex){
    queue<int> myqueue;
    cores[vertex] = 1;
    myqueue.push(vertex);

    while(!myqueue.empty()){
        int t = myqueue.front();
        myqueue.pop();

        for(int i = 0 ; i < n ; i++){
            if(adj[t][i] != 0){
                if(cores[i] == 0){
                    cores[i] = 1 - cores[t];
                    myqueue.push(i);
                }
                else if(cores[i] == cores[t]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

void makeVector(int n){
    cores.resize(n);
    adj.resize(n);
    for(int i = 0 ; i < n ; i++){
        adj[i].resize(n);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            adj[i][j] = 0;
        }
    }
}

int main(){
    while(!std::cin.eof()){
        cin >> n >> m;
        makeVector(n);
        for(int i = 0 ; i < m ; i++){
            cin >> train1 >> train2;
            adj[train1-1][train2-1]+=1;
            adj[train2-1][train1-1]+=1;
        }
        
        if(BFS(0)){
            cout << "NOT SURE\n";
        }
        else{
            cout << "NO\n";
        }       

    }
    return 0;
}