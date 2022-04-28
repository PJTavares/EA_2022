#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int Dijstra(vector<vector<int>> G, int s, int t){
    return 0;
}

int main() {
    int num,finish,value;
    cin >> num >> finish;

    vector<vector<int>> matrix;
    vector<int> adj;
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num + 1 ; j++){
            cin >> value;
            adj.push_back(value);
        }
        matrix.push_back(adj);
        adj.clear();
    }

    cout << "VALORES DO INPUT\n";
    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j < matrix[i].size() ; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}