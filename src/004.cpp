#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 1;  // 慢指针, 表示返回的数组大小
    int n = nums.size();
    if (n <= 2) return n;
    for (int j = 2; j < n; ++j) {
      if (nums[i - 1] != nums[j]) {
        ++i;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  Solution s;
  int num = s.removeDuplicates(nums);
  cout << num << endl;
  for (int i = 0; i < num; ++i) {
    cout << nums[i] << " ";
  }
  return 0;
}