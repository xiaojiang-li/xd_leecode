#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs);
};

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
  vector<vector<string>> res;
  map<vector<int>, vector<string>> smap;
  for (const auto& str : strs) {
    vector<int> s = vector<int>(26, 0);
    // 记录每一个单词的频次
    for (const auto& m : str) s[m - 'a']++;
    // 将相同频次的单词放在同一个键值中
    smap[s].emplace_back(str);
  }
  // 遍历map, 把map中的元素放入vector中
  for (const auto& str : smap) res.emplace_back(str.second);

  return res;
}

int main(int argc, char** argv) {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution s;
  s.groupAnagrams(strs);

  return 0;
}