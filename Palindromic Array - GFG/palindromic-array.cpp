//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    { 
    	for(int i=0; i<n; i++) {
    	    int n=a[i],r=0,d;
    	    do {
    	        d=n%10;
    	        r=(r*10)+d;
    	        n=n/10;
    	    } while(n!=0);
    	    if(r!=a[i])
    	        return 0;
    	}
    	return 1;
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
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends