#include <iostream>
#include <array>
#include <string>
#include <vector>


using namespace std;
std::vector<vector<int>> board;
std::vector<vector<int>> DP;

void resetVector(int rows){
    board.resize(rows);
    DP.resize(rows);
    for(int aux = 0;aux<rows;aux++){
        board[aux].resize(rows);
        DP[aux].resize(rows);
    }

    for(int i = 0;i<rows;i++){
        for(int j = 0;j<rows;j++){
            board[i][j] = 0;
            DP[i][j] = -1;
        }
    }
}


void escreveVector(int rows,int col){
    for(int i = 0;i<rows;i++){
        cout << "==== Linha " << i <<" ====\n";
        for(int j = 0;j<col;j++){
            cout << board[i][j]<<" ";
        }
        cout << "\n";
    }
}

int winter(int x,int y){
    if(DP[x][y] != -1){
        return DP[x][y];
    }
    if(x < 0 || y < 0 || y > x){
        DP[x][y] = 0;
        return DP[x][y];
    }
    if(x == 0 || y == 0){
        DP[x][y] = board[x][y];
        cout << DP[x][y] <<'\n';
        return DP[x][y];
    }
    DP[x][y] = std::max(winter(x-1,y),winter(x-1,y-1)) + board[x][y];
    return DP[x][y];
}

int bottomup(int num_cases){
    DP[0][0] = board[0][0];
    int aux,res = 0;
    for(int i = 1;i<num_cases;i++){
        for(int j = 0;j<i;j++){
            DP[i][j] = std::max(DP[i-1][j],DP[i-1][j-1]) + board[i][j];   
        }
    }
    for(int i = 0;i<num_cases;i++){
        aux = DP[num_cases-1][i];
        if(aux > res){
            res = aux;
        }
    }
    return res;
}
int main(){
    int num_cases,num_rows,value;
    int lido,res = 0;
    cin >> num_cases;
    for(int i = 0;i<num_cases;i++){
        cin >> num_rows;
        resetVector(num_rows);
        cout << "Number of rows: " << num_rows << '\n';
        for(int j = 0;j<num_rows;j++){
            for(int k = 0;k<j+1;k++){
                cin >> lido;
                board[j][k] = lido;
            }
        }

        escreveVector(num_rows,num_rows);

        for(int aux = 0;aux<num_rows;aux++){
            value = winter(num_rows-1,aux);
            cout << "OBTIDO: " << value << '\n';
            if(value > res){
                res = value;
            }
        }
       
        cout << "RESULTADO " << res << '\n';
    }
    
    return 0;
}