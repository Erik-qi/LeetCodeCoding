/**********************************************
* 文件名：03.cpp
* 创建人：qhy
* 创建时间：2024.07.03
* 题目来源：程序员面试金典
* 代码描述：01.03.URL化(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int SpaceCnt = 0;
        for (int i = 0; i < length; ++i) {//计算空格数
            if (S[i] == ' ')
                ++SpaceCnt;
        }

        int NewLen = 2 * SpaceCnt + length;//计算填充后所需要的S.size()
        S.resize(NewLen);//改变S的尺寸
        for (int j = length - 1; j >= 0; --j) {
            if (S[j] == ' ') {
                S[--NewLen] = '0';
                S[--NewLen] = '2';
                S[--NewLen] = '%';
            }
            else {
                S[--NewLen] = S[j];
            }
        }
        return S;
    }
};

int main() {
    Solution sol;
    string S = "ds sdfs afs sdfa dfssf asdf             ";
    int Length = 27;
    cout << sol.replaceSpaces(S, Length);
}