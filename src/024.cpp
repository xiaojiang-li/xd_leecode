#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // 生成全是空格的字符串
  string Blank(int n) { return string(n, ' '); }

  // 将空格和单词组合起来
  string Join(const vector<string>& words, int left, int right, string blank) {
    string s = words[left];
    for (int i = left + 1; i < right; ++i) {
      s += blank + words[i];
    }
    return s;
  }

  vector<string> fullJustify(vector<string>& words, int maxWidth);
};

vector<string> Solution::fullJustify(vector<string>& words, int maxWidth) {
  vector<string> ret;
  int right = 0;  // 遍历到了words中的第几个单词
  int n = words.size();

  while (1) {
    int left = right;  // 当前行的第一个单词word中的位置
    int curr_len = 0;  // 当前行长度

    while (right < n &&  // 每多一个单词, 其后面就要加一个空格
           curr_len + words[right].length() + right - left <= maxWidth) {
      curr_len += words[right].length();
      right++;
    }

    // 如果当前行是最后一行, 每个单词间只有一个空格, 行最后用空格填充
    if (right == n) {
      string s = Join(words, left, right, " ");
      ret.emplace_back(s + Blank(maxWidth - s.length()));
      return ret;
    }

    int curr_words = right - left;          // 当前行有多少个单词
    int curr_spaces = maxWidth - curr_len;  // 当前行有多少个空格

    // 如果当前行只有一个单词, 单词左对齐, 用0填充其余部分
    if (curr_words == 1) {
      ret.emplace_back(words[left] + Blank(curr_spaces));
      continue;
    }

    // 当前行有很多单词
    int avg_spaces = curr_spaces / (curr_words - 1);  // 平均每一个空格处空格数
    int ext_spaces = curr_spaces % (curr_words - 1);  // 多少个空格处多一个单词
    string s1 =
        Join(words, left, left + ext_spaces + 1, Blank(avg_spaces + 1));
    string s2 = Join(words, left + ext_spaces + 1, right, Blank(avg_spaces));
    ret.emplace_back(s1 + Blank(avg_spaces) + s2);
  }
}

int main(int argc, char** argv) {
  vector<string> words = {"This", "is",   "an",           "example",
                          "of",   "text", "justification"};
  // vector<string> words = {"a"};
  Solution s;
  for (const auto& m : s.fullJustify(words, 16)) cout << m << endl;
  return 0;
}