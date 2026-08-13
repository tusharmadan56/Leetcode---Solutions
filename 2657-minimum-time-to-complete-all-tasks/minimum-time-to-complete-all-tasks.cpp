class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](vector<int>& a,vector<int>& b){
            if(a[1]==b[1]){
                return a[2]>b[2];
            }
            return a[1]<b[1];
        });

        int n = tasks.size();
        vector<bool> v(2001 , 0);
        for(int i=0;i<n;i++){
            int a = tasks[i][0] , b=tasks[i][1] , c = tasks[i][2];
            int tot = 0 ;

            for(int j=b;j>=a;j--){
                if(v[j]) tot++;

            }
            if(tot>=c) continue;
            int diff = c-tot;

            for(int j=b;j>=a;j--){
                if(diff==0) break;
                if(!v[j]){
                    v[j] = true;
                    diff--;
                }
            }



        }   


        int fans = 0;

        for(int i=0;i<=2000;i++){
            if(v[i]) fans++;
        }

        return fans;





    }
};