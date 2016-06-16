// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 解法1：
class Solution {
public:
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {

        int nLeft = 0;
        int nRight = 0;
        if (root->left != NULL){
           nLeft = kthSmallest(root->left, k);
        }
        count++;
        if (k == count) {
            return root->val;
        }
        if (root->right != NULL) {
           nRight = kthSmallest(root->right, k);
        }
        return nLeft + nRight;
    }
};
解法2：
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int result = 0;
        int count = 0;
        TreeNode *node = root;

        while (node != NULL || s.size() != 0){
            while (node) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            count++;
            if (count == k){
                result = node->val;
            }
            node = node->right;
        }
        return result;
    }
};
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// 输入一个二叉搜索树，和一个整数k， 求二叉搜索树中第k小的元素
// 解法1：使用递归,中序遍历二叉树数求出第k小的元素（利用二叉搜索树的特性， 左子树的所有元素小于当前节点元素值，右子数的所有元素的值大于当前节点元素值）
// 解法2：使用堆栈模拟递归，中序遍历二叉树，求出第k小的元素