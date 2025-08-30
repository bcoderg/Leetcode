
class Solution {
public:
    bool check(vector<vector<char>>& v , int row , int col, char num)
    {
        for (int i = 0; i < 9; ++i) {
            if (v[row][i] == num)return false; //check val in row

            if (v[i][col] == num)return false; //check val in col

            int boxRow = 3 * (row / 3) + i / 3; //i/3 row offset in 3*3
            int boxCol = 3 * (col / 3) + i % 3; //i%3 col offset in 3*3

            if (v[boxRow][boxCol] == num)return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& v) {

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j] == '.') {
                    for (char num = '1' ; num <= '9'; num++) {
                        if (check(v , i , j , num)) {
                            v[i][j] = num;
                            bool isValid = solve(v);//checks for remaining sudoku board

                            if (isValid) {
                                return true;//if invalid state, false
                            }

                            v[i][j] = '.';//backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};