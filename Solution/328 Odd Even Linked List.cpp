// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.

// Note:
// The relative order inside both the even and odd groups should remain as it was in the input.
// The first node is considered odd, the second node even and so on ...

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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode *evenHead = head->next;
        ListNode *odd = head;
        ListNode *even = evenHead;
        ListNode *curr = even->next;
        int count = 3;

        while (curr){
            odd->next = curr;
            odd = odd->next;
            curr = curr->next;
            if (curr){
                even->next = curr;
                even = even->next;
                curr = curr->next;
            }else{
                break;
            }

        }
        odd->next = evenHead;
        even->next = NULL;
        return head;
    }
};

// https://leetcode.com/problems/odd-even-linked-list/
// 输入一个队列，将队列分成奇数位置部分链表到一起和偶数位置部分链表，之后再把偶数链表连接到奇数部分列表尾部。
// 解法：将输入的列表node的第一节点作为奇数链表的头部，第二节点作为偶数链表的头部，之后从第三个节点的位置遍历链表，分别将每个节点连接到奇数和偶数链表
// 	最后将偶数链表连接到奇数链表上 并返回
//