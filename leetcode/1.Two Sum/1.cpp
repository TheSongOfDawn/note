class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool flag=false;
        vector<int> r;
        for(int i=0;i<=nums.size()-2;i++)
        {
            int willfind=target-nums[i];
            int j;
            for(j=i+1;j<nums.size();j++)
            {
                if(willfind==nums[j])
                {
                    flag=true;
                    break;
                }
            }
            if(flag){
                r.push_back(i);
                r.push_back(j);
                break;
            }
        }
        return r;
    }
};