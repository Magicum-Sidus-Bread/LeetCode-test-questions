char * convert(char * s, int numRows){
    char character[numRows][numRows];
    int length = strlen(s);
    int row = 0;
    int column = 0;
    for(int i = 0;i < length;i++){
        character[row][column] = s[i];
        if(row == 0){
            row++;
        }
        if(row == numRows-1){
            row = row - 1;
            column = column + 1;
        }
    }
    for(int i = 0;i < numRows;i++){
        for(int j = 0;j < numRows;j++){
            printf("%c",character[i][j]);
        }
        printf("\n");
    }
    return "PINALSIGYAHRPI";
}