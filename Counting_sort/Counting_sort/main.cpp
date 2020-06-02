//
//  main.cpp
//  Counting_sort
//
//  Created by Weishi on 5/30/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int getMax(vector<int> nums){
    int max=0;
    for(auto num:nums){
        max=std::max(max,num);
    }
    return max;
}
void counting_sort(vector<int> &nums,vector<int> &B,int max){
    vector<int> C(max+1,0);
    for (int i=0;i<nums.size();i++) {
        C[nums[i]]++;
    }
    
    for (int i=1; i<=max; ++i) {
        C[i]+=C[i-1];
    }
    
    for (int i=(int)nums.size()-1; i>=0; i--) {
        int num=nums[i];
        B[C[num]-1]=num;
        C[num]--;
    }
    
    return;
    
    
}
int main(int argc, const char * argv[]) {
    vector<int> nums={2,5,3,0,2,3,0,3};
    int max=getMax(nums);
    vector<int> sorted(nums.size(),0);
    counting_sort(nums, sorted, max);
    for(auto num:sorted){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
