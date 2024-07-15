/**********************************************
* 文件名：013.cpp
* 创建人：qhy
* 创建时间：2024.07.14
* 题目来源：程序员面试金典
* 代码描述：02.04.分割链表
* 复杂度分析：(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
        /*创建两个链表*/
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);

        /*新建链表需要遍历，创建新建链表的指针*/
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

        /*拼接链表*/
        first->next = big->next;
        last->next = nullptr;
        return small->next;
    }
};

int main() {
    /*创建链表*/
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(2);

    /*连接链表*/
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    /*创建对象*/
    Solution sol;

    ListNode* result = sol.partition(head, 3);

    /*遍历链表并输出*/
    ListNode* curListNode = result;
    while (curListNode != nullptr) {
        cout << curListNode->val << " ";
        curListNode = curListNode->next;
    }
    cout << endl;


}