/**********************************************
* 文件名：009.cpp
* 创建人：qhy
* 创建时间：2024.07.13
* 题目来源：程序员面试金典
* 代码描述：01.09.字符串轮转
* 复杂度分析：(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {/*在s1+s1中寻找s2，如果找不到则为-1*/
        return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;;
    }
};

int main() {
    Solution sol;
    string s1 = "abcd", s2 = "acdb";
    cout << (sol.isFlipedString(s1, s2) ? "true" : "false");
    //cout << (s1+s1).find(s2);
}