#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    queue<int> que;
    int sum_que = 0;
    int min_size = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      que.push(nums[i]);
      sum_que += nums[i];

      while (sum_que >= target) {
        if (que.size() < min_size) min_size = que.size();
        if (sum_que - que.front() >= target) {
          sum_que -= que.front();
          que.pop();
        } else {
          break;
        }
      }
    }
    return sum_que >= target ? min_size : 0;
  }
};

int main(int argc, char** argv) {
  // vector<int> nums = {2, 3, 1, 1, 1, 1, 1};
  // vector<int> nums = {5, 5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
  vector<int> nums = {1, 2, 3, 4, 5};
  Solution s;
  cout << s.minSubArrayLen(15, nums) << endl;
  return 0;
}