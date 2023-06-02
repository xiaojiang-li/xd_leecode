#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> row_zero = vector<int>(row, 0);
    vector<int> col_zero = vector<int>(col, 0);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          row_zero[i] = 1;
          col_zero[j] = 1;
        }
      }
    }
    for (int i = 0; i < row; i++) {
      if (row_zero[i] == 1) matrix[i] = vector<int>(col, 0);
    }
    for (int i = 0; i < col; i++) {
      if (col_zero[i] == 1) {
        for (int j = 0; j < row; j++) {
          matrix[j][i] = 0;
        }
      }
    }
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  Solution s;
  s.setZeroes(matrix);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}