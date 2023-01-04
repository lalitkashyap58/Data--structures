#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    private:
    int func(TreeNode* root,int &diameter)
    {
        if(root==NULL)
        return 0;
        int leftDiameter=func(root->left,diameter);
        int rightDiameter=func(root->right,diameter);
        
        diameter=max(diameter,leftDiameter+rightDiameter);
        return 1+max(leftDiameter,rightDiameter);
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
    int maxi=INT_MIN;
    func(root,maxi);
    return maxi;
    
    }
};