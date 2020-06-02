//
//  main.cpp
//  quick_sort
//
//  Created by Weishi on 5/17/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
int partition(vector<int> &nums,int l,int r){
    int mid=(l+r)/2;
    while (true) {
        while (nums[r]>nums[mid]) {
            r--;
        }
        while (nums[l]<nums[mid]) {
            l++;
        }
        if (l>=r) {
            return l;
        }
        else{
            int tmp=nums[l];
            nums[l]=nums[r];
            nums[r]=tmp;
            ++l;
            --r;
        }
        
    }

}
void QuickSort(vector<int> &nums,int l,int r){
    if (l>=r) {
        return;
    }
    int p=partition(nums,l,r);
    QuickSort(nums, l, p);
    QuickSort(nums, p+1, r);
    return;

}*/
void swap(vector<int> &nums,int i,int j){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
    return;
}
int partition(vector<int> &nums,int l, int r){
    int pivot=nums[r];
    int i=l-1;
    int j=0;
    for (j=l; j<=r-1; j++) {
        if (nums[j]<=pivot) {
            i++;
            swap(nums,i,j);
        }
    }
    
    swap(nums,i+1,j);
    
    
    return i+1;
}
void quick_sort(vector<int> &nums,int l, int r){
    if (l<r) {
        //int mid=(l+r)/2;
        int i=partition(nums,l,r);
        quick_sort(nums, l, i-1);
        quick_sort(nums, i+1, r);
    }
    return;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={1,2,3,4};
    quick_sort(nums,0,(int) nums.size()-1);
    cout<<"res:"<<endl;
    for (auto num:nums) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
