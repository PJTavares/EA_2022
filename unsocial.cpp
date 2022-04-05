#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


std::vector<vector<int>> connection;
std::vector<int> vizinhos;

int best = 0;
int n,m,first,sec;
 
void resetVector(int rows,int col){
    connection.resize(rows);
    vizinhos.resize(rows);
    for(int aux = 0;aux<rows;aux++){
        connection[aux].resize(col);
    }

    for(int i = 0;i<rows;i++){
        vizinhos[i] = 0;
        for(int j = 0;j<rows;j++){
            connection[i][j] = 0;
        }
    }
}
/*
void escreveVector(int rows,int col){
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<i;j++){
            cout << connection[i][j] <<" ";
        }
        cout << "\n";
    }
}*/
void mis(int v,int size){
    if (size > best) {
        best = size;
    }
    int UB = 0;
    for (int i = v + 1; i < n ; i++){
        if(vizinhos[i] == 0){
            UB++;
        }
    }
    if(size + UB <= best){
        return;
    }

    for (int i = v + 1 ; i < n ; i++){
        if(connection[i][v] > 0){
            vizinhos[i]++;
        }
    }
    for (int i = v + 1 ; i < n ; i++){
        if(vizinhos[i] == 0){
            mis(i,size+1);
        }
    }
    for (int i = v + 1 ; i < n ; i++){
        if(connection[i][v] > 0){
            vizinhos[i]--;
        }
    }
    
}
int main(){
    cin >> n >> m;
    resetVector(n,n);
    for(int i = 0 ; i < m ; i++){
        cin >> first >> sec;
        connection[first][sec]++;
        connection[sec][first]++;
    }
    for(int i = 0 ; i< n ;i++){
        mis(i,1);
    
    }

    //cout << '\n';

    cout << best << '\n';
    return 0;
}