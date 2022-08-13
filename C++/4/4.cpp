//
// Created by Susancutie on 2022/8/13.
//

class Solution {
public:
    double find_kth_num(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while(true){
            if(index1 == m){
                return nums2[index2 + k - 1];   //第一个数组为空
            }
            if(index2 == n){                    //第二个数组为空
                return nums1[index1 + k - 1];
            }
            if(k == 1){
                return min(nums1[index1], nums2[index2]); //当k为1时，取两数组开头的较小的数
            }
            int neWIndex1 = min(index1 + k / 2 - 1, m - 1);
            int neWIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[neWIndex1];
            int pivot2 = nums2[neWIndex2];
            if(pivot1 <= pivot2){
                k -= neWIndex1 - index1 + 1;
                index1 = neWIndex1 + 1;
            }
            else{
                k -= neWIndex2 - index2 + 1;
                index2 = neWIndex2 + 1;
            }
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        double result;
        if(length % 2 == 0) result = (find_kth_num(nums1, nums2, length/2) + find_kth_num(nums1, nums2, length/2+1))/2;
        else result = find_kth_num(nums1, nums2, (length+1)/2);
        return result;
    }


};


/*
1.判断数组长度的奇偶 若为奇，返回中间的数；若为偶，返回中间的两个数的平均数
2.find_kth_num()思路：
1）不断循环，在边界值处退出循环
2）边界情况为：其中一个数组为空或者k为1
*/