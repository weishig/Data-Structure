//
//  main.cpp
//  最优搜索树
//
//  Created by Weishi on 6/14/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void construct_optimal_BST(vector<vector<float>> root, int i, int j){
    if (i<=j) {
        int r=root[i][j];
        if(r>i){
            int child=root[i][r-1];
            cout<<"k"<<child<<" is k"<<r<<" left child"<<endl;
            construct_optimal_BST(root, i, r-1);
        }
        else{
            cout<<"d"<<r-1<<" is k"<<r<<" left child"<<endl;
        }
        if (r<j) {
            int child=root[r+1][j];
            cout<<"k"<<child<<" is k"<<r<<" right child"<<endl;
            construct_optimal_BST(root, r+1, j);
        }
        else{
            cout<<"d"<<r<<" is k"<<r<<" right child"<<endl;
        }
        
    }
    return;
}
int main(int argc, const char * argv[]) {
    vector<float> p={0,0.15,0.1,0.05,0.1,0.2}; //ki的被搜索概率，其中坐标为1到n
    vector<float> q={0.05,0.1,0.05,0.05,0.05,0.1};// di的被搜索概率，其中index为0到n;
    int n=(int)p.size()-1;
    vector<vector<float>> e(n+2,vector<float> (n+1)); //e(i,j)用来保存index i to index j 的期望搜索代价. e(1...n+1, 0...n)
    vector<vector<float>> w(n+2,vector<float> (n+1)); //w(i,j)用来保存index i to index j 的概率和. w(1...n+1, 0...n)
    vector<vector<float>> root(n+1,vector<float>(n+1));
    for (int i=1; i<=n+1; ++i) {
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    
    for(int l=1;l<=n;++l){ //l为长度
        //以i为外层循环，这里由于长度是L，i最大为n-l+1，而j-i+1=L，j=L+i-1
        for (int i=1; i<=n-l+1; ++i) {
            int j=l+i-1;
            e[i][j]=INT_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for (int r=i; r<=j; ++r) {
                float t=e[i][r-1]+e[r+1][j]+w[i][j];
                if (t<e[i][j]) {
                    e[i][j]=t;
                    root[i][j]=r;
                }
            }
        }
    }
    cout<<"k"<<root[1][5]<<" is root"<<endl;
    construct_optimal_BST(root, 1, 5);
    return 0;
}
