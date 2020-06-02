//
//  main.cpp
//  Insertion_Sort
//
//  Created by Weishi on 5/19/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector<int> &nums){
    for (int i=1; i<nums.size(); ++i) {
        int j=i;
        while (j-1>=0&&nums[j]<nums[j-1]) {
            int tmp=nums[j-1];
            nums[j-1]=nums[j];
            nums[j]=tmp;
            j--;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={5,2,4,6,1,3};
    InsertionSort(nums);
    return 0;
}
