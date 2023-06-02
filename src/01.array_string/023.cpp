/*
 * @Descripttion:
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-21 05:19:32
 * @LastEditTime: 2023-05-21 18:04:56
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle);
  //  private:
  vector<int> GetNext(string needle);
};

// KMP算法
vector<int> Solution::GetNext(string needle) {
  int len = needle.length();
  int prefix_len = 0;
  vector<int> next = vector<int>(len, 0);
  if (len == 1) return next;
  int i = 1;
  while (i < len) {
    if (needle[i] == needle[prefix_len]) {
      prefix_len++;
      next[i] = prefix_len;
      i++;
    } else {
      if (prefix_len == 0) {
        next[i] = prefix_len;
        i++;
      } else {
        prefix_len = next[prefix_len - 1];
      }
    }
  }
  return next;
}

int Solution::strStr(string haystack, string needle) {
  vector<int> next = GetNext(needle);

  int len = haystack.length();
  int i = 0;
  int j = 0;
  while (i < len) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
    } else {
      if (j > 0) {
        j = next[j - 1];
      } else {
        i++;
      }
    }
    if (j == needle.length()) return i - needle.length();
  }
  return -1;
}

int main(int argc, char **argv) {
  string haystack = "aabaaabaaac";
  string needle = "aabaaac";
  Solution s;
  for (const auto &m : s.GetNext(needle)) cout << m << " ";
  cout << endl;
  cout << s.strStr(haystack, needle) << endl;
  return 0;
}