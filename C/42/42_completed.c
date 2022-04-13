int higher(int* height,int heightSize,int column,int direction,int max_height_column){
    if(direction == 0){
        if(column == heightSize - 1) return -1;
        for(int i = column + 1;i < heightSize;i++){
            if(height[i] >= height[column]) return i;
        }
        return -1;
    }
    else{
        for(int i = column - 1;i >= max_height_column;i--){
            if(height[i] >= height[column]) return i;
        }
        return -1;
    }
}
int NumCalculate(int* height,int left,int right,int direction){
    if(direction == 0){
        if(right == left + 1) return 0;
        int total = (right - left - 1) * height[left];
        int bar_sum = 0;
        for(int i = left + 1;i < right;i++){
            bar_sum += height[i];
        }
        int water_num = total - bar_sum;
        return water_num;
    }
    else{
        if(right == left + 1) return 0;
        int total = (right - left - 1) * height[right];
        int bar_sum = 0;
        for(int i = left + 1;i < right;i++){
            bar_sum += height[i];
        }
        int water_num = total - bar_sum;
        return water_num;
    }
   
}




int trap(int* height, int heightSize){
    int WaterNum = 0;
    int column = 0;
    int direction = 0;
    int right;
    int left;
    int max_height_column;

    while(column < heightSize - 2){
        right = higher(height,heightSize,column,direction,max_height_column);
        if(right != -1){
            WaterNum += NumCalculate(height,column,right,direction);
            printf("%d?\n",WaterNum);
            printf("%d?\n",WaterNum);
            column = right;
            printf("%d mmmmmmm\n",column);
        }
        else{//在它右边没有同高或更高的柱子
            max_height_column = column;
            column = heightSize - 1;
            direction = 1;
            break;
        } 
    }
    while(column != max_height_column && direction == 1){
        left = higher(height,heightSize,column,direction,max_height_column);
        if(left != -1){
            WaterNum += NumCalculate(height,left,column,direction);
            column = left;
            printf("%d 090909\n",column);
            printf("wqwq\n");
            printf("%d\n",direction);
        }
    }
    printf("%d+\n",WaterNum);
    return WaterNum;
}