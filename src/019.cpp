/*
 * @Descripttion: 寻找字符串最有一个单词的长度
 * @version: 1.0
 * @Author: Li Xiaodong
 * @Date: 2023-05-20 18:13:45
 * @LastEditTime: 2023-05-20 23:16:17
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    // if (s.length() == 0) return 0;
    // if (s.length() == 1) return s[0] == ' ' ? 0 : 1;

    int n = s.length() - 1;
    while (s[n] == ' ') n--;
    
    int len = 0;
    while (n >= 0 && s[n] != ' ') {
      len++;
      n--;
    }

    return len;
  }
};

int main(int argc, char **argv) {
  // string str = "hello world";
  string str = " ";
  Solution s;
  cout << s.lengthOfLastWord(str) << endl;

  return 0;
}