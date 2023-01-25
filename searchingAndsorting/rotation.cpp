int solve(int arr[], int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
       
       if(mid<high&&arr[mid]>arr[mid+1])
        return mid;
        if(mid>low&&arr[mid-1]>arr[mid])
        return mid-1;
        
        if(arr[mid]<arr[low])
        high=mid-1;
        else
        low=mid+1;
    }
 return -1;
}
	int findKRotation(int arr[], int n) {
	    return solve(arr,n)+1;
	    
    
}