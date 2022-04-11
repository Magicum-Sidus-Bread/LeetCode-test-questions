//以下解答可以通过测试，但是时间复杂度和空间复杂度都较高
//我还会继续优化代码，给出消耗更小时间和内存的解答
int lengthOfLongestSubstring(char * s){
    int MaxLength = 0;
    int len = strlen(s);
    int Repeated;
    if(!len){
        return 0;
    }
    char t[len];
    for(int i = 0;i < len;i++){
        int l = 0;
        Repeated = 0;
        for(int j = i;j < len;j++){
            if(Repeated == 1) {
                break;}
                for(int k = 0;k < l;k++){
                    if(t[k] == s[j]) Repeated = 1;
                }
            if(Repeated!=1){
                t[l] = s[j];
                l++;
                if(l>MaxLength) MaxLength = l;
            }
        }
    }
    return MaxLength;
}