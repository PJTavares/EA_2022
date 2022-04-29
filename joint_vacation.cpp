#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stdio.h>
#include <math.h>
using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << g.front() << ' ';
        g.pop();
    }
    cout << '\n';
}

int Dijstra(vector<vector<int>> G, int s, int t, queue<int> Q){
    vector<int> d;
    for(int i = 0 ; i < t ; i++){
        d.push_back(999999);
    }
    d[0] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        //cout << "=== DEGUB ===\n";
        //cout << u << '\n';
        //showq(Q);
        //cout << "=============\n";
        
        if(u == t){
            break;
        }

        for (int v = 0 ; v < G[u].size();v++) {
            if(G[u][v] > -1){
                if(d[v] > d[u] + G[u][v]){
                    d[v] = d[u] + G[u][v];
                }
            }
        }
        cout << '\n';

        for(int i = 0 ; i < d.size() ; i++){
            cout << d[i] << ' ';
        }
        cout << '\n';
    }
    return d[t];
}

int main() {
    int num,finish,value;
    cin >> num >> finish;

    vector<vector<int>> matrix;
    vector<int> adj;
    queue<int> Q;

    for(int i = 0 ; i < num ; i++){
        cin >> value;
        //adj.push_back(value);
        Q.push(value-1);
        for(int j = 0 ; j < num  ; j++){
            cin >> value;
            adj.push_back(value);
        }
        matrix.push_back(adj);
        adj.clear();
    }

    /*for(int i = 0 ; i < matrix[0].size() ; i++){
        if(matrix[0][i] > -1){
            Q.push(i);
        }
    }*/

    showq(Q);
    int out = Dijstra(matrix,Q.front(),finish-1,Q);
    cout << out << '\n';
   /*
    cout << "VALORES DO INPUT\n";
    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j < matrix[i].size() ; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }*/
}