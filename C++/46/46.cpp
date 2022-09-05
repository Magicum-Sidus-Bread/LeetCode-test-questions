//
// Created by Susancutie on 2022/9/5.
// Copyright © 2022 Susancutie. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> combinations;
        vector<int> combination;
        backtrack(combinations, nums, 0, combination);
        return combinations;
    }

    void backtrack(vector<vector<int>>& combinations, vector<int>& nums, int index, vector<int>& combination){
        bool admission;
        if(index == nums.size()){
            combinations.push_back(combination);
        } else {
            for(const int& num: nums){
                admission = true;
                for(const int& digit: combination){
                    if(digit == num) admission = false;
                }
                if(admission){
                    combination.push_back(num);
                    backtrack(combinations, nums, index + 1, combination);
                    combination.pop_back();
                }
            }
        }
    }
};
