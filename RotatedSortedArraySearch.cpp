int getRotationIndex(const vector<int>& nums, int low, int high) {
        //cout << "// getRotationIndex // high: " << high << "low: " << low;
        if (high < low) {
            //cout << "high less than low" << endl;
            return -1;
        }
        if(high == low) return low;
        
        int mid = (low+high)/2;
        //cout << "mid: " << mid << endl;
    
        if(mid<high && nums[mid]>nums[mid+1]) {
            return mid;
        }
        else if(mid > low && nums[mid-1] > nums[mid]) {
            return mid-1;
        }
        else if(nums[low]>=nums[mid]) {
            return getRotationIndex(nums,low,mid-1);
        }
        else {
            return getRotationIndex(nums,mid+1,high);
        }
    }
    
    int binarySearch(const vector<int> &nums, int low, int high, int target) {
        if (high < low)
            return -1;
        
        int mid = (high + low)/2;
        //cout << "// Binary Search // high :" << high << "low: " << low << "mid: " << mid << endl;
        mid = (low + high)/2;
            
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            return binarySearch(nums,mid+1,high,target);
        }
 
        return binarySearch(nums,low,mid-1,target);
    }

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size()==0) {
            return -1; 
    }
        
    int rotationIndex = getRotationIndex(A, 0, A.size()-1);
    if(rotationIndex == -1) {
        return binarySearch(A,0,A.size()-1,B);
    }
        
    //cout << "rotationIndex: " << rotationIndex << endl;
        
    if(A[rotationIndex]==B) {
        return rotationIndex;
    }
    else if(A[0] <= B) {
        return binarySearch(A,0,rotationIndex-1,B);
    }
    else {
        return binarySearch(A,rotationIndex+1,A.size()-1,B);
    }
    
    
    
}
