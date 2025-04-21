class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int x = 0; x < m; ++x){
            for (int y = 0; y < n; ++y){
                if (dfs_word_board(board,word,0,x,y)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs_word_board(vector<vector<char>>& board, string word, int idx, int x, int y) {
        if (board[x][y] == word[idx]){
            // Base case - solved
            if (idx == word.length()-1) return true;

            board[x][y] = '#';

            // Flags for each direction
            bool l = false, r =false, u=false, d=false;
            
            if (x > 0){ // Left
                l = dfs_word_board(board,word,idx+1,x - 1,y);
            }

            if (x + 1 < board.size() ){ // Right
                r = dfs_word_board(board,word,idx+1,x + 1,y);
            }

            if (y > 0){ // Up
                u = dfs_word_board(board,word,idx+1,x,y - 1);
            }

            if (y + 1 < board[0].size() ){ // Down
                d = dfs_word_board(board,word,idx+1,x,y + 1);
            }

            if (l || r || u || d) return true;

            board[x][y] = word[idx];

        }
        return false;
    }
};


// Chk out of bounds
// Looping