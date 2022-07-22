//
// Created by Susancutie on 2022/7/22.
//

int removeElement(int* nums, int numsSize, int val){
    if(numsSize==1 && nums[0]==val)return 0;
    int head = 0;
    int tail = numsSize - 1;
    int switch_;
    while(head < tail){
        while(head <= tail && nums[tail]==val){
            tail--;
        }
        while(head < tail && nums[head]!=val){
            head++;
        }
        if(head>=0 && head<numsSize && tail>=0 && head<numsSize){
            switch_ = nums[head];
            nums[head] = nums[tail];
            nums[tail] = switch_;
        }
    }
    int left_num = tail + 1;
    return left_num;
}