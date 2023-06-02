/*
 * @Descripttion: 最小覆盖子串
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-24 22:54:38
 * @LastEditTime: 2023-05-25 00:16:17
 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t);
};

string Solution::minWindow(string s, string t) {
  unordered_map<char, int> tmap;  // 制作t的哈希表
  for (const auto &m : t) ++tmap[m];

  int left = 0;
  int right = 0;
  int n = s.length();
  int corr_tmap_size = 0;
  unordered_map<char, int> smap;  // 滑窗哈希表
  string ret = s;

  while (right < n) {
    smap[s[right]]++;
    if (tmap.count(s[right]) && tmap[s[right]] >= smap[s[right]])
      corr_tmap_size++;

    while (left < right &&
           (!tmap.count(s[left]) || smap[s[left]] > tmap[s[left]])) {
      smap[s[left]]--;
      left++;
    }

    if (corr_tmap_size == t.length() && right - left + 1 < ret.size())
      ret = s.substr(left, right - left + 1);

    right++;
  }
  return corr_tmap_size == t.length() ? ret : "";
}
int main(int argc, char **argv) {
  // string s = "ADOBECODEBANC";
  // string t = "ABC";
  string s = "ab";
  string t = "b";
  Solution sol;
  cout << sol.minWindow(s, t) << endl;

  return 0;
}