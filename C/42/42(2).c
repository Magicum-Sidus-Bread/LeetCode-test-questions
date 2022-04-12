//又一种超时的解题思路：返回每一行的水块的数量，再把每一行的水的数量加起来
int row_num(int* height,int heightSize,int row){
    int num = 0;
    int column;
    bool IsStarted = false;
    for(int i = 0;i < heightSize;i++){
        if(height[i] >= row && IsStarted == false){
            column = i;
            IsStarted = true;
        }
        else if(height[i] >= row && IsStarted == true){
            num += i-column-1;
            column = i;
        }
    }
    return num;
}
int trap(int* height, int heightSize){
    int WaterNum = 0;
    int max_height;
    int WaterRowNum;
    max_height = height[0];
    for(int i = 1;i < heightSize;i++){
        if(height[i] >= max_height) max_height = height[i];
    }
    for(int row = 1;row <= max_height;row++){
        WaterRowNum = row_num(height,heightSize,row);
        WaterNum += WaterRowNum;
    }
    return WaterNum;
}