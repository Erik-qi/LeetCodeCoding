/**********************************************
* �ļ�����010.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.13
* ��Ŀ��Դ������Ա���Խ��
* ����������02.01.�Ƴ��ظ��ڵ�
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* first = head;

        while (first != nullptr) {
            ListNode* last = first;
            while (last->next != nullptr) {
                if (last->next->val == first->val)
                    last->next = last->next->next;
                else
                    last = last->next;
            }
            first = first->next;
        }

        return head;
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
    ListNode* result = sol.removeDuplicateNodes(head);

    // ��������ӡ���
    ListNode* current = result;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // �����ڴ�
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}