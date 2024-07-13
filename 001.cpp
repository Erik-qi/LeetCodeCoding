/**********************************************
* 文件名：001.cpp
* 创建人：qhy
* 创建时间：2024.07.02
* 题目来源：程序员面试金典
* 代码描述：01.01.判定字符是否唯一(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        if (astr == "")
            return true;
        sort(astr.begin(), astr.end());
        for (int i = 1; i < astr.length(); i++) {
            if (astr[i] == astr[i - 1])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    cout << sol.isUnique(s);
}