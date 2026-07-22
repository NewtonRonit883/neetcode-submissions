class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            unordered_map<char,int> mp;
            for(int j = 0;j<9;j++){
                if (board[i][j]=='.') continue;
                if (!mp[board[i][j]]){
                    mp[board[i][j]] = 1;
                }else{
                    return false;
                }
            }
        }
        for(int i = 0;i<9;i++){
            unordered_map<char,int> mp;
            for(int j = 0;j<9;j++){
                if (board[j][i]=='.') continue;
                if (!mp[board[j][i]]){
                    mp[board[j][i]] = 1;
                }else{
                    return false;
                }
            }
        }   
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                int s = i*3;
                int t = j*3;
                unordered_map<char,int> mp;
                for(int k = s;k<s+3;k++){
                    for(int l = t;l<t+3;l++){
                        if (board[k][l]=='.') continue;
                        if (!mp[board[k][l]]){
                            mp[board[k][l]] = 1;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
