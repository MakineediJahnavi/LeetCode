class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(int i=0; i<stones.size(); i++) {
            p.push(stones[i]);
        }
        while(p.size()>1){
            int y=p.top();
            p.pop();
            int x=p.top();
            p.pop();
            if(x!=y)
                p.push(y-x);
        }
        if(!p.empty())
            return p.top();
        return 0;
    }
};