//
// Created by Susancutie on 2022/9/5.
// Copyright © 2022 Susancutie. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> combinations;
        vector<int> combination;
        vector<int> chosen(nums.size());
        backtrack(combinations, nums, 0, combination, chosen);
        return combinations;
    }

    void backtrack(vector<vector<int>>& combinations, vector<int>& nums, int index, vector<int>& combination, vector<int>& chosen){
        bool admission;
        if(index == nums.size()){
            admission = true;
            for(const vector<int>& comb: combinations){
                if(comb == combination) admission = false;
            }
            if(admission){
                combinations.push_back(combination);
            }
        } else {
            int i = 0;
            for(const int& num: nums){
                if(chosen[i] == 0){
                    combination.push_back(num);
                    chosen[i] = 1;
                    backtrack(combinations, nums, index + 1, combination, chosen);
                    combination.pop_back();
                    chosen[i] = 0;
                }
                ++i;
            }
        }
    }
};

