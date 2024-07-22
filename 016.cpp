/**********************************************
* �ļ�����016.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.22
* ��Ŀ��Դ������Ա���Խ��
* ����������02.07.�����ཻ(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
* ���Ӷȷ�����ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�O(1)
***********************************************/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* A = headA; ListNode* B = headB;

        while (A != B) {
            if (A != nullptr)
                A = A->next;
            else
                A = headB;
            if (B != nullptr)
                B = B->next;
            else
                B = headA;
        }

        return A;
    }
};

int main() {
    /*��������1*/
    ListNode* headA = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(4);

    /*��������1*/
    headA->next = node1;
    node1->next = node2;

    /*��������2*/
    ListNode* headB = new ListNode(0);
    ListNode* node5 = new ListNode(9);
    ListNode* node6 = new ListNode(1);
    ListNode* node7 = new ListNode(2);
    ListNode* node8 = new ListNode(4);

    /*��������2*/
    headB->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    /*��������*/
    Solution sol;

    ListNode* result = sol.getIntersectionNode(headA, headB);

    /*�����������*/
    while (result != nullptr) {
        cout << result->val << " ";
    }
    cout << endl;
}