int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    if(A==0 || A==1) {
            return A;
    }
        
    int start = 0, end = A, mid = 0;
    int ans;
            
    while(start <= end) {
        mid = start + (end-start)/2;
        //cout << "start:" << start << "end:" << end << "mid: " << mid << endl;
            
        if ((mid <= (A/mid)) && (mid+1) > (A/(mid+1))) {
            return mid;
        }
        else if(mid < (A/mid)) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
            
    }
        
    return ans;
    
}
