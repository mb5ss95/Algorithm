#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int move_num = moves.size();
    int board_num = board.size();
    int row_size[30] = {0,};
    vector <int> col_size(30);
    int col = 0;
    int row = 0;
    int temp = 0;

   
    
    for(int i=0; i<board_num; i++){
        for(int j=0; j<board_num; j++){
            if(board[i][j]>0){
                row_size[j]++;
            }
        }
    }
    
    for(int i=0; i<move_num; i++){
        temp = moves[i] -1;
        if(moves[i] && row_size[temp]){
            col = temp;
            row = board_num - row_size[temp];
            
            if(col_size.back() == board[row][col]){
                answer++;
                col_size.pop_back();
            }
            else{
                col_size.push_back(board[row][col]);
            }
            row_size[temp]--;
        } 
    }
    
    return answer*2;
}