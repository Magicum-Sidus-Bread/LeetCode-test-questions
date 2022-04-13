//此解答超出时间限制！！！  
int trap(int* height, int heightSize){
    int max_height;
    int WaterNum = 0;
    int count = 0;
    max_height = height[0];
    for(int i = 1;i < heightSize;i++){
        if(height[i] >= max_height) max_height = height[i];
    }
    //初始化二维数组，1表示块，0表示空
    int ** bar;  
    bar=(int**)malloc(max_height * sizeof(int*));  
    for(int i = 0;i < max_height;i++){  
        bar[i]=(int*)calloc(heightSize,sizeof(int));  
    }
    for(int column = 0;column < heightSize;column++){
        for(int row = 0;row < height[column];row++){
            bar[row][column] = 1;
        }
    }
    /*水在一行中的两个黑块之间，所以在每一行遍历每个块，遇到黑块把之前的计数加到总数上，并把计数清零。遇到第一个黑块之前的空块根据IsStartCounting布尔值判断不计入总数。*/
    for(int row = 0;row < max_height;row++){
        bool IsStartCounting = false;
        count = 0;
        for(int column = 0;column < heightSize;column++){
            if(bar[row][column] == 1){
                IsStartCounting = true;
                WaterNum += count;
                count = 0;
            }
            else if(bar[row][column] == 0 && IsStartCounting == true){
                count++;
            }
        }
        printf("%d\n",WaterNum);
    }
    return WaterNum;
}
