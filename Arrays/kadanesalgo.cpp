//largest sum in contiguous subarray
long long maxSubarraySum(vector<int> arr, int n)
{
    long long max=LONG_MIN;
    long long sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
         if(sum<0){
            sum=0;
        }
        if(sum>max){
            max=sum;
        }
       
        
    }
    return max;
}
