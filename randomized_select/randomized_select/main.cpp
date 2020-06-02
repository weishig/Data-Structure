//
//  main.cpp
//  randomized_select
//
//  Created by Weishi on 6/1/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
using namespace std;
void swap(vector<int> &nums,int i,int j){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
    return;
}

int partition(vector<int> &nums,int l,int r){
    int pivot=nums[r];
    int left=l-1;
    for (int i=l; i<=r; ++i) {
        if (nums[i]<=pivot) {
            left++;
            swap(nums, left,i);
        }
    }
    swap(nums, left+1,r);
    return left+1;
}

int randomized_partition(vector<int> &nums,int l,int r){
    int a=0;
    int b=(int)nums.size()-1;
    srand(int(time(0)));
    int random_val=(std::rand()%(b-a+1))+a;
    swap(nums,r,random_val);
    return partition(nums,l,r);
    
}

int randomized_select(vector<int> &nums,int l,int r,int index){
    if (l==r) {
        return nums[l];
    }
    int i=randomized_partition(nums, l, r);
    if (i==index) {
        return nums[i];
    }
    else if(i<index){
        return randomized_select(nums, i+1, r, index);
    }
    else{
        return randomized_select(nums, l, i-1, index);
    }

}

int main(int argc, const char * argv[]) {
    vector<int> nums={3,2,9,0,7,5,4,8,6,1};
    int res=randomized_select(nums,0,(int)nums.size()-1,3); //找出第二小的元素
    cout<<res<<endl;
    return 0;
}
