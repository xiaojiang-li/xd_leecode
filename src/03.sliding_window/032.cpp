#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words);
};

vector<int> Solution::findSubstring(string s, vector<string>& words) {
  unordered_map<string, int> diff;
  for (const auto& word : words) {
    if (diff.count(word)) {
      diff[word]++;
    } else {
      diff[word] = 1;
    }
  }

  vector<int> ret;
  unordered_map<string, int> sf;

  int ls = s.length();
  int n = words.size();
  int m = words[0].length();

  int left = 0;
  int right = m * n - 1;

  while (right < ls) {
    for (int i = left; i <= right - m + 1; i += m) {
      string word = s.substr(i, m);
      if (diff.count(word)) {
        if (!sf.count(word)) {
          sf[word] = 1;
        } else {
          sf[word]++;
        }
      }
      if (!diff.count(word) || sf[word] > diff[word]) {
        left++;
        right++;
        break;
      }
      if (i == right - m + 1) {
        ret.emplace_back(left);
        left++;
        right++;
        break;
      }
    }
    sf.clear();
  }

  return ret;
}

int main(int argc, char** argv) {
  // string str = "barfoothefoobarman";
  // vector<string> words = {"foo", "bar"};

  // string str = "goodgoodbestword";
  // vector<string> words = {"word", "good", "best", "good"};

  string str = "a";
  vector<string> words = {"a"};

  Solution s;

  for (const auto& m : s.findSubstring(str, words)) cout << m << " ";
  cout << endl;

  return 0;
}