#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) { return Fun1(nums); }

  int Fun1(vector<int>& nums);
};

int max(int i, int j) { return i > j ? i : j; }

int Solution::Fun1(vector<int>& nums) {
  int step = 0;
  int max_pos = 0;
  int end = 0;  // 当前可以跳到哪里
  for (int i = 0; i < nums.size() - 1; ++i) {
    if (max_pos >= i) {
      max_pos = max(max_pos, i + nums[i]);  //
      if (end == i) {
        end = max_pos;
        step++;
      }
    }
  }
  return step;
}

int main(int argc, char** argv) {
  vector<int> nums = {1, 1, 1, 1, 1, 1};
  Solution s;
  cout << s.jump(nums) << endl;

  return 0;
}