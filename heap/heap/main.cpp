

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include "Node.cpp"
#include <algorithm>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int Left(int i){
    return 2*i+1;
}
int Right(int i){
    return 2*i+2;
}
int parent(int i){
    if (i==1 ||i==2) {
        return 0;
    }
    return i/2;
}
void max_heapify(vector<int>& heap,int i,int size){
    //int size=(int)heap.size();
    
    
    while (true) {
        int left=Left(i);
        int right=Right(i);
        int largest=0;
        
        if (left<size && heap[left]>heap[i]) {
            largest=left;
        }
        else{
            largest=i;
        }
        
        if(right<size && heap[largest]<heap[right]){
            largest=right;
        }
        if(largest==i) break;
        
        int tmp=heap[largest];
        heap[largest]=heap[i];
        heap[i]=tmp;
        i=largest;
     
    }
    
    return;
}

void build_max_heap(vector<int> &heap){
    int size=(int) heap.size();
    for(int i=size/2-1;i>=0;--i){
        if(i==1){
            
        }
        max_heapify(heap, i,size);
    }
    
}
/*
void sort_heap(vector<int> &heap){
    int size=(int)heap.size();
    for (int i=size-1; i>=0; i--) {
        int tmp=heap[0];
        heap[0]=heap[i];
        max_heapify(heap, 0, size--);
        heap[i]=tmp;
    }
}*/
void push_heap(vector<int> &heap,int k){
    if(k>heap[0]) return;
    
    heap[0]=k;
    max_heapify(heap, 0, (int)heap.size());
    
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> heap(k);
    int i=0;
    for(i=0;i<k;++i){
        heap[i]=arr[i];
    }
    
    build_max_heap(heap);
    while (i<arr.size()) {
        push_heap(heap,arr[i++]);
        
    }
    
    return heap;

}
int main(int argc, const char * argv[]) {
    vector<int> arr={16,4,10,14,7,9,3,2,8,1};
    int k=2;
    
    vector<int> res=getLeastNumbers(arr, k);
    for(int r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 1;
}
