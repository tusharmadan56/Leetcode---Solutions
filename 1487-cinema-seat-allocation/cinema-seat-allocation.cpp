class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = n*2;

        unordered_map<int,int> mp;

        for(auto x:reservedSeats){
            mp[x[0]]|=(1<<x[1]);
        }

        for(auto [x,y]:mp){
            // cout<<x<<endl;
            // for(int i=1;i<=10;i++){
            //     if(y & (1<<i)){
            //         cout<<1<<" ";
            //     }
            //     else cout<<0<<" ";
            // }
            // cout<<endl;
            int fans = 0;
            bool f = true;
            for(int i=2;i<=5;i++){
                if(y & (1<<i)){
                    f=false;
                }
                else{
                    
                }
            }
            if(!f) fans--;

            f=true;
            for(int i=6;i<=9;i++){
                if(y & (1<<i)){
                     f=false;
                }
                else{
                   
                }
            }
            if(!f){
                fans--;
                
            }

            if(fans==-2){
                f=true;
                for(int i=4;i<=7;i++){
                    if(y & (1<<i)){
                        //cout<<i<<endl;
f=false;
                    }
                    else{
                        
                    }
                }
                //cout<<"f="<<f<<endl;
                if(f){
                    fans++;
                }
            }

            //cout<<fans<<endl;

            ans += fans;
        }

        return ans;


    }
};