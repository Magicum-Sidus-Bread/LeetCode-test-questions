//
// Created by Harry Potter on 2022/6/26.
//
int strStr(char * haystack, char * needle){
    char *p,*q;
    p = haystack;
    q = needle;
    int index = 0;
    int location = 0;
    while(*p){
        if(*q==NULL) return location;
        else{
            if(*p==*q){
                p++;
                q++;
            }
        }

    }
    return -1;
}