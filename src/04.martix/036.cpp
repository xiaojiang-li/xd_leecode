/*
 * @Descripttion: 旋转矩阵
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-06-01 22:59:07
 * @LastEditTime: 2023-06-02 00:02:27
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> tmp = vector<int>(n, 0);
    for (int i = 0; i < n / 2; ++i) {
      tmp = matrix[i];
      matrix[i] = matrix[n-i-1];
      matrix[n-i-1] = tmp;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        int m = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = m;
      }
    }
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  s.rotate(matrix);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.size(); ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}