#include <iostream>
#include <array>
#include <string>
#include <vector>


using namespace std;
int board [400][400];

int chess(int x,int y,int m){
    int v = 0;
    if(board[x+200][y+200] == 0){
        v = 1;
        board[x+200][y+200] = 1;
    }
    if(m == 0)
        return v;
    else{
        return v + chess(x+2,y+1,m-1)
                 + chess(x+2,y-1,m-1)
                 + chess(x-2,y+1,m-1)
                 + chess(x-2,y-1,m-1)
                 + chess(x+1,y+2,m-1)
                 + chess(x+1,y-2,m-1)
                 + chess(x-1,y+2,m-1)
                 + chess(x-1,y-2,m-1);
    }
}

int main(){
    int numKnights,x,y,m,count = 0;;
    cin >> numKnights;
    for(int i = 0;i<numKnights;i++){
        cin >> x >> y >> m;
        count+=chess(x,y,m);
    }
    cout << count <<endl;
    return 0;
}