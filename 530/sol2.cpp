class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;        

        TreeNode *pre;      
        TreeNode *current = root;
        int ans = INT_MAX;
        int prev = INT_MIN + 100000;
        
        while (current != NULL) {
            if (current->left == NULL) {
                ans = min(ans, current->val - prev);
                prev = current->val;
                current = current->right;
            }
            else {
                pre = current->left;
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    ans = min(ans, current->val - prev);
                    prev = current->val;
                    current = current->right;
                } 
            }
        }
        return ans;
    }
};
