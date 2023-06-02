/*
 * @Descripttion: 生命游戏
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-06-02 00:20:56
 * @LastEditTime: 2023-06-02 00:46:37
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  // 0 原来是死的, 现在是死的
  // 1 原来是活的, 现在是活的
  // 2 原来是死的, 现在是活的
  // 3 原来是活的, 现在是死的

 public:
  void gameOfLife(vector<vector<int>>& board) {
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        // 规则四
        if (board[i][j] == 0) {
          int x = 0;  // 周围有多少活物
          for (int k = i + 1; k >= i - 1; k--) {
            for (int l = j + 1; l >= j - 1; l--) {
              if (k < row && k >= 0 & l < col && l >= 0 && (i != k || j != l)) {
                x += board[k][l] == 1 || board[k][l] == 3 ? 1 : 0;
              }
            }
          }
          if (x == 3) board[i][j] = 2;
        }

        if (board[i][j] == 1) {
          int x = 0;
          for (int k = i + 1; k >= i - 1; k--) {
            for (int l = j + 1; l >= j - 1; l--) {
              if (k < row && k >= 0 & l < col && l >= 0 && (i != k || j != l)) {
                x += board[k][l] == 1 || board[k][l] == 3 ? 1 : 0;
              }
            }
          }

          // 规则一
          if (x < 2) board[i][j] = 3;
          // 规则二
          if (x == 2 || x == 3) board[i][j] = 1;
          // 规则三
          if (x > 3) board[i][j] = 3;
        }
      }
    }

    // 更新状态
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == 2) board[i][j] = 1;
        if (board[i][j] == 3) board[i][j] = 0;
      }
    }
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> matrix = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  Solution s;
  s.gameOfLife(matrix);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}