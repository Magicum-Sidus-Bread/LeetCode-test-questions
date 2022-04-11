char * intToRoman(int num){
    char *s = calloc(16, sizeof(char));
    int j = 0;
    int thousand = num / 1000;
    if(thousand != 0){
        for(int i = 0;i < thousand;i++){
            s[j] = 'M';
            j++; 
        }
    }
    num = num - thousand * 1000;
    if(num >= 900) {
        s[j] = 'C';
        s[j+1] = 'M';
        j += 2;
        num -= 900;
    }
    else if(num >= 500){
        s[j] = 'D';
        j++;
        num -= 500;
    }
    else if(num >= 400){
        s[j] = 'C';
        s[j+1] = 'D';
        j += 2;
        num -= 400;
    }
    int hundred = num / 100;
    if(hundred != 0){
        for(int i = 0;i < hundred;i++){
            s[j] = 'C';
            j++; 
        }
    }
    num = num - hundred * 100;

    if(num >= 90) {
        s[j] = 'X';
        s[j+1] = 'C';
        j += 2;
        num -= 90;
    }
    else if(num >= 50){
        s[j] = 'L';
        j++;
        num -= 50;
    }
    else if(num >= 40){
        s[j] = 'X';
        s[j+1] = 'L';
        j += 2;
        num -= 40;
    }
    int ten = num / 10;
    if(ten != 0){
        for(int i = 0;i < ten;i++){
            s[j] = 'X';
            j++; 
        }
    }
    num = num - ten * 10;
    

    if(num >= 9) {
        s[j] = 'I';
        s[j+1] = 'X';
        j += 2;
        num -= 9;
    }
    else if(num >= 5){
        s[j] = 'V';
        j++;
        num -= 5;
    }
    else if(num >= 4){
        s[j] = 'I';
        s[j+1] = 'V';
        j += 2;
        num -= 4;
    }
    int one = num;
    if(one != 0){
        for(int i = 0;i < one;i++){
            s[j] = 'I';
            j++; 
        }
    }
    return s;
}