#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
vector<int>heap;
    void heapifyUp_max(int i){
        while(i>0 && heap[i]>heap[(i-1)/2]){
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    void heapifyDown_max(int i){
        int n=heap.size();
        int left=2*i+1;
        int right=2*i+2;
        int max=i;
        if(left<n && heap[max]<heap[left]){
            max=left;
        }
        if(right<n && heap[max]<heap[right]){
            max=right;
        }
        if(max==i)return;
        swap(heap[max],heap[i]);
        heapifyDown_max(max);
    }

    public:
    void insert(int x){
        heap.push_back(x);
        heapifyUp_max(heap.size()-1);
    }

    void remove(){
        if(heap.empty())return;
        int i=heap.size()-1;
        swap(heap[i],heap[0]);
        heap.pop_back();
        heapifyDown_max(0);
    }

    int top(){
        return heap[0];
    }

    int extractMin(){
        int n=heap.size();
        int min=heap[n/2];
        for(int i=n/2;i<n;i++){
            if(heap[i]<min){
                min=heap[i];
            }
        }
        return min;
    }
    int extractMax(){
        int n=heap.size();
        int max=heap[n/2];
        for(int i=n/2;i<n;i++){
            if(max<heap[i]){
                max=heap[i];
            }
        }
        return max;
        // return heap[0];
    }
};

int main(){
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    // cout<<h.top()<<endl;
    // h.remove();
    // cout<<h.top()<<endl;
    cout<<h.extractMin()<<endl;
    cout<<h.extractMax();
}