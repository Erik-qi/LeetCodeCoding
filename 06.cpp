/**********************************************
* �ļ�����06.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.11
* ��Ŀ��Դ������Ա���Խ��
* ����������01.06.�ַ���ѹ��(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        if (S.size() <= 1) return S;
        int first = 0, last = 1;
        string outS = "";
        while (first <= S.size() - 1) {
            if (S[first] != S[last]) {
                outS += (S[first] + to_string(last - first));
                first = last;
                last = first + 1;
            }
            else {
                if (++last > (S.size() - 1)) {
                    outS += (S[first] + to_string(last - first));
                    break;
                }
            }
        }
        return outS.size() < S.size() ? outS : S;
    }
};

int main() {
    Solution sol;
    string S = "bbbac";
    cout << sol.compressString(S);
}