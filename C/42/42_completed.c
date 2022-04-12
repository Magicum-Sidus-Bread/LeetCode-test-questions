int higher(int* height,int heightSize,int column){
    if(column == heightSize - 1) return -1;
    for(int i = column + 1;i < heightSize;i++){
        if(height[i] >= height[column]) return i;
    }
    return -1;
}
int NumCalculate(int* height,int left,int right){
    if(right == left + 1) return 0;
    int total = (right - left - 1) * height[left];
    int bar_sum = 0;
    for(int i = left + 1;i < right;i++){
        bar_sum += height[i];
    }
    int water_num = total - bar_sum;
    return water_num;
}
int NumCalculate_lower(int* height,int left,int right){
    if(right == left + 1) return 0;
    int total = (right - left - 1) * height[right];
    int bar_sum = 0;
    for(int i = left + 1;i < right;i++){
        bar_sum += height[i];
    }
    int water_num = total - bar_sum;
    return water_num;
}

int compare(int* height,int column,int lower){
    for(int p = lower - 1;p >= column;p--){
        if(NumCalculate_lower(height,p,lower) > 0) return p;
    }
    return -1;
}

int trap(int* height, int heightSize){
    int WaterNum = 0;
    int column = 0;
    int right;
    while(column < heightSize - 2){
        right = higher(height,heightSize,column);
        if(right == -1){//在它右边没有同高或更高的柱子
            int lower = column + 2;
            while(lower < heightSize - 1 && compare(height,column,lower)==-1){
                lower++;
                printf("121212\n");
            }
            printf("%d 3333\n",lower);
            column = compare(height,column,lower);
           
            printf("%d9999\n",column);
            if(column!=-1){
            WaterNum += NumCalculate_lower(height,column,lower);
            printf("%d!\n",WaterNum);}
            column = lower;
            printf("%d)))\n",column);
            
        } 
        else{
            WaterNum += NumCalculate(height,column,right);
            printf("%d?\n",WaterNum);
            column = right;
        }
    }
    printf("%d+\n",WaterNum);
    return WaterNum;
}