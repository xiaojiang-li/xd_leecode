#include <iostream>
#include <vector>
using namespace std;

static int sNumSize = 0;

// 找出出现次数最多的元素
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sNumSize = nums.size();
    return Fun2(nums);
  }

  // 能做这道题的所有方式
  // 1 排序法, 归并排序. 时间复杂度为nlogn, 与题不符合
  int Fun1(vector<int>& nums);
  // 2 投票法
  int Fun2(vector<int>& nums);
};

void Merge(const vector<int>& tr, vector<int>& sr, int s, int m, int t) {
  int i, j, k;
  for (i = s, j = m + 1, k = i; i <= m && j <= t; ++k) {
    if (tr[i] < tr[j]) {
      sr[k] = tr[i];
      ++i;
    } else {
      sr[k] = tr[j];
      ++j;
    }
  }
  if (i <= m) {
    for (int l = 0; l <= m - i; ++l) {
      sr[k + l] = tr[i + l];
    }
  }
  if (j <= t) {
    for (int l = 0; l <= t - j; ++l) {
      sr[k + l] = tr[j + l];
    }
  }
}

void Divide(const vector<int>& tr, vector<int>& sr, int s, int t) {
  if (s == t) {
    sr[s] = tr[s];
    return;
  }
  int m = (s + t) / 2;
  vector<int> sr2(sNumSize);
  Divide(tr, sr2, s, m);
  Divide(tr, sr2, m + 1, t);
  Merge(sr2, sr, s, m, t);
  return;
}

int Solution::Fun1(vector<int>& nums) {
  Divide(nums, nums, 0, nums.size() - 1);
  return nums[sNumSize / 2];
}

int Solution::Fun2(vector<int>& nums) {
  int candidate = 0;  // 众数候选人
  int count = 0;      // 候选人所占票数
  for (const auto& m : nums) {
    if (count == 0) {
      candidate = m;
      count++;
      continue;
    }
    if (candidate == m) {
      count++;
    } else {
      count--;
    }
  }
  return candidate;
}

int main(int argc, char* argv[]) {
  vector<int> nums = {1, 3, 2, 6, 5, 4, 9, 7, 8};
  Solution s;
  cout << s.majorityElement(nums) << endl;
  for (int i = 0; i < nums.size(); ++i) {
    cout << nums[i] << " ";
  }
  return 0;
}