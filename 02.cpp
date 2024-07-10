/**********************************************
* 文件名：02.cpp
* 创建人：qhy
* 创建时间：2024.07.03
* 题目来源：程序员面试金典
* 代码描述：01.02.判定是否互为字符重排(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() > 100 || s1.size() < 0 || s2.size() > 100 || s2.size() < 0) return false;
        if (s1.size() != s2.size()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main() 
{
    Solution sol;
    string s1, s2;
    s1 = "abc", s2 = "bca";
    cout << sol.CheckPermutation(s1,s2);
}