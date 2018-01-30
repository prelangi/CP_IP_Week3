int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    if(A==NULL && B==NULL) {
            return true; 
        }
        else {
            if(A==NULL) {
                return false;
            }
            else {
                if(B==NULL) {
                    return false;
                }
            }
        }
        
        bool leftMatch  = true;
        bool rightMatch = true;
        
        if(A->val == B->val) {
            //Check if left tree exists and if they match
            if(A->left) {
                if(B->left) {
                    leftMatch = isSameTree(A->left,B->left);
                }
                else {
                    return false;
                }
            }
            else {
                if(B->left) {
                    return false;
                }
            }
            
            //Check if right tree exists and if they match
            if(A->right) {
                if(B->right) {
                    rightMatch = isSameTree(A->right,B->right);
                }
                else {
                    return false;
                }
            }
            else {
                if(B->right) {
                    return false;
                }
            }
        } 
        else {
            return false;
        }
        
        return(leftMatch && rightMatch);
    
}
