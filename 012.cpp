/**********************************************
* �ļ�����012.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.14
* ��Ŀ��Դ������Ա���Խ��
* ����������02.03.ɾ���м�ڵ�
* ���Ӷȷ�����O(1)(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
    void deleteNode(ListNode* node) {/*���ⲻ��д����*/
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {

}