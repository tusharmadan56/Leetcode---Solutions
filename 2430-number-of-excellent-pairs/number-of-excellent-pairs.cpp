class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> temp;
        long long fans = 0;

        sort(nums.begin(),nums.end());
        for(int i=0;i<(int)nums.size();i++){
            int c = 0;
            int x = nums[i];
            for(int i=0;i<=31;i++){
                if(x&(1<<i)){
                    c++;
                }
            }
           
            if(i>0 && nums[i]==nums[i-1]) continue;
            temp.push_back(c);
             if(2*c>=k) fans += 1;
            
        }

        int n = temp.size();

        sort(temp.begin(),temp.end());
        
       

        long long gg = 0;

      //  cout<<endl;//<<fans;


        for(int i=0;i<n;i++){
            //if(i>0 && temp[i]==temp[i-1]) continue;
            int val = k-temp[i];
            auto it = lower_bound(temp.begin()+i+1,temp.end(),val);

           //if(it!=temp.end()) cout<<*it<<endl;


            if(it!=temp.end()) gg += 0LL + (temp.end()-it);

          //  cout<<"gg="<<gg<<endl;


        }
        //cout<<"val"<<val<<end

        fans = fans + 2LL*gg;

        return fans;
        


        return 0;
    }
};