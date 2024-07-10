/**********************************************
* 文件名：04.cpp
* 创建人：qhy
* 创建时间：2024.07.07
* 题目来源：程序员面试金典
* 代码描述：01.04.回文排列(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dic;
        for (char str : s) {
            dic[str] += 1;
        }

        int OddCnt = 0;
        for (auto pair : dic) {
            if (pair.second % 2 == 1) {
                if (++OddCnt > 1)
                    return false;
            }
        }

        return true;
    }
};

int main() 
{
    Solution sol;
    string s = "tactcoa";
    cout << (sol.canPermutePalindrome(s) ? "true" : "false");
}