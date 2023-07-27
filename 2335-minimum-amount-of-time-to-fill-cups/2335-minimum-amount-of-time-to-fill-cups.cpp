class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto it: amount)
            pq.push(it);
        int time=0;
        while(pq.top()!=0) {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(y==0){
                time+=x;
                pq.push(0);
            }
            else{
                time++;
                pq.push(x-1);
                pq.push(y-1);
            }
        }
        return time;
    }
};