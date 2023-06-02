/*
 * @Descripttion: 盛水最多的容器
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-23 00:20:12
 * @LastEditTime: 2023-05-23 23:15:22
 */
#include <iostream>
#include <vector>

using namespace std;

int min(int i, int j) { return i < j ? i : j; };
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0;
    int j = n - 1;
    int max_sum_water = (j - i) * min(height[i], height[j]);
    while (i < j) {
      int cur_sum_water = (j - i) * min(height[i], height[j]);
      if (cur_sum_water <= max_sum_water) {
        if (height[i] > height[j]) {
          j--;
        } else {
          i++;
        }
      } else {
        max_sum_water = cur_sum_water;
      }
    }
    return max_sum_water;
  }
};

int main(int argc, char** argv) {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution s;
  cout << s.maxArea(height) << endl;
  return 0;
}