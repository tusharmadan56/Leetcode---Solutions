class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {

        int ogm = m,ogn = n;
        if(m>n){
            swap(n,m);
        }

        //cout<<n<<" "<<m<<endl;

        vector<vector<int>> dp(n,vector<int>(m,0));

        dp[0][0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                if(i==0){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1]+dp[i-1][j];
                }
            }
        }

        if(dp[n-1][m-1]<k) return {};
        if(dp[n-1][m-1]==k) {
            return vector<string> (ogm,string(ogn,'.'));
        }
        if(k==1){
            vector<string> fans;
            for(int i=0;i<ogm-1;i++){
                fans.push_back("."+string(ogn-1,'#'));
            }
            fans.push_back(string(ogn,'.'));

            return fans;
        }

        if(m<=2){

           // cout<<"h";
            if(ogm==2){
            vector<string> fans;
            
            fans.push_back(string(ogn,'.'));
            fans.push_back(string(ogn,'#'));

            fans[ogm-1][ogn-1]='.';

            fans[1][ogn-2]='.';

            if(k==2) return fans;

            if(ogn<3) return {};

            fans[1][ogn-3]='.';

            if(k==3) return fans;
            if(ogn<4) return {};

            fans[1][ogn-4]='.';
            if(k==4) return fans;
            }

            else{
                vector<string> fans;
            
                
                for(int i=1;i<ogm;i++){
                    fans.push_back(".#");
                }
                fans.push_back(string(ogn,'.'));

                //for(auto x:fans) cout<<x<<" ";

                fans[ogm-2][1]='.';
                 if(k==2) return fans;

                    if(ogm<3) return {};

                    fans[ogm-3][1]='.';

                    if(k==3) return fans;
                    if(ogm<4) return {};

                    fans[ogm-4][1]='.';
                    if(k==4) return fans;

            }

            

        }
        else if( m==3){

            if(ogm==3){
             vector<string> fans;
            
            fans.push_back(string(ogn,'.'));
                for(int i=2;i<ogm;i++){
                    fans.push_back(string(ogn-1,'#')+".");
                }
                fans.push_back(string(ogn,'#'));

            fans[ogm-1][ogn-1]='.';
            
            fans[1][ogn-2]='.';
            cout<<"h1";
            if(k==2) return fans;
            cout<<"h2";
            fans[1][ogn-3]='.';
            if(k==3) return fans;

            if(n==3){
                fans[0][2]='#';
                fans[2][0]='#';
                fans[2][1]='.';
                
                return fans;
            }

            fans[1][ogn-4]='.';
            return fans;
            }
            else{
                vector<string> fans;
            
           
                for(int i=1;i<ogm;i++){
                    fans.push_back("."+string(ogn-1,'#'));
                }
                fans.push_back(string(ogn,'.'));

            
            
            fans[ogm-2][1]='.';
            //cout<<"h1";
            if(k==2) return fans;
            //cout<<"h2";
            fans[ogm-3][1]='.';
            if(k==3) return fans;

            if(ogm<4) return {};

            fans[ogm-4][1]='.';
            return fans;
            }
        }
        else{
            vector<string> fans;
            
                fans.push_back(string(ogn,'.'));
                for(int i=2;i<ogm;i++){
                    fans.push_back("."+string(ogn-2,'#')+".");
                }
                fans.push_back(string(ogn,'.'));
            if(k==2){
                return fans;
            }
             if(k==3){
                fans[1][ogn-2]='.';

            }
            if(k==4){
                fans[1][ogn-2]='.';
                fans[ogm-2][1]='.';
            }

            return fans;

        }
        return {};

    }
};