/*
 * @Descripttion: 反转字符串中的单词
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-20 19:26:33
 * @LastEditTime: 2023-05-21 00:02:42
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    // 删除首尾的空格
    int left = 0, right = s.length() - 1;
    while (left <= right && s[left] == ' ') left++;
    while (left <= right && s[right] == ' ') right--;

    string ret = "";
    while (left <= right) {
      string word = "";
      while (left <= right && s[right] != ' ') {
        word += s[right];
        right--;
      }

      int space_len = 0;
      while (left <= right && s[right] == ' ') {
        right--;
      }

      for (int i = word.length() - 1; i >= 0; i--) {
        ret += word[i];
      }
      if (left <= right) ret += ' ';
    }
    return ret;
  }
};

int main(int argc, char **argv) {
  // string str = "hello world";
  string str = "the sky is  blue";
  Solution s;
  cout << s.reverseWords(str) << endl;

  return 0;
}