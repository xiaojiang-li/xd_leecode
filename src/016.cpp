/*
 * @Descripttion: 3种接雨水的方法
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-19 21:11:23
 * @LastEditTime: 2023-05-20 23:17:35
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) { return Fun3(height); }

 private:
  // 暴力法
  int Fun1(vector<int>& height);
  // 记事本法
  int Fun2(vector<int>& height);
  // 双指针法
  int Fun3(vector<int>& height);
};

int min(int x, int y) { return x < y ? x : y; }

int Solution::Fun1(vector<int>& height) {
  int rain = 0;
  int n = height.size();

  if (n == 1 || n == 2) return 0;

  // int left_max = height[0];
  // int right_max = height[2];

  for (int i = 1; i < n - 1; i++) {
    int left_max = 0;
    int right_max = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (height[j] > left_max) left_max = height[j];
    }
    for (int j = i + 1; j < n; j++) {
      if (height[j] > right_max) right_max = height[j];
    }
    if (left_max > height[i] && right_max > height[i])
      rain += min(left_max, right_max) - height[i];
  }

  return rain;
}

int Solution::Fun2(vector<int>& height) {
  int rain = 0;
  int n = height.size();

  vector<int> left_max(n, 0);
  vector<int> right_max(n, 0);

  left_max[0] = height[0];
  right_max[n - 1] = height[n - 1];

  for (int i = 1; i < n; i++) {
    left_max[i] = height[i] > left_max[i - 1] ? height[i] : left_max[i - 1];
  }
  // for (const auto& m : left_max) cout << m << " ";
  // cout << endl;

  for (int i = n - 2; i >= 0; i--) {
    right_max[i] = height[i] > right_max[i + 1] ? height[i] : right_max[i + 1];
  }
  // for (const auto& m : right_max) cout << m << " ";
  // cout << endl;

  for (int i = 1; i < n - 1; ++i) {
    if (left_max[i] > height[i] && right_max[i] > height[i])
      rain += min(left_max[i], right_max[i]) - height[i];
  }

  return rain;
}

int Solution::Fun3(vector<int>& height) {
  int rain = 0;
  int n = height.size();

  int left_max = height[0];
  int right_max = height[n - 1];

  int left = 0;
  int right = n - 1;

  while (left < right) {
    left_max = height[left] > left_max ? height[left] : left_max;
    right_max = height[right] > right_max ? height[right] : right_max;

    if (left_max < right_max) {
      rain += left_max - height[left];
      left++;
    } else {
      rain += right_max - height[right];
      right--;
    }
  }

  return rain;
}

int main(int argc, char** argv) {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> height = {4, 2, 0, 3, 2, 5};
  Solution s;
  cout << s.trap(height) << endl;

  return 0;
}