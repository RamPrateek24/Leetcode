/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> l;
            for(int i=0; i<s; i++){
                TreeNode* tr = q.front();
                q.pop();
                if(tr->left != NULL) q.push(tr->left);
                if(tr->right != NULL) q.push(tr->right);
                l.push_back(tr->val);
            }
            v.push_back(l);
        }
        return v;
    }
};