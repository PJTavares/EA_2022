#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

std::vector<vector<int>> adj;
std::vector<int> cores;

int BFS(int vertex){
    int t;
    queue<int> myqueue;
    cores[vertex] = 1;
    myqueue.push(vertex);


    while(!myqueue.empty()){
        t = myqueue.front();
        myqueue.pop();

        for(int i: adj[t]){
            if(cores[i] == -1){
                cores[i] = 1 - cores[t];
                myqueue.push(i);
            }
            else if(cores[i] == cores[t]){
                return 0;
            }
            
        }
    }
    return 1;
}

int main(){
    while(!std::cin.eof()){
        int n,m,train1,train2;

        cin >> n >> m;
        int wrong = 0;

        adj.resize(n);
        cores.resize(n);
        for(int i = 0 ; i < n ; i++){
            cores[i] = -1;
        }

        for(int i = 0 ; i < m ; i++){
            cin >> train1 >> train2;
            adj[train1-1].push_back(train2-1);
            adj[train2-1].push_back(train1-1);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(cores[i] == -1){
                int result = BFS(i);
                if(result == 0){
                    wrong = 1;
                    break;
                }
            }
        }
        if(wrong){
            cout << "NO" << endl;
        }
        else{
            cout << "NOT SURE" << endl;
        }       

        adj.clear();
        cores.clear();
    }
    return 0;
}