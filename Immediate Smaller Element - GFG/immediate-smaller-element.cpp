//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    stack<int> s;
	    for(int i=n-1; i>=0; i--) {
	        if(s.empty()){
	            s.push(arr[i]);
	            arr[i]=-1;}
	        else if(arr[i]>s.top()){
	            int x=s.top();
	            s.push(arr[i]);
	            arr[i]=x;
	        }
	        else {
	            s.push(arr[i]);
	            arr[i]=-1;
	        }
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends