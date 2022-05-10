#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> low;
vector<int> dfs;
vector<int> parent;
vector<vector<int>> network;

void AP(int v){
    cout << "TO_DO\n";
    
    int t = dfs[v];
    low[v] = dfs[v];
    t = t + 1;

    for(int i = 0 ; i<network.size() ; i++){
        for(int j = 1 ; j < network[i].size() ; j++){
            int w = network[i][j];
            int v = network[i][0];
            if(dfs[w] == 0){
                parent[w] = v;
                AP(w);
                low[v] = min(low[v],low[w]);
                if(dfs[v] = 1 && dfs[w] != 2 ){
                    cout << v << " is root";
                }
                if(dfs[v] != 1 && low[w] >= dfs[v] ){
                    cout << v << " is a non-root AP";
                }
            }
            else{
                low[v] = min(low[v],dfs[w]);
                
            }
        }
    }
}

int main(){
    vector<int> vetor_aux;
    int lines,n,aux;
    cin >> lines;

    low.resize(lines);
    dfs.resize(lines);
    parent.resize(lines);

    string lido = "";
    getline(cin,lido);

    for(int k = 0 ; k <= lines ; k++){
        getline(cin,lido);
        if(lido.compare("0") == 0){
            /*cout << "=========\n";
            for(int i = 0 ; i < network.size() ;i++){
                for(int j = 0 ; j < network[i].size() ; j++){
                    cout << network[i][j] << ' ';
                }
                cout << '\n';
            }

            for(int i = 0 ; i < dfs.size() ;i++){
                cout << dfs[i] << ' ';
            }
            cout << '\n';
            for(int i = 0 ; i < low.size() ;i++){
                cout << low[i] << ' ';
            }
            cout << "\n=========\n";
            */
            AP(0);
            network.clear();            
        }
        
        int n = lido.length();
        char linha[n + 1];
        strcpy(linha, lido.c_str());
        char *token = strtok(linha, " ");
        vetor_aux.clear();
    
        while (token != NULL){
            aux = atoi(token);
            vetor_aux.push_back(aux);
            token = strtok(NULL, " ");
        }

        if(vetor_aux.size() > 1)
            network.push_back(vetor_aux);
        
        else{ 
            if(aux > 0){
                dfs.clear();
                low.clear();
                parent.clear();
                dfs.resize(aux);
                low.resize(aux);
                parent.resize(aux);
    
            }
        }
    }
    
}