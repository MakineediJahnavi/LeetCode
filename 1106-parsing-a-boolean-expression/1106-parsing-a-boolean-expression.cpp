class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for(auto it: expression) {
            if(it==',') continue;
            if(it==')') {
                int f=0,t=0;
                while(s.top()!='(') {
                    if(s.top()=='f') f++;
                    else if(s.top()=='t') t++;
                    s.pop();
                }
                s.pop();
                char c=s.top();
                s.pop();
                if(c=='|') {
                    if(t)
                        s.push('t');
                    else
                        s.push('f');
                }
                else if(c=='!') {
                    if(t)
                        s.push('f');
                    else
                        s.push('t');
                }
                else {
                    if(f)
                        s.push('f');
                    else
                        s.push('t');
                }
            }
            else 
                s.push(it);
        }
        if(s.top()=='f')
            return false;
        return true;
    }
};