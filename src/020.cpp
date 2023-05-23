/*
 * @Descripttion: 找到所有单词的共同前缀
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-20 18:31:53
 * @LastEditTime: 2023-05-20 23:15:54
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ret = "";

    if (strs.size() == 1) return strs[0];

    sort(strs.begin(), strs.end());  // 这个排序结果好好看一下
    // for (const auto &m : strs) {
    //   cout << m << endl;
    // }

    string st = strs.front();
    string en = strs.back();
    int n = min(st.size(), en.size());
    for (int i = 0; i < n; ++i) {
      if (st[i] == en[i]) {
        ret += st[i];
      } else {
        return ret;
      }
    }

    return ret;
  }
};

int main(int argc, char** argv) {
  vector<string> strs = {"flower", "flow", "flight"};
  // vector<string> strs = {"",""};
  // vector<string> strs = {"flower", "flower", "flower", "flower"};
  Solution s;
  cout << s.longestCommonPrefix(strs) << endl;

  return 0;
}