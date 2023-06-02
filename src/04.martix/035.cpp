#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> ret;
    int top = 0;
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;
    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; ++i) {
        ret.push_back(matrix[top][i]);
      }
      for (int i = top + 1; i <= bottom; ++i) {
        ret.push_back(matrix[i][right]);
      }
      if (left < right && top < bottom) {
        for (int i = right - 1; i > left; --i) {
          ret.push_back(matrix[bottom][i]);
        }
        for (int i = bottom; i > top; --i) {
          ret.push_back(matrix[i][left]);
        }
      }
      top++;
      bottom--;
      left++;
      right--;
    }
    return ret;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> matrix = {vector<int>{1, 2, 3, 4},
                                vector<int>{5, 6, 7, 8},
                                vector<int>{9, 10, 11, 12}};
  Solution s;
  for (const auto& m : s.spiralOrder(matrix)) cout << m << " ";
  cout << endl;
  return 0;
}