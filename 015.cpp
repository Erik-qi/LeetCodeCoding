/**********************************************
* �ļ�����015.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.22
* ��Ŀ��Դ������Ա���Խ��
* ����������02.06.��������(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec{};
        while (head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
            if (vec[i] != vec[j])
                return false;
        }

        return true;
    }
};

int main() {
    /*��������*/
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);

    /*��������*/
    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    /*��������*/
    Solution sol;

    cout << (sol.isPalindrome(head) ? "true" : "false");
}