/**********************************************
* �ļ�����05.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.07
* ��Ŀ��Դ������Ա���Խ��
* ����������01.05.һ�α༭(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int firstLen = first.size(), secondLen = second.size();
        if (firstLen > secondLen) return oneEditAway(second, first);
        int cnt = 0; int ods = 0;
        switch (secondLen-firstLen)
        {
        case 0:
            for (int i = 0; i < firstLen; i++) {
                if (first[i] != second[i])
                    cnt++;
            }
            return cnt <= 1;
            break;
        case 1:
            while (cnt < firstLen) {
                if (first[cnt] != second[cnt + ods]) {
                    if (++ods > 1) return false;
                }
                else
                    cnt++;
            }
            return true;
            break;
        default:
            return false;
            break;
        }
    }
};

int main() {
    Solution sol;
    string first = "a", second = "ab";
    cout << (sol.oneEditAway(first, second) ? "true" : "false");
}