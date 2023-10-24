class Solution {
public:
    void f(TreeNode* root,vector<int>& ans){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maxi = INT_MIN;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(maxi);
                maxi = INT_MIN;
                if(!q.empty())
                q.push(NULL);
                continue;
            }
            maxi = max(temp->val,maxi);
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        f(root,ans);
        return ans;
    }
};
