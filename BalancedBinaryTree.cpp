bool isBalancedWrapper(TreeNode* root, int &currHeight) {
        if(root== NULL) {
            currHeight = 0;
            return true;
        }    
        
        if(root->left == NULL && root->right==NULL) {
            currHeight = 1;
            return true;
        }
        
        int leftTreeHeight = 0, rightTreeHeight = 0; 
        bool isLeftBalanced = isBalancedWrapper(root->left, leftTreeHeight);
        bool isRightBalanced = isBalancedWrapper(root->right, rightTreeHeight);
        int diff = abs(leftTreeHeight - rightTreeHeight); 
        currHeight = 1 + max(leftTreeHeight, rightTreeHeight);
        //cout << "isLeftBalanced: " << isLeftBalanced << "isRightBalanced: " << isRightBalanced << "diff: " << diff << endl;
        if(diff<=1 && isLeftBalanced && isRightBalanced) {
            return true;
        }
        else {
            return false;
        }
        
}

int Solution::isBalanced(TreeNode* A) {
    int currHeight;
    return isBalancedWrapper(A, currHeight);
}
