/**********************************************
* �ļ�����04.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.07
* ��Ŀ��Դ������Ա���Խ��
* ����������01.04.��������(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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