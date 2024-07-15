/**********************************************
* 文件名：012.cpp
* 创建人：qhy
* 创建时间：2024.07.14
* 题目来源：程序员面试金典
* 代码描述：02.03.删除中间节点
* 复杂度分析：O(1)(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
    void deleteNode(ListNode* node) {/*这题不好写用例*/
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {

}