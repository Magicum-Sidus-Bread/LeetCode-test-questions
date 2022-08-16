//
// Created by Susancutie on 2022/8/16.
// Copyright © 2022 Susancutie. All rights reserved.
//

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            if(rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;
            int digit = x % 10;
            x = x / 10;
            rev = 10 * rev + digit;
        }
        return rev;
    }
};