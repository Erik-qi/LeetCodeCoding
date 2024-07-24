/**********************************************
* �ļ�����016.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.22
* ��Ŀ��Դ������Ա���Խ��
* ����������02.08.��·���(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
* ���Ӷȷ�����
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head;
        
        while (fast != nullptr) {
            slow = slow->next;
            /*���ǻ�������*/
            if (fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            
            if (slow == fast) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }

        return nullptr;
    }
};