/**********************************************
* 文件名：016.cpp
* 创建人：qhy
* 创建时间：2024.07.22
* 题目来源：程序员面试金典
* 代码描述：02.07.链表相交(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
* 复杂度分析：时间复杂度O(m+n)，空间复杂度O(1)
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
    /*创建链表1*/
    ListNode* headA = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(4);

    /*连接链表1*/
    headA->next = node1;
    node1->next = node2;

    /*创建链表2*/
    ListNode* headB = new ListNode(0);
    ListNode* node5 = new ListNode(9);
    ListNode* node6 = new ListNode(1);
    ListNode* node7 = new ListNode(2);
    ListNode* node8 = new ListNode(4);

    /*连接链表2*/
    headB->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    /*创建对象*/
    Solution sol;

    ListNode* result = sol.getIntersectionNode(headA, headB);

    /*遍历链表并输出*/
    while (result != nullptr) {
        cout << result->val << " ";
    }
    cout << endl;
}