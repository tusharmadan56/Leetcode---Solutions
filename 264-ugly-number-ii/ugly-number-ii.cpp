class Solution {
public:
    #define ll long long 
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll>> q;
        int c = 1;

        unordered_set<ll> s;

        q.push(1);


        for(int i=1;i<=n;i++){
            ll f = q.top();
            q.pop();
           // cout<<f<<" ";
            if(i==n) return f;

            // if(s.size()>000) continue;

            if(s.find(f*2)==s.end()) q.push(f*2);
            if(s.find(f*3)==s.end()) q.push(f*3);
            if(s.find(f*5)==s.end()) q.push(f*5);

            s.insert(f*2);
            s.insert(f*3);
            s.insert(f*5);
        }

        return 0;



    }
};