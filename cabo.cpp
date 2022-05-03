#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stdio.h>
#include <math.h>
using namespace std;


vector<vector<int>> pos_nos;
vector<vector<int>> liga_nos;
vector<int> set;
vector<int> rank_vec;

vector<int> aux;


void make_set(){
    for(int i = 0 ; i < rank_vec.size() ; i++){
        set[i] = i;
        rank_vec[i] = 0;
    }
}

int find(int a){
    if(set[a] != a){
        set[a] = find(set[a]);
    }
    return set[a];
}

void link_func(int a,int b){
    if(rank_vec[a] > rank_vec[b]){
        set[b] = a;
    }
    else{
        set[a] = b;
    }
    if(rank_vec[a] == rank_vec[b]){
        rank_vec[b]++;
    }
}
void union_func(int a,int b){
    link_func(find(a),find(b));
}
double euc_dist(int x1, int x2, int y1, int y2){
    return (double)sqrt(fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2));
}


vector<int> Kruskal(){
    vector<int> T;
    make_set();

    for(int i = 0 ; i < liga_nos.size() ; i++){
        if(find(liga_nos[i][0]) != find(liga_nos[i][1])){
            T.push_back(liga_nos[i][0]);
            T.push_back(liga_nos[i][1]);
            union_func(liga_nos[i][0],liga_nos[i][1]);
        }
    }
    return T;
}

int main(){
    int num_nos,num_liga,x_pos,y_pos;
    while(!std::cin.eof()){
        cin >> num_nos;
        for(int i = 0 ; i < num_nos ; i++){
            cin >> x_pos >> y_pos;
            aux.push_back(x_pos);
            aux.push_back(y_pos);
            pos_nos.push_back(aux);
            aux.clear();
        }

        rank_vec.resize(num_nos);
        set.resize(num_nos);

        cin >> num_liga;
        for(int j = 0 ; j < num_liga ; j++){
            cin >> x_pos >> y_pos;
            aux.push_back(x_pos-1);
            aux.push_back(y_pos-1);
            liga_nos.push_back(aux);
            aux.clear(); 
        }

        cout << "=== TESTING ===\n";
        cout << num_nos << '\n';
        for(int i = 0 ; i < pos_nos.size() ; i++){
            cout << pos_nos[i][0] << ' ' << pos_nos[i][1] << '\n';
        }
        cout << num_liga << '\n';
        for(int i = 0 ; i < liga_nos.size() ; i++){
            cout << liga_nos[i][0] << ' ' << liga_nos[i][1] << '\n';
        }       
        cout << "===============\n";

        
        vector<int> output = Kruskal();
        cout << "RESULT: ";
        for(int i = 0 ; i < output.size() ; i++){
            cout << output[i] << ' ';
        }
        cout << '\n';

        
        pos_nos.clear();
        liga_nos.clear();       
    }

}