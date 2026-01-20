class Solution {
public:
    long long totalSum = 0;
    long long mx = 0;

    long long dfs(TreeNode* root) {
        if (root == NULL) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);
                                                                                                                                                                                                                                                                                                                                                                                                        
        long long curSum = root->val + left + right;

        mx = max(mx, curSum * (totalSum - curSum));

        return curSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfsTotal(root);   // first pass
        dfs(root);                   // second pass
        return mx % 1000000007;
    }

private:
    long long dfsTotal(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + dfsTotal(root->left) + dfsTotal(root->right);
    }
};
