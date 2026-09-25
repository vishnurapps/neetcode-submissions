class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                char c = board[i][j];

                if(c == '.'){
                    continue;
                }

                int box_index = (i/3)*3+(j/3);

                if(rows[i].count(c) || columns[j].count(c) || boxes[box_index].count(c)){
                    return false;
                }
                rows[i].insert(c);
                columns[j].insert(c);
                boxes[box_index].insert(c);

            }
        }
        return true;

    }
};
