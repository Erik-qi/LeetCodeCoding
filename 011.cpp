/**********************************************
* �ļ�����011.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.13
* ��Ŀ��Դ������Ա���Խ��
* ����������02.02.���ص�����K���ڵ�
* ���Ӷȷ�����(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        /*����һ�����ڽڵ�*/
        ListNode* first = head;
        ListNode* last = first;
        for (int i = 0; i < k; i++) {
            last = last->next;
        }

        while (last != nullptr) {
            first = first->next;
            last = last->next;
        }

        return first->val;
    }
};

int main() {
    // ����һ�������ظ�Ԫ�ص�����
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(2);

    // ������������ӣ���head��������
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // ���� Solution ʵ��
    Solution sol;

    // �Ƴ��ظ��ڵ�
    cout<<sol.kthToLast(head,2);
}