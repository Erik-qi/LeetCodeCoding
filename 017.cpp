/**********************************************
* 文件名：016.cpp
* 创建人：qhy
* 创建时间：2024.07.22
* 题目来源：程序员面试金典
* 代码描述：02.08.环路检测(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
* 复杂度分析：
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
            /*不是环形链表*/
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