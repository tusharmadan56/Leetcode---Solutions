class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> possible;
        possible.push_back(nums);

        vector<int> arr;

        for(int i = 0; i < n - 1; i++)
            arr.push_back(nums[i]);
        possible.push_back(arr);

        arr.clear();

        for(int i = 1; i < n; i++)
            arr.push_back(nums[i]);
        possible.push_back(arr);

        vector<int> prefix(n), suffix(n);

        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = gcd(prefix[i - 1], nums[i]);

        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
            suffix[i] = gcd(nums[i], suffix[i + 1]);

        int idx = -1;

        for(int i = 1; i < n - 1; i++) {
            int left = prefix[i - 1];
            int right = suffix[i + 1];

            if(gcd(left, right) != gcd(gcd(left, right), nums[i])) {
                idx = i;
                break;
            }
        }

        if(idx != -1) {
            arr.clear();

            for(int i = 0; i < n; i++) {
                if(i == idx) continue;
                arr.push_back(nums[i]);
            }

            possible.push_back(arr);
        }

        int res = 0;

        for(auto &vec : possible) {
            int m = vec.size();

            vector<int> prefix2(m), suffix2(m);

            prefix2[0] = vec[0];

            for(int i = 1; i < m; i++)
                prefix2[i] = gcd(prefix2[i - 1], vec[i]);

            suffix2[m - 1] = vec[m - 1];

            for(int i = m - 2; i >= 0; i--)
                suffix2[i] = gcd(vec[i], suffix2[i + 1]);

            int temp = 0;

            for(int i = 0; i < m - 1; i++) {
                if(prefix2[i] == suffix2[i + 1])
                    temp++;
            }

            res = max(res, temp);
        }

        return res;
    }
};