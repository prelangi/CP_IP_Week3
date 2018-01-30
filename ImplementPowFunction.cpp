int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int result = 1;
    int negative = 0;
    
    //Base cases
    if(x == 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    
    if(x<0){
        x = abs(x);
        if(n%2 != 0){ //odd power so number will still be negative
            negative = 1;
        }
    }
    
    long long int temp = x%d; //so that we can handle big numbers 
    
    while(n != 0){
        if(n%2 != 0){
            result = (result*temp)%d;
        }
        
        temp = temp*temp;
        temp = temp%d;
        n = n/2;
        
        if(result > d){
            result = result%d;
        }
    }
    
    if(negative == 1){
        return d-(int)result;
    }
    
    return (int)result;
        
}
