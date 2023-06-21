#include <limits.h>

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    set<int> set;
    for (const auto& i : nums) set.insert(i);
    int cur_size = 0;
    int cur_num = INT_MAX;
    int longest_size = 0;
    // 有一个bug, 如果nums里面只有一个值, 且该值为INT_MAX, 该函数返回0(应该返回1)
    for (const auto& m : set) {
      if (!set.count(m - 1) && m != cur_num) {
        int num = m;
        cur_size = 1;
        while (set.count(num + 1)) {
          cur_size++;
          num++;
        }
        cur_num = m;
        longest_size = max(longest_size, cur_size);
      }
    }

    return longest_size;
  }
};

int main(int argc, char** argv) {
  vector<int> nums = {INT_MAX};

  Solution sol;
  cout << sol.longestConsecutive(nums) << endl;  ///

  return 0;
}
