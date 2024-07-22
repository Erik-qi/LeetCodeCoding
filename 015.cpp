/**********************************************
* 文件名：015.cpp
* 创建人：qhy
* 创建时间：2024.07.22
* 题目来源：程序员面试金典
* 代码描述：02.06.回文链表(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
    bool isPalindrome(ListNode* head) {
        vector<int> vec{};
        while (head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
            if (vec[i] != vec[j])
                return false;
        }

        return true;
    }
};

int main() {
    /*创建链表*/
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);

    /*连接链表*/
    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    /*创建对象*/
    Solution sol;

    cout << (sol.isPalindrome(head) ? "true" : "false");
}