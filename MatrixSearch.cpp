int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    if(A.size()==0) {
        return 0;
    }
        
    int rows = A.size();
    int cols = A[0].size();
    int numElems = rows*cols;
    int currRow, currCol; 
        
    int low = 0,mid = 0;
    int high = numElems - 1;
        
    while(low <= high) {
        mid = (low + high)/2;
        currRow = mid/cols;
        currCol = mid%cols;
        //cout << "low: " << low << "high: " << high << "mid: " << mid << endl;
        //cout << "currRow: " << currRow << "currCol: " << currCol << endl;
            
            if(A[currRow][currCol] == B) {
                return 1;
            }
            else if(A[currRow][currCol] < B) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
            
        }
        
        return 0;
}
