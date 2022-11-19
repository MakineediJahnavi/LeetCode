//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int a[], int n, int key)
    {
        int k=-1;
        vector<int> result;
        for(int i=0; i<n; i++) {
            if(a[i]==key){
            result.push_back(i);
            k=0;
            break;}
        }
        for(int i=n-1; i>=0; i--) {
            if(a[i]==key){
            result.push_back(i);
            k=0;
            break;}
        }
        if(k==-1) {
        result.push_back(-1);
        result.push_back(-1); }
        return result;
    }
  
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends