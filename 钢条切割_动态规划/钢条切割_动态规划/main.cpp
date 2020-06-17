//
//  main.cpp
//  钢条切割_动态规划
//
//  Created by Weishi on 6/11/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int Memorized_cut_rod_aux(vector<int> price_table,int length,vector<int> dp_table){//自顶向下
    if (dp_table[length]>=0) {
        return dp_table[length];
    }
    
    int q=-INT_MAX;
    for (int i=1; i<=length; ++i) {
        q=max(q,price_table[i]+Memorized_cut_rod_aux(price_table, length-i, dp_table));
    }
    dp_table[length]=q;
    return q;
}

int Memorzized_cut_rod( vector<int> price_table,int length){
    vector<int> dp_table(length+1,-INT_MAX);
    dp_table[0]=0;
    dp_table[1]=1;
    return Memorized_cut_rod_aux(price_table, length, dp_table);
}

int main(int argc, const char * argv[]) {
    vector<int> price_table{0,1,5,8,9,10,17,20,24,30};
    int length=4;
    int res=Memorzized_cut_rod( price_table,length);
    cout<<res<<endl;
    
    return 0;
}
