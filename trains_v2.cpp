#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

tuple<int, vector<int>> trains(vector<vector<int>> adj, vector<int> cores, int vertex) {
    queue<int> myqueue;
    int t;

    cores[vertex] = 1;
    myqueue.push(vertex);

    while (!myqueue.empty()) {
        t = myqueue.front();
        myqueue.pop();

        for (int id: adj[t]) {
            if (cores[id] == -1) {
                cores[id] = 1 - cores[t];
                myqueue.push(id);
            } else if (cores[id] == cores[t]) {
                return make_tuple(0, cores);
            }
        }
    }
    return make_tuple(1, cores);
}

int main() {
    int n,m,train1,train2;
    while( cin >> n >> m ){
        vector<vector<int>> adj(n);
        vector<int> cores (n, -1);
        int flag = 0;

        for (int i = 0; i < m ; ++i) {
            cin >> train1 >> train2;
            adj[train1-1].push_back(train2 - 1);
            adj[train2-1].push_back(train1 - 1);
        }

        for (int i = 0; i < n; ++i) {
            if (cores[i] == -1) {
                tuple<int,vector<int>> result = trains(adj, cores, i);
                cores = get<1>(result);
                if (get<0>(result) == 0){
                    flag=1;
                    break;
                }
            }
        }

        if (flag==1) {
            cout << "NO" << endl;
        } else {
            cout << "NOT SURE" << endl;
        }
    }
}