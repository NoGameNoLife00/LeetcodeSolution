// Reverse a singly linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == NULL || head->next == NULL){
    		return head;
    	}
    	ListNode *pre = head;
    	ListNode *next = head->next;
    	ListNode *last = next->next;
    	while (true){
    		next->next = pre;
    		head->next = last;

    		pre = next;
    		next = last;
    		if (head->next == NULL){
    			break;
    		}
    		last = last->next;

    	}
    	return pre;
    }
};
// https://leetcode.com/problems/reverse-linked-list/
// 输入一个链表，翻转这个链表，并返回
// 解法： 设置3个指针变量分别指向需要交互的两个节点，和他们的后一个节点。 遍历链表开始交换
