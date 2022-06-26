//
// Created by Harry Potter on 2022/6/26.
//
int strStr(char* haystack, char* needle) {
    int n = strlen(haystack), m = strlen(needle);
    for (int i = 0; i + m <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}