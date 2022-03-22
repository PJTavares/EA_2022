#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
std::vector<vector<vector<int>>> tabuleiro;
std::vector<vector<vector<int>>> out_tabuleiro;
std::vector<vector<vector<int>>> aux_tabuleiro;
std::vector<vector<int>> pecas;
std::vector<int> pecas_usadas;
std::vector<int> aux_peca;
std::vector<int> peca_error;
int num_cases,num_pecas,max_rows,max_col,solved;
bool cima = true;
/*
201888018_2018280970
Cb5Ps0
*/
bool addRight(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
bool addLeft(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
bool addDown(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
bool addUp(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
void geraPrint(std::vector<vector<vector<int>>> input_tabuleiro);

vector<vector<int>> nextPeca(vector<vector<vector<int>>> tabuleiro, vector<int> &peca_usado, int row, int col);

bool checkDireita(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[1] == peca2[0] && peca1[2] == peca2[3]) || peca1[0] == -1){
        return true;
    }
    return false;
}
bool checkEsquerda(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[0] == peca2[1] && peca1[3] == peca2[2]) || peca1[0] == -1){
        return true;
    }
    return false;
}
bool checkCima(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[0] == peca2[3] && peca1[1] == peca2[2]) || peca1[0] == -1){
        return true;
    }
    return false;
}
bool checkBaixo(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[2] == peca2[1] && peca1[3] == peca2[0]) || peca1[0] == -1){
        return true;
    }
    return false;
}

vector<int> rotate90(std::vector<int> peca){
    aux_peca [0] = peca[3];
    aux_peca [1] = peca[0];
    aux_peca [2] = peca[1];
    aux_peca [3] = peca[2];
    return aux_peca;
}

vector<int> rotate180(std::vector<int> peca){
    aux_peca [0] = peca[2];
    aux_peca [1] = peca[3];
    aux_peca [2] = peca[0];
    aux_peca [3] = peca[1];
    return aux_peca;
}
vector<int> rotate270(std::vector<int> peca){
    aux_peca [0] = peca[1];
    aux_peca [1] = peca[2];
    aux_peca [2] = peca[3];
    aux_peca [3] = peca[0];
    return aux_peca;
}

vector<int> chosseRight(std::vector<int> peca1,std::vector<int> peca2){
    if (checkDireita(peca1,peca2)){
        return peca2;
    }
    aux_peca = rotate90(peca2);
    if(checkDireita(peca1,aux_peca)) {
        return aux_peca;
    }
    aux_peca = rotate180(peca2);
    if(checkDireita(peca1,aux_peca)){
        return aux_peca;
    }
    aux_peca = rotate270(peca2);
    if( checkDireita(peca1,aux_peca)){
        return aux_peca;
    }
    return peca_error;
}

vector<int> chosseLeft(std::vector<int> peca1,std::vector<int> peca2){
    if (checkEsquerda(peca1,peca2)){
        return peca2;
    }
    aux_peca = rotate90(peca2);
    if(checkEsquerda(peca1,aux_peca)) {
        return aux_peca;
    }

    aux_peca = rotate180(peca2);
    if( checkEsquerda(peca1,aux_peca)){
        return aux_peca;
    }
    aux_peca = rotate270(peca2);
    if( checkEsquerda(peca1,aux_peca)){
        return aux_peca;
    }
    return peca_error;
}

vector<int> chosseDown(std::vector<int> peca1,std::vector<int> peca2){
    if (checkBaixo(peca1,peca2)){
        return peca2;
    }
    aux_peca = rotate90(peca2);
    if(checkBaixo(peca1,aux_peca)) {
        return aux_peca;
    }
    aux_peca = rotate180(peca2);
    if( checkBaixo(peca1,aux_peca)){
        return aux_peca;
    }
    aux_peca = rotate270(peca2);
    if( checkBaixo(peca1,aux_peca)){
        return aux_peca;
    }
    return peca_error;
}

vector<int> chosseUp(std::vector<int> peca1,std::vector<int> peca2){
    if (checkCima(peca1,peca2)){
        return peca2;
    }
    aux_peca = rotate90(peca2);
    if(checkCima(peca1,aux_peca)) {
        return aux_peca;
    }
    aux_peca = rotate180(peca2);
    if( checkCima(peca1,aux_peca)){
        return aux_peca;
    }
    aux_peca = rotate270(peca2);
    if( checkCima(peca1,aux_peca)){
        return aux_peca;
    }
    return peca_error;
}

bool addRight(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado, int count,int row,int col){
    //geraPrint(input_tabuleiro);
    
    if(solved){
        //cout << "ENCOTROU DIREITA\n";
        return true;
    }
    if(count == num_pecas){
        //cout << "SOLVED\n";
        //geraPrint(input_tabuleiro);
        solved = 1;
        out_tabuleiro = input_tabuleiro;
        return true;
    }
    if(col>= max_col-1){
        //geraPrint(input_tabuleiro);
        //ESTAVA COL
        //cout << "CASO EXTREMO MAXIMO\n";
        addDown(input_tabuleiro,peca_usado,count,row,col);
    }
    if(col == (max_col) || col < 0){
        return false;
    }
    if(row < 0 || row >= max_rows){
        return false;
    }
    for(int i = 1;i<num_pecas && solved == 0;i++){
        if(peca_usado[i] == 0 && solved == 0){
            aux_peca = chosseRight(input_tabuleiro[row][col],pecas[i]);
            /*if(row != 0){
                //geraPrint(input_tabuleiro);
                cima = checkCima(aux_peca,input_tabuleiro[row-1][col+1]);
                //cout << "======\n";
                //cout << "PECA CIMA" << input_tabuleiro[row-1][col+1][0] << " " << input_tabuleiro[row-1][col+1][1] << " " << input_tabuleiro[row-1][col+1][2] << " " << input_tabuleiro[row-1][col+1][3] << "\n";
                //cout << "POSSIVEL PECA " << aux_peca[0] << " " << aux_peca[1] << " " << aux_peca[2] << " " << aux_peca[3] << "\n";
                //cout << "======\n";
                cima = true;
            }*/
            if(aux_peca[0] != -1 && peca_usado[i] == 0 && solved == 0 && cima){
                input_tabuleiro[row][col+1] = aux_peca;
                //geraPrint(input_tabuleiro);
                peca_usado[i] = 1;
                addRight(input_tabuleiro,peca_usado,count+1,row,col+1);
                peca_usado[i] = 0;
            }
        }
    }
    
    return false;
}

bool addLeft(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado, int count,int row,int col){
    if(solved){
        //cout << "ENCOTROU ESQUERDA\n";
        return true;
    }
    if(count == num_pecas){
        solved = 1;
        //cout << "ENCOTROU SOLUCAO\n";
        //geraPrint(input_tabuleiro);
        out_tabuleiro = input_tabuleiro;
        return true;
    }

    if(col == 0){
        //cout << "ERROU BOI\n";
        addDown(input_tabuleiro,peca_usado,count,row,col);
    }
    
    if(col < 0 || col >= max_col){
        return false;
    }
    if(row < 0 || row >= max_rows){
        return false;
    }
    if(input_tabuleiro[row][col-1][0] != -1){
        return false;
    }
    
    for(int i = 1;i<num_pecas && solved == 0;i++){
        if(peca_usado[i] == 0 && solved == 0){
            aux_peca = chosseLeft(input_tabuleiro[row][col],pecas[i]);
            //cout << "POSSIVEL PECA " << aux_peca[0] << " " << aux_peca[1] << " " << aux_peca[2] << " " << aux_peca[3] << "\n";
            /*if(row != 0){
                cima = checkCima(aux_peca,input_tabuleiro[row-1][col-1]);
                cima = true;
            }*/
            if((aux_peca[0] != -1) && (peca_usado[i] == 0) && (solved == 0) && cima){
                input_tabuleiro[row][col-1] = aux_peca;
                peca_usado[i] = 1;
                addLeft(input_tabuleiro,peca_usado,count+1,row,col-1);
                peca_usado[i] = 0;
            }
        }
    }
    //cout << "PESSOU ESQUERDA " << solved <<"\n";
    return false;
}

bool addDown(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado, int count, int row, int col){
    //geraPrint(input_tabuleiro);
    if(solved){
        //cout << "ENCOTROU BAIXO\n";
        return true;
    }
    if(count == num_pecas){
        solved = 1;
        //cout << "SOLVED\n";
        //geraPrint(input_tabuleiro);
        out_tabuleiro = input_tabuleiro;
        return true;
    }
    if(row >= max_rows || row < 0){
        return false;
    }
    if(col < 0 || col >= max_col){
        return false;
    }
    for(int i = 1;i<num_pecas;i++){
        if((peca_usado[i] == 0) && (solved == 0)){
            aux_peca = chosseDown(input_tabuleiro[row][col],pecas[i]);
            if((aux_peca[0] != -1) && (solved == 0)){
                input_tabuleiro[row+1][col] = aux_peca;
                peca_usado[i] = 1;
                if(col == 0 && solved == 0){
                    //cout << "EXTREMIDADE DIREITA\n";
                    addRight(input_tabuleiro,peca_usado,count+1,row+1,col);
                }
                if(col == max_col-1 && solved == 0){
                    //cout << "EXTREMIDADE ESQUERDA\n";
                    addLeft(input_tabuleiro,peca_usado,count+1,row+1,col);
                }
                peca_usado[i] = 0;
            }
        }
    }
    return false;
}

void geraPrint(std::vector<vector<vector<int>>> input_tabuleiro){
    for (int i = 0 ; i < max_rows -1 ; i++){
        for (int j = 0 ; j < max_col -1 ; j++){
            cout << input_tabuleiro[i][j][0] << " " << input_tabuleiro[i][j][1] << "  ";
        }
        cout <<input_tabuleiro[i][max_col-1][0] << " " << input_tabuleiro[i][max_col-1][1] << '\n';

        for (int j = 0 ; j < max_col -1 ; j++){
            cout << input_tabuleiro[i][j][3] << " " << input_tabuleiro[i][j][2] << "  ";
        }
        cout << input_tabuleiro[i][max_col-1][3] << " " << input_tabuleiro[i][max_col-1][2] << "\n\n";
            
    }

    for (int j = 0 ; j < max_col -1 ; j++){
        cout << input_tabuleiro[max_rows-1][j][0] << " " << input_tabuleiro[max_rows-1][j][1] << "  ";
    }
    cout << input_tabuleiro[max_rows-1][max_col-1][0] << " " << input_tabuleiro[max_rows-1][max_col-1][1] << '\n';
    
    for (int j = 0 ; j < max_col -1 ; j++){
        cout << input_tabuleiro[max_rows-1][j][3] << " " << input_tabuleiro[max_rows-1][j][2] << "  ";
    }
    cout << input_tabuleiro[max_rows-1][max_col-1][3] << " " << input_tabuleiro[max_rows-1][max_col-1][2]<<'\n';
}

void resetVector(){
    tabuleiro.resize(max_rows);
    pecas.resize(num_pecas);
    pecas_usadas.resize(num_pecas);
    aux_peca.resize(4);
    peca_error.resize(4);

    for(int aux = 0;aux<max_rows;aux++){
        tabuleiro[aux].resize(max_col);
        for(int k = 0 ; k < max_col ; k++){
            tabuleiro[aux][k].resize(4);
        }
    }

    for(int i = 0 ; i < num_pecas ; i++){
        pecas[i].resize(4);
        pecas_usadas[i] = 0;
        for(int j = 0 ; j < 4 ; j++){
            pecas[i][j] = -1;
        }
    }
    for(int i = 0 ;i < max_rows ;i++){
        for(int j = 0 ; j < max_col ; j++){
            for(int k = 0 ; k < 4 ; k++){
                tabuleiro[i][j][k] = -1;
            }
        }
    }
    for(int j = 0 ; j < 4 ; j++){
        aux_peca[j] = -1;
        peca_error[j] = -1;
        
    }
}

int main(){
    std::cin >> num_cases;

    for(int i = 0;i<num_cases;i++){
        std::cin >> num_pecas >> max_rows >> max_col;
        vector<int> peca_usado(num_pecas,0);
        peca_usado[0] = 1;
        solved = 0;
        resetVector();
        vector<int> cores(1000,0);
        for(int j = 0; j < num_pecas;j++){
            std::cin >> pecas[j][0] >> pecas[j][1] >> pecas[j][2] >> pecas[j][3];
            cores[pecas[j][0]]++;
            cores[pecas[j][1]]++;
            cores[pecas[j][2]]++;
            cores[pecas[j][3]]++;
        }
        int count = 0;
        for(int i = 0 ; i < 1000 ; i++){
            if(cores[i] % 2 == 1){
                count++;
            }
        }
        
        if(count > 4){
            cout << "impossible puzzle!\n";
        }
        else{
            tabuleiro[0][0] = pecas[0];
            pecas_usadas[0] = 1;
            addRight(tabuleiro,peca_usado,1,0,0);
            if(solved){
                geraPrint(out_tabuleiro);
            }
            
            else{
                cout << "impossible puzzle!\n";
            }
        }
        cout << "FUCK OFF NEXT CASE\n";
        //geraPrint(out_tabuleiro);
        
    }
    return 0;
}