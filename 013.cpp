/**********************************************
* �ļ�����013.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.14
* ��Ŀ��Դ������Ա���Խ��
* ����������02.04.�ָ�����
* ���Ӷȷ�����(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
    ListNode* partition(ListNode* head, int x) {
        /*������������*/
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);

        /*�½�������Ҫ�����������½������ָ��*/
        ListNode* first = small; ListNode* last = big;

        while (head != nullptr) {
            if (head->val < x) {
                first->next = head;
                first = first->next;
            }
            else {
                last->next = head;
                last = last->next;
            }
            head = head->next;
        }

        /*ƴ������*/
        first->next = big->next;
        last->next = nullptr;
        return small->next;
    }
};

int main() {
    /*��������*/
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(2);

    /*��������*/
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    /*��������*/
    Solution sol;

    ListNode* result = sol.partition(head, 3);

    /*�����������*/
    ListNode* curListNode = result;
    while (curListNode != nullptr) {
        cout << curListNode->val << " ";
        curListNode = curListNode->next;
    }
    cout << endl;


}