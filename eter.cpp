#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <bits/stdc++.h>



using namespace std;
std::vector<vector<vector<int>>> board;


void resetVector(int rows,int col){
    board.resize(rows);
    for(int aux = 0;aux<rows;aux++){
        board[aux].resize(col);
        for(int j = 0;j<4;j++){
            board[aux][j].resize(4);
        }
    }

    for(int i = 0;i<rows;i++){
        for(int j = 0;j<rows;j++){
            for(int k = 0;k<4;k++){
                board[i][j][k] = 0;
            }
        }
    }
}


void escreveVector(int rows,int col){
    for(int i = 0;i<rows;i++){
        cout << "==== Linha " << i <<" ====\n";
        for(int j = 0;j<col;j++){
            for(int k = 0;k<4;k++){
                cout << board[i][j][k] <<" ";
            }
            cout << " | ";
        }
        cout << "\n";
    }
}
int main(){
    int num_casos,num_pecas,rows,columns;
    cin >> num_casos;
    for (int i = 0;i<num_casos;i++){
        cin >> num_pecas >> rows >> columns;
        resetVector(rows,columns);
        escreveVector(rows,columns);
    }
   

}
/*
 num_cases = readln()
    #para cada caso de teste
    for i in range(int(num_cases)):
        pecas = []
        n,r,c = readln().split(' ')
        print("=== Caso %d ==="%(i))
        print("=== Numero Pecas %d Rows %d Collumns %d ==="%(int(n),int(r),int(c)))
        //Ler cada peca
        for j in range(int(n)):
            peca = []
            lidos = readln().split(' ')

            for k in range(len(lidos)):
                peca.append(int(lidos[k]))

            //pecas = lista de todas as pecas
            pecas.append(peca)
        
        //cria um tabuleiro de dimensoes r*c
        tabuleiro = []
        for i in range(int(r)):
            aux = []
            for j in range(int(c)):
                aux.append([])
            tabuleiro.append(aux)

        //peca fixa
        tabuleiro[0][0] = pecas[0]
        //chamar a funcao para cada caso
        eternity(tabuleiro,pecas,r,c)*/
//print(insereEsquerda([1,2,3,4],[5,1,4,6]))
//print(insereDireita([1,2,3,4],[2,5,6,3]))
//print(insereCima([1,2,3,4],[6,5,2,1]))
//print(insereBaixo([1,2,3,4],[4,3,5,6]))