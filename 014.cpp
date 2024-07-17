/**********************************************
* �ļ�����013.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.15
* ��Ŀ��Դ������Ա���Խ��
* ����������02.05.�������(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*���������ָ��*/
        ListNode* first = l1;
        ListNode* last = l2;

        /*���ֽڵ������l1<l2*/
        int cnt1 = 0, cnt2 = 0;
        while (first != nullptr) {
            ++cnt1;
            first = first->next;
        }
        while (last != nullptr) {
            ++cnt2;
            last = last->next;
        }

        if (cnt1 > cnt2)
            return addTwoNumbers(l2, l1);
        
        /*��l1��ֵ����l2*/
        ListNode* ptr = l2;
        while (ptr != nullptr) {
            if (l1 != nullptr) {
                ptr->val = ptr->val + l1->val;
                l1 = l1->next;
                ptr = ptr->next;
            }
            else
                break;            
        }

        /*����l2�����ڵ���10��λ*/
        ListNode* result = l2;
        while (result->next != nullptr) {
            if (result->val >= 10) {
                result->val = result->val % 10;
                result->next->val++;
            }
            result = result->next;
        }
        /*�ж����һ���ڵ��Ƿ���ڵ���10*/
        if (result->val>= 10) {
            result->val= result->val % 10;
            ListNode* node = new ListNode(1);
            node->next = nullptr;
            result->next = node;
        }

        return l2;
    }
};

int main() {
    /*��������1*/
    ListNode* node1 = new ListNode(0);

    /*��������2*/
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(8);

    
    /*��������2*/
    node4->next = node5;

    /*��������*/
    Solution sol;

    ListNode* result = sol.addTwoNumbers(node1, node4);

    /*�����������*/
    ListNode* curListNode = result;
    while (curListNode != nullptr) {
        cout << curListNode->val << " ";
        curListNode = curListNode->next;
    }
    cout << endl;
}