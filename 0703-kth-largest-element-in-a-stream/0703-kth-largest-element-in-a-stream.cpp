class KthLargest {
    int n;
    priority_queue<int, vector<int>, greater<int>> p;
public:
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto it: nums) {
            p.push(it);
        }
    }
    
    int add(int val) {
        p.push(val);
        while(p.size()>n) {
                p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */