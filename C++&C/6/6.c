char * convert(char * s, int numRows){
    if(numRows == 1) return s;
    int length = strlen(s);
    // printf("%d\n",length);
    int numColumns = (length / (2 * numRows - 2) + 1) * (numRows - 1);
    char character[numRows][numColumns];
    //初始化二维数组的每一项为‘0’
    for(int i = 0;i < numRows;i++){
        for(int j = 0;j < numColumns;j++){
            character[i][j] = '0';
        }
    }
    int row = 0;
    int column = 0;
    bool direction = true;//ture代表向下方向，false代表向上
    //在二维数组中按照Z字形的规则填充相应的字母，考虑四种情况：最上边、最下边、中间向下、中间向上
    for(int i = 0;i < length;i++){
        character[row][column] = s[i];
        if(row == 0){
            row++;
            direction = true;
        }
        else if(row == numRows-1){
            row = row - 1;
            column = column + 1;
            direction = false;
        }
        else if(direction == true) row++;
        else if(direction == false){
            row = row - 1;
            column = column + 1;
        }
    }
    //遍历二维数组、输出不为‘0’的项
    char *p = calloc(length + 1, sizeof(char));
    int v = 0;
    for(int i = 0;i < numRows;i++){
        for(int j = 0;j < numColumns;j++){
            if(character[i][j] != '0'){
                p[v] = character[i][j];
                v++;
            }
        }
    }

    return p;
}