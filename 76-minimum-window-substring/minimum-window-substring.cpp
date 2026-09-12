class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> arr(128, 0 ),temp(128,0);

        for(auto x:t){
            arr[x]++;
        }

        int n = s.size();

        int i = 0 , j = 0 ;

        int  f = -1 , e = -1;

        int fans = 1e9;

        while(j<n){
            temp[s[j]]++;

            while(i<=j){
                bool flag = true;
                for(int k=0;k<128;k++){
                    if(temp[k]<arr[k]){
                        flag = false;
                        break;
                    }
                }

                if(!flag) break;

                int len = j - i+1;
                if(fans > len){
                    f = i;
                    e = j;
                    fans = len ;
                }
                temp[s[i]]--;
                i++;
            }
            j++;
        }

        string ok = "";

        if(f!=-1){
            ok = s.substr(f , fans);
        }

        return ok;
    }
};