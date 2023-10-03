//used for arrays of 0,1,2 
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int high=n-1,low=0,mid=0;
    while(high>=mid){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
            
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
        }
    
}
