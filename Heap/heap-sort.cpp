#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MaxHeap{
    vector<int>heap;



    void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
    }

    void heapifyUp(int i){
        int n=heap.size()-1;
        while(i>0 && heap[i]>heap[(i-1)/2]){
            swap(&heap[i],&heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    
    void heapify(int i,int n){
        // int n=heap.size();
        int left=2*i+1;
        int right=2*i+2;
        int max=i;

        if(left<n && heap[left]>heap[max]){
            max=left;
        }
        if(right<n && heap[right]>heap[max]){
            max=right;
        }

        if(max!=i){
            swap(&heap[max],&heap[i]);
            heapify(max,n);
        }
    } 

    public:

    MaxHeap(vector<int>arr){
        heap=arr;
        int n=heap.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(i,n);
        }
    }

    void extractMax(int n){
        // int n=heap.size();
        swap(&heap[0],&heap[n-1]);
        // n--;
        heapify(0,n-1);
    }


    // void insert(int x){
    //     heap.push_back(x);
    //     heapifyUp(heap.size()-1);
    // }
    // void remove(){
    //     int n=heap.size();
    //     swap(&heap[0],&heap[n-1]);
    //     heap.pop_back();
    //     heapify(0,n-1);
    // }

    void heapSort(){
        // buildHeap(arr);
        int on=heap.size();
        int n=on;
        for(int i=0;i<on;i++){
            extractMax(n);
            n--;
        }

        // arr=heap;

    }

    void print(){
        for(auto it:heap){
            cout<<it<<" ";
        }
    }
};

int main(){
    vector<int>arr={1,5,3,2,4};
    MaxHeap h(arr) ;
    // h.buildHeap(arr);
    h.print();
    cout<<endl;
    h.heapSort();
    // h.print();
}