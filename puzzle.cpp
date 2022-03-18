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


bool addRight(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
bool addLeft(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
bool addDown(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
bool addUp(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado,int count,int row,int col);
void geraPrint(std::vector<vector<vector<int>>> input_tabuleiro);

vector<vector<int>> nextPeca(vector<vector<vector<int>>> tabuleiro, vector<int> &peca_usado, int row, int col);

bool checkDireita(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[1] == peca2[0] && peca1[2] == peca2[3]) || peca2[0] == -1){
        return true;
    }
    return false;
}
bool checkEsquerda(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[0] == peca2[1] && peca1[3] == peca2[2]) || peca2[0] == -1){
        return true;
    }
    return false;
}
bool checkCima(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[0] == peca2[3] && peca1[1] == peca2[2]) || peca2[0] == -1){
        return true;
    }
    return false;
}
bool checkBaixo(std::vector<int> peca1, std::vector<int> peca2){
    if((peca1[2] == peca2[1] && peca1[3] == peca2[0]) || peca2[0] == -1){
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

    if(solved){
        return true;
    }

    if(col == (max_col-1) || col < 0){
        return false;
    }
    if(row < 0 || row >= max_rows){
        return false;
    }
    if(input_tabuleiro[row][col+1][0] != -1){
        return false;
    }
    vector<vector<int>> aux_peca = nextPeca(input_tabuleiro, peca_usado, row, col+1);
    
    if(aux_peca[0][0] == -1){
        return false;
    }
    
    vector<int> ini(4,-1);
    for(int i = 0;i<(int)aux_peca.size()/2;i++){
        input_tabuleiro[row][col+1] = aux_peca[i*2];
        peca_usado[aux_peca[i*2+1][0]]=1;
        if(count + 1 == num_pecas){
            solved = 1;
            out_tabuleiro = input_tabuleiro;
        return true;
        }
        addRight(input_tabuleiro,peca_usado,count+1,row,col+1);
        addDown(input_tabuleiro,peca_usado,count+1,row,col+1);
        addUp(input_tabuleiro,peca_usado,count+1,row,col+1);
        peca_usado[aux_peca[i*2+1][0]]=0;
        input_tabuleiro[row+1][col] = ini;
    }
    
    return false;
}

bool addLeft(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado, int count,int row,int col){
    if(solved){
        return true;
    }
    
    if(col == 0 || col >= max_col){
        return false;
    }
    if(row < 0 || row >= max_rows){
        return false;
    }
    if(input_tabuleiro[row][col-1][0] != -1){
        return false;
    }
    vector<vector<int>> aux_peca = nextPeca(input_tabuleiro, peca_usado, row, col-1);
    
    if(aux_peca[0][0] == -1){
        return false;
    }
    vector<int> ini(4,-1);
    for(int i = 0;i<(int)aux_peca.size()/2;i++){
        input_tabuleiro[row][col-1] = aux_peca[i*2];
        peca_usado[aux_peca[i*2+1][0]]=1;
        if(count + 1 == num_pecas){
            solved = 1;
            out_tabuleiro = input_tabuleiro;
        return true;
        }
        addLeft(input_tabuleiro,peca_usado,count+1,row,col-1);
        addUp(input_tabuleiro,peca_usado,count+1,row,col-1);
        addDown(input_tabuleiro,peca_usado,count+1,row,col-1);
        peca_usado[aux_peca[i*2+1][0]]=0;
        input_tabuleiro[row+1][col] = ini;
    }
    
    return false;
}

bool addUp(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado, int count,int row,int col){   
    if(solved){
        return true;
    }
    if(row <= 0 || row > max_rows-1){
        return false;
    }
    if(col < 0 || col >= max_col){
        return false;
    }

    if(input_tabuleiro[row-1][col][0] != -1){
        return false;
    }
    
    vector<vector<int>> aux_peca = nextPeca(input_tabuleiro, peca_usado, row-1, col);
    
    if(aux_peca[0][0] == -1){
        return false;
    }
    vector<int> ini(4,-1);
    for(int i = 0;i<(int)aux_peca.size()/2;i++){
        input_tabuleiro[row-1][col] = aux_peca[i*2];
        peca_usado[aux_peca[i*2+1][0]]=1;
        if(count + 1 == num_pecas){
            solved = 1;
            out_tabuleiro = input_tabuleiro;
        return true;
        }
        addUp(input_tabuleiro,peca_usado,count+1,row-1,col);
        addRight(input_tabuleiro,peca_usado,count+1,row-1,col);
        addLeft(input_tabuleiro,peca_usado,count+1,row-1,col);
        peca_usado[aux_peca[i*2+1][0]]=0;
        input_tabuleiro[row+1][col] = ini;
    }

    return false;
}

bool addDown(std::vector<vector<vector<int>>> input_tabuleiro, vector<int> peca_usado, int count, int row, int col){
    if(solved){
        return true;
    }
    if(row >= max_rows-1 || row < 0){
        return false;
    }
    if(col < 0 || col >= max_col){
        return false;
    }
    if(input_tabuleiro[row+1][col][0] != -1){
        return false;
    }
    vector<vector<int>> aux_peca = nextPeca(input_tabuleiro, peca_usado, row+1, col);
    
    if(aux_peca[0][0] == -1){
        return false;
    }
    vector<int> ini(4,-1);
    for(int i = 0;i<(int)aux_peca.size()/2;i++){
        input_tabuleiro[row+1][col] = aux_peca[i*2];
        peca_usado[aux_peca[i*2+1][0]]=1;
        if(count + 1 == num_pecas){
            solved = 1;
            out_tabuleiro = input_tabuleiro;
        return true;
        }
        addDown(input_tabuleiro,peca_usado,count+1,row+1,col);
        addLeft(input_tabuleiro,peca_usado,count+1,row+1,col);
        addRight(input_tabuleiro,peca_usado,count+1,row+1,col);
        peca_usado[aux_peca[i*2+1][0]]=0;
        input_tabuleiro[row+1][col] = ini;
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

void escreveVector(){
    cout << "\n=== PECAS ===\n";
    for(int i = 0; i < num_pecas ;i++){
        for(int j = 0 ; j < 4 ;j++){
            cout << pecas[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> nextPeca(vector<vector<vector<int>>> tabuleiro, vector<int> &peca_usado, int row, int col){

    vector<vector<int>> tmp;
    int existe = 0;

    for(int i = 0;i<(int)pecas.size();i++){

        //print(tabuleiro[0][0])
        if(peca_usado[i]!=1){
        //verificar que posição no tabuleiro está ocupado
            if(row==0){//[0][:]
                if(col==0){ //[0][0]
                    if(checkBaixo(pecas[i],tabuleiro[row+1][col]) == true && checkDireita(pecas[i],tabuleiro[row][col+1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(pecas[i]);
                        tmp.push_back(indice);
                    }
                }
                else if(col==((int)tabuleiro[0].size()-1)){//[0][FIM]
                    if(checkBaixo(pecas[i],tabuleiro[row+1][col]) == true && checkEsquerda(pecas[i],tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(pecas[i]);
                        tmp.push_back(indice);
                    }
                }
                else if(checkBaixo(pecas[i],tabuleiro[row+1][col]) == true && checkDireita(pecas[i],tabuleiro[row][col+1]) == true && checkEsquerda(pecas[i],tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(pecas[i]);
                        tmp.push_back(indice);
                }
            }

            else if(col==0){//[:][0]
                if(row==(int)tabuleiro.size()-1){//[FIM][0]
                    if(checkCima(pecas[i],tabuleiro[row-1][col])==true && checkDireita(pecas[i],tabuleiro[row][col+1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(pecas[i]);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(pecas[i],tabuleiro[row-1][col])==true && checkDireita(pecas[i],tabuleiro[row][col+1])==true && checkBaixo(pecas[i],tabuleiro[row+1][col])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(pecas[i]);
                    tmp.push_back(indice);
                    }
            }
            else if(row==(int)tabuleiro.size()-1){//[FIM][:]
                if(col==(int)tabuleiro[0].size()-1){//[FIM][FIM]
                    if(checkCima(pecas[i],tabuleiro[row-1][col])==true && checkEsquerda(pecas[i],tabuleiro[row][col-1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(pecas[i]);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(pecas[i],tabuleiro[row-1][col])==true && checkDireita(pecas[i],tabuleiro[row][col+1])==true && checkEsquerda(pecas[i],tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(pecas[i]);
                    tmp.push_back(indice);
                }
            }
            else if(col==(int)tabuleiro[0].size()-1){//[:][FIM]
                if(checkBaixo(pecas[i],tabuleiro[row+1][col])==true && checkCima(pecas[i],tabuleiro[row-1][col]) && checkEsquerda(pecas[i],tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(pecas[i]);
                    tmp.push_back(indice);
                }
            }
            else{
                if(checkBaixo(pecas[i],tabuleiro[row+1][col])==true && checkCima(pecas[i],tabuleiro[row-1][col]) && checkEsquerda(pecas[i],tabuleiro[row][col-1]) && checkDireita(pecas[i],tabuleiro[row][col+1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(pecas[i]);
                    tmp.push_back(indice);
                }
            }

            vector<int> aux = rotate90(pecas[i]);

            if(row==0){//[0][:]
                if(col==0){ //[0][0]
                    if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkDireita(aux,tabuleiro[row][col+1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(col==((int)tabuleiro[0].size()-1)){//[0][FIM]
                    if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkEsquerda(aux,tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkDireita(aux,tabuleiro[row][col+1]) == true && checkEsquerda(aux,tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                }
            }
            else if(col==0){//[:][0]
                if(row==(int)tabuleiro.size()-1){//[FIM][0]
                    if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true && checkBaixo(aux,tabuleiro[row+1][col])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                    }
            }
            else if(row==(int)tabuleiro.size()-1){//[FIM][:]
                if(col==(int)tabuleiro[0].size()-1){//[FIM][FIM]
                    if(checkCima(aux,tabuleiro[row-1][col])==true && checkEsquerda(aux,tabuleiro[row][col-1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true && checkEsquerda(aux,tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }
            else if(col==(int)tabuleiro[0].size()-1){//[:][FIM]
                if(checkBaixo(aux,tabuleiro[row+1][col])==true && checkCima(aux,tabuleiro[row-1][col]) && checkEsquerda(aux,tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }
            else{
                if(checkBaixo(aux,tabuleiro[row+1][col])==true && checkCima(aux,tabuleiro[row-1][col]) && checkEsquerda(aux,tabuleiro[row][col-1]) && checkDireita(aux,tabuleiro[row][col+1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }

            aux = rotate180(pecas[i]);

            if(row==0){//[0][:]
                if(col==0){ //[0][0]
                    if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkDireita(aux,tabuleiro[row][col+1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(col==((int)tabuleiro[0].size()-1)){//[0][FIM]
                    if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkEsquerda(aux,tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkDireita(aux,tabuleiro[row][col+1]) == true && checkEsquerda(aux,tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                }
            }
            else if(col==0){//[:][0]
                if(row==(int)tabuleiro.size()-1){//[FIM][0]
                    if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true && checkBaixo(aux,tabuleiro[row+1][col])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                    }
            }
            else if(row==(int)tabuleiro.size()-1){//[FIM][:]
                if(col==(int)tabuleiro[0].size()-1){//[FIM][FIM]
                    if(checkCima(aux,tabuleiro[row-1][col])==true && checkEsquerda(aux,tabuleiro[row][col-1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true && checkEsquerda(aux,tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);                   

                }
            }
            else if(col==(int)tabuleiro[0].size()-1){//[:][FIM]
                if(checkBaixo(aux,tabuleiro[row+1][col])==true && checkCima(aux,tabuleiro[row-1][col]) && checkEsquerda(aux,tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }
            else{
                if(checkBaixo(aux,tabuleiro[row+1][col])==true && checkCima(aux,tabuleiro[row-1][col]) && checkEsquerda(aux,tabuleiro[row][col-1]) && checkDireita(aux,tabuleiro[row][col+1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }

            aux = rotate270(pecas[i]);

            if(row==0){//[0][:]
                if(col==0){ //[0][0]
                    if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkDireita(aux,tabuleiro[row][col+1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(col==((int)tabuleiro[0].size()-1)){//[0][FIM]
                    if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkEsquerda(aux,tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkBaixo(aux,tabuleiro[row+1][col]) == true && checkDireita(aux,tabuleiro[row][col+1]) == true && checkEsquerda(aux,tabuleiro[row][col-1]) == true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                }
            }
            else if(col==0){//[:][0]
                if(row==(int)tabuleiro.size()-1){//[FIM][0]
                    if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true && checkBaixo(aux,tabuleiro[row+1][col])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                    }
            }
            else if(row==(int)tabuleiro.size()-1){//[FIM][:]
                if(col==(int)tabuleiro[0].size()-1){//[FIM][FIM]
                    if(checkCima(aux,tabuleiro[row-1][col])==true && checkEsquerda(aux,tabuleiro[row][col-1])==true){
                        existe = 1;
                        vector<int> indice(1, i);
                        tmp.push_back(aux);
                        tmp.push_back(indice);
                    }
                }
                else if(checkCima(aux,tabuleiro[row-1][col])==true && checkDireita(aux,tabuleiro[row][col+1])==true && checkEsquerda(aux,tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }
            else if(col==(int)tabuleiro[0].size()-1){//[:][FIM]
                if(checkBaixo(aux,tabuleiro[row+1][col])==true && checkCima(aux,tabuleiro[row-1][col]) && checkEsquerda(aux,tabuleiro[row][col-1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }
            else{
                if(checkBaixo(aux,tabuleiro[row+1][col])==true && checkCima(aux,tabuleiro[row-1][col]) && checkEsquerda(aux,tabuleiro[row][col-1]) && checkDireita(aux,tabuleiro[row][col+1])){
                    existe = 1;
                    vector<int> indice(1, i);
                    tmp.push_back(aux);
                    tmp.push_back(indice);
                }
            }
        }
    }
    if(existe==1)
        return tmp;
    else{
        vector<int> a;
        a.push_back(-1);
        a.push_back(-1);
        a.push_back(-1);
        a.push_back(-1);
        tmp.push_back(a);
        return tmp;
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
        for(int j = 0; j < num_pecas;j++){
            std::cin >> pecas[j][0] >> pecas[j][1] >> pecas[j][2] >> pecas[j][3];
        }
        tabuleiro[0][0] = pecas[0];
        
        addRight(tabuleiro,peca_usado,1,0,0);
        if(solved){
            geraPrint(out_tabuleiro);
        }
        else{
            addDown(tabuleiro,peca_usado,1,0,0);
            if(solved){
                geraPrint(out_tabuleiro);
            }
            else{
                cout << "impossible puzzle!\n";
            }
        }
    }
    return 0;
}