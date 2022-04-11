class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//int length = end(nums) - begin(nums);
int length = nums.size();
for(int i=0;i<length-1;i++){
    for(int j=i+1;j<length;j++){
        int sum = nums[i] + nums[j];
        if(sum==target){
            vector<int> result;
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
}
return {};
    }
};