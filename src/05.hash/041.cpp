#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool wordPattern(string pattern, string s);
};

bool Solution::wordPattern(string pattern, string s) {
  unordered_map<char, string> pmap;
  unordered_map<string, char> smap;

  int jlen = 0;  // s字符串读取到第几个单词了(单词开始的位置)
  for (int i = 0; i < pattern.length(); i++) {
    if (jlen >= s.length()) return false;  // s中的单词数少于pattern长度
    int j = jlen;
    while (jlen < s.length() && s[jlen] != ' ') jlen++;
    string tmp = s.substr(j, jlen - j);

    if (pmap.count(pattern[i]) && pmap[pattern[i]] != tmp) return false;
    if (smap.count(tmp) && smap[tmp] != pattern[i]) return false;

    pmap[pattern[i]] = tmp;
    smap[tmp] = pattern[i];
    jlen++; // 跳过空格
  }
  return jlen >= s.length();
}

int main(int argc, char **argv) {
  string pattern = "aaaa";
  string s = "dog dog dog dog";

  Solution sol;
  cout << sol.wordPattern(pattern, s) << endl;
  
  return 0;
}