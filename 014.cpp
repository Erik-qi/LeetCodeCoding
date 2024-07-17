/**********************************************
* 文件名：013.cpp
* 创建人：qhy
* 创建时间：2024.07.15
* 题目来源：程序员面试金典
* 代码描述：02.05.链表求和(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
        /*创建链表的指针*/
        ListNode* first = l1;
        ListNode* last = l2;

        /*区分节点个数，l1<l2*/
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
        
        /*将l1的值赋给l2*/
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

        /*遍历l2，大于等于10进位*/
        ListNode* result = l2;
        while (result->next != nullptr) {
            if (result->val >= 10) {
                result->val = result->val % 10;
                result->next->val++;
            }
            result = result->next;
        }
        /*判断最后一个节点是否大于等于10*/
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
    /*创建链表1*/
    ListNode* node1 = new ListNode(0);

    /*创建链表2*/
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(8);

    
    /*连接链表2*/
    node4->next = node5;

    /*创建对象*/
    Solution sol;

    ListNode* result = sol.addTwoNumbers(node1, node4);

    /*遍历链表并输出*/
    ListNode* curListNode = result;
    while (curListNode != nullptr) {
        cout << curListNode->val << " ";
        curListNode = curListNode->next;
    }
    cout << endl;
}