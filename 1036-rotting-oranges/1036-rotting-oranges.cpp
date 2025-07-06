class Solution {
public:
  class orange {
  public:
    int row, col, time;
    orange(int row, int col , int time) {
      this->row = row;
      this->col = col;
      this->time = time;
    }
  };

  bool isRotten(int val) {
    return val == 2;
  }
  bool isFresh(int val) {
    return val == 1;
  }
  bool isEmpty(int val) {
    return val == 0;
  }

  bool isValid(int i , int j , int n , int m) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
      return true;
    }
    return false;
  }

  int getMaxTimeToRotting(vector<vector<int>>& grid , queue<orange>rottenOranges , int &freshOranges)
  {
    int maxTime = 0;

    int deltaRow[4] = {1 , 0 , -1 , 0};
    int deltaCol[4] = {0 , -1 , 0 , 1};

    while (!rottenOranges.empty())
    {
      orange currentOrange = rottenOranges.front();
      rottenOranges.pop();
      int currentTime = currentOrange.time;
      maxTime = max(maxTime , currentTime);

      int n = grid.size() , m = grid[0].size();

      for (int direction = 0; direction < 4 ; direction++) {
        int new_row = currentOrange.row + deltaRow[direction];
        int new_col = currentOrange.col + deltaCol[direction];

        if (isValid(new_row , new_col , n , m) && isFresh(grid[new_row][new_col]) ) {
          grid[new_row][new_col] = 2;
          freshOranges--;
          rottenOranges.push(orange(new_row , new_col , currentTime + 1) );
        }
      }
    }
    return maxTime;
  }

  queue<orange> getRottenOranges(vector<vector<int>>& grid , int &freshOranges)
  {
    int n = grid.size() , m = grid[0].size();
    queue<orange>q;
    for (int i = 0 ; i < n; i++) {
      for (int j = 0 ; j < m; j++) {
        if (isRotten(grid[i][j])) {
          q.push(orange(i, j, 0));
        }
        else if (isFresh(grid[i][j])) {
          freshOranges++;
        }
      }
    }
    return q;
  }

  int orangesRotting(vector<vector<int>>& grid) {
    int freshOranges = 0;

    queue<orange>rottenOranges = getRottenOranges(grid , freshOranges);

    int maxTime = getMaxTimeToRotting(grid , rottenOranges , freshOranges);

    if (freshOranges != 0)return -1;

    return maxTime;
  }
};