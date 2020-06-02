//
//  main.cpp
//  Merge_Sort
//
//  Created by Weishi on 5/21/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums,int l,int m,int r){
    int i=l;
    int p=m+1;
    vector<int> arr;
    while (l<=m &&p<=r) {
        if (nums[l]<nums[p]) {
            arr.push_back(nums[l++]);
        }
        else{
            arr.push_back(nums[p++]);
        }
    }
    
    while (l<=m) {
        arr.push_back(nums[l++]);
    }
    while (p<=r) {
        arr.push_back(nums[p++]);
    }
    
    for (int a=0; a<arr.size(); ++a) {
        nums[i++]=arr[a];
    }
    
    return;
    
}
void merge_sort(vector<int> &nums,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);
        merge(nums,l,mid,r);
    }
    return;
}
int main(int argc, const char * argv[]) {
    vector<int> nums={4,2,7,3};
    merge_sort(nums,0,(int)nums.size()-1);
    for(int num:nums){
        cout<<num;
    }
    cout<<endl;
    return 0;
}
