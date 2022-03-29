#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int museu(int num_pecas,int m,std::vector<int> pecas){
    int i = 0;
    sort(pecas.begin(),pecas.end());
    vector<int> guards;
    //guards[i] = pecas[1] + m;
    guards.push_back(pecas[0]+m);
    for (int j = 1; j < num_pecas; j++){
        if(pecas[j] > guards[i] + m ){
            //guards[i+1] = pecas[j] + m;
            guards.push_back(pecas[j]+m);
            i = i + 1;
        }
    }
    return i+1;
}

int main(){
    int test_cases,num_pecas,m,sol;
    cin >> test_cases;
    for(int i = 0 ; i < test_cases ; i++){
        cin >> num_pecas >> m;
        vector<int> pecas(num_pecas,0);
        for(int j = 0 ; j < num_pecas ; j++){
            cin >> pecas[j];
        }
        sol = museu(num_pecas,m,pecas);
        //for(int x : pecas)
        //    cout << x << ' ';
        //cout << '\n';
        cout << sol << '\n';
    }
    return 0;
}