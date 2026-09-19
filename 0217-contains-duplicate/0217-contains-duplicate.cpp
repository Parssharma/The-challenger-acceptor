class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i=0;
        int j=1;
        if(nums.size()<2){
            return false;
        }
        while(j<nums.size()){
            if( nums[i]==nums[j])
            return true;
            else{

            i++;
            j++;
            }
        
        }
        return false;
    }
};