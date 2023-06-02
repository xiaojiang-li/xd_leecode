#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s) {
  int left = 0;  //
  int right = 0;
  int max_len = 0;
  int n = s.length();
  unordered_set<char> window;

  while (right < n) {
    if (!window.count(s[right])) {
      window.insert(s[right]);
      right++;
      max_len = max(max_len, (int)window.size());
    } else {
      window.erase(s[left]);
      left++;
    }
  }

  return max_len;
}

int main(int argc, char **argv) {
  // string str = "ssssssssssssssss";
  // string str = "abcabcbb";
  string str = "";

  Solution s;
  cout << s.lengthOfLongestSubstring(str) << endl;

  return 0;
}