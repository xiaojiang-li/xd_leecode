#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 向右翻转数组
class Solution {
 public:
  void rotate(vector<int>& nums, int k) { Fun2(nums, k); }

  // 两种方法
  // 额外数组
  void Fun1(vector<int>& nums, int k);
  // 翻转整个数组
  void Fun2(vector<int>& nums, int k);
};

void Solution::Fun1(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> rt_nums = nums;  // 这是拷贝构造吗?
  for (int i = 0; i < n; ++i) {
    nums[(i + k) % n] = rt_nums[i];
  }
}

void Solution::Fun2(vector<int>& nums, int k) {
  int n = nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin()+k%n);
  reverse(nums.begin()+k%n, nums.end());
}

int main(int argc, char** argv) {
  // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  vector<int> nums = {1, 2,3};

  Solution s;
  s.Fun2(nums, 3);
  for (const auto& m : nums) {
    cout << m << " ";
  }
  return 0;
}