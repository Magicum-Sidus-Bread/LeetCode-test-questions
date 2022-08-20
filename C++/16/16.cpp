//
// Created by Susancutie on 2022/8/20.
//

class Solution {
public:
    void update(int cur, int* best, int target) {
        if(abs(cur - target) < abs(*best - target)) {
            *best = cur;
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        for(int first = 0;first < n;++first){
            if(first > 0 && nums[first] == nums[first - 1]){
                continue;
            }
            int second = first + 1;
            int third = n - 1;
            while(second < third){
                int sum = nums[first] + nums[second] + nums[third];
                if(sum == target) {
                    return target;
                }
                update(sum, &best, target);
                if(sum > target){
                    int k0 = third - 1;
                    while(second < k0 && nums[k0] == nums[third]){
                        --k0;
                    }
                    third = k0;
                } else {
                    int j0 = second + 1;
                    while(j0 < third && nums[j0] == nums[second]){
                        ++j0;
                    }
                    second = j0;
                }
            }
        }
        return best;
    }
};