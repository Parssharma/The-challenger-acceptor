class Solution {
private:
    void solution(vector<int> nums , vector<vector<int>> &ans, vector<int> output , int index ){
        if (index>=nums.size()){
            ans.push_back(output);
            return;
        }

        // /exclude
        solution(nums, ans, output, index+1);

        // include
        int element = nums[index];
        output.push_back(element);
        solution(nums,ans, output,index+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        int index = 0;
        solution(nums, ans , output , index);
        return ans;
    }
};