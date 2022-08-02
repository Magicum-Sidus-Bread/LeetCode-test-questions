//
// Created by Susancutie on 2022/8/2.
//

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if(length < 2){
            return s;
        }
        int Maxlength = 1;
        int begin = 0;

        vector<vector<int>> dp(length,vector<int>(length));
        for(int i = 0;i < length;i++){
            dp[i][i] = true;
        }

        for(int L = 2;L <= length;L++){
            for(int i = 0;i < length;i++){
                int j = L + i -1;
                if(j >= length){
                    break;
                }
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && j-i+1 > Maxlength){
                    Maxlength = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,Maxlength);
    }
};