#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i, j;
    // i为返回数组的末尾, j为原数组待比较值的头
    for (i = 0, j = 0; j < nums.size(); ++j) {
      if (nums[j] != val) {
        nums[i] = nums[j];
        ++i;
      }
    }
    return i;
  }
};

int main(int argc, char **argv) {
  vector<int> nums =  { 0, 3, 2, 5, 5, 2, 1, 5};
  int val = 5;
  Solution s;
  int n = s.removeElement(nums, val);
  for (int i = 0; i < n; ++i) {
    cout << nums[i] << " ";
  }

  return 0;
}