//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        vector<int> temp;
        int low = l;
        int right = m+1;
        while(low<=m && right<=r) {
            if(arr[low]<=arr[right]) {
                temp.push_back(arr[low]);
                low++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(low<=m) {
            temp.push_back(arr[low]);
                low++;
        }
        while(right<=r) {
            temp.push_back(arr[right]);
                right++;
        }
        for(int i=l; i<=r; i++) {
            arr[i]=temp[i-l];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
            return ;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends