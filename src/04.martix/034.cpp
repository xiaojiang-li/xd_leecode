#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board);
};

bool Solution::isValidSudoku(vector<vector<char>>& board) {
  int rows[9][9] = {0};  // 某一行某个元素出现的频数
  int cols[9][9] = {0};
  int boxes[3][3][9] = {0};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int num = board[i][j] - '0' - 1;
        cols[j][num]++;
        rows[i][num]++;
        if (rows[i][num] > 1) return false;
        if (cols[j][num] > 1) return false;

        // 九宫格
        boxes[i / 3][j / 3][num]++;
        if (boxes[i / 3][j / 3][num] > 1) return false;
      }
    }
  }
  return true;
}

int main(int argc, char** argv) {
  vector<vector<char>> board = {
      vector<char>{'7', '.', '.', '4', '.', '.', '.', '.', '.'},
      vector<char>{'.', '.', '.', '8', '6', '5', '.', '.', '.'},
      vector<char>{'.', '1', '.', '2', '.', '.', '.', '.', '.'},
      vector<char>{'.', '.', '.', '.', '.', '9', '.', '.', '.'},
      vector<char>{'.', '.', '.', '.', '4', '.', '5', '.', '.'},
      vector<char>{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'.', '.', '.', '.', '.', '.', '2', '.', '.'},
      vector<char>{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      vector<char>{'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
  Solution s;
  cout << s.isValidSudoku(board) << endl;

  return 0;
}