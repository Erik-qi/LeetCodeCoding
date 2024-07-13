/**********************************************
* �ļ�����009.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.13
* ��Ŀ��Դ������Ա���Խ��
* ����������01.09.�ַ�����ת
* ���Ӷȷ�����(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {/*��s1+s1��Ѱ��s2������Ҳ�����Ϊ-1*/
        return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;;
    }
};

int main() {
    Solution sol;
    string s1 = "abcd", s2 = "acdb";
    cout << (sol.isFlipedString(s1, s2) ? "true" : "false");
    //cout << (s1+s1).find(s2);
}