/**********************************************
* 文件名：010.cpp
* 创建人：qhy
* 创建时间：2024.07.13
* 题目来源：程序员面试金典
* 代码描述：02.01.移除重复节点
* 复杂度分析：(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
    // 创建一个包含重复元素的链表
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(2);

    // 建立链表的链接，以head代表链表
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // 创建 Solution 实例
    Solution sol;

    // 移除重复节点
    ListNode* result = sol.removeDuplicateNodes(head);

    // 遍历并打印结果
    ListNode* current = result;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // 清理内存
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}