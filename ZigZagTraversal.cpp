vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> result; 
        if (A==NULL) {
            return result;
        }
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(A);
        
        while(!s1.empty()  || !s2.empty()) {
            //cout << "Inside while loop1" << endl;
            
            vector<int> newArray1 = vector<int>();
            vector<int> newArray2 = vector<int>();
            while(!s1.empty()) {
                //cout << "s1 is non-empty" << endl;
                TreeNode* currNode = s1.top();
                s1.pop();
                //cout << "val: " << currNode->val << endl;
                newArray1.push_back(currNode->val); 
                
                if(currNode->left) 
                    s2.push(currNode->left);
                if(currNode->right)
                    s2.push(currNode->right);

            }
            if(newArray1.size()>0)
                result.push_back(newArray1);
            
            while(!s2.empty()) {
                //cout << "s2 is non-empty" << endl;
                TreeNode* currNode = s2.top();
                s2.pop();
                newArray2.push_back(currNode->val); 
                //cout << "val: " << currNode->val << endl;
                                
                if(currNode->right)
                    s1.push(currNode->right);
                if(currNode->left)
                    s1.push(currNode->left);
                
            }
            if(newArray2.size()>0)
                result.push_back(newArray2);
        }
        return result;
}
