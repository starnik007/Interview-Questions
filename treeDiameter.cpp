#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int value;
};

int findDiameterHelper(TreeNode* node, int &maxResult){
    if(!node) return 0;
    int leftResult = findDiameterHelper(node->left, maxResult), rightResult = findDiameterHelper(node->right, maxResult);
    maxResult = max(maxResult, leftResult + rightResult + 1);
    return max(leftResult, rightResult) + 1;
}

int findDiameter(TreeNode* root){
    int result = 0;
    findDiameterHelper(root, result);
    return result;
}