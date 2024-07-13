/**********************************************
* �ļ�����001.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.02
* ��Ŀ��Դ������Ա���Խ��
* ����������01.01.�ж��ַ��Ƿ�Ψһ(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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