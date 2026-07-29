class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> s1,s2;

        int n= matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            bool f = false;
            if(s1.find(i)!=s1.end()) {
                f=true;
            }
            for(int j=0;j<m;j++){
                if(f || s2.find(j)!=s2.end()){
                    matrix[i][j] = 0;
                }
            }
        }

        



    }
};