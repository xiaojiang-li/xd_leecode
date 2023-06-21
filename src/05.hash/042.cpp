#include <iostream>
#include <string>

using namespace std;

#define WORD_SIZE 26

class Solution {
 public:
  bool isAnagram(string s, string t);
};

bool Solution::isAnagram(string s, string t) {
  int map[WORD_SIZE] = {0};

  if (s.length() != t.length()) return false;
  for (int i = 0; i < s.length(); i++) {
    map[s[i] - 'a']++;
    map[t[i] - 'a']--;
  }
  for (int i = 0; i < WORD_SIZE; i++) {
    if (map[i] != 0) return false;
  }
  return true;
}

int main(int argc, char **argv) {
  string s = "anagram";
  string t = "anagraa";

  Solution sol;
  cout << sol.isAnagram(s, t) << endl;
  return 0;
}