#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&v,int low,int mid,int high){
    int left=low,right=mid+1,k=0;
    vector<int> a(high-low+1);
    while(left<=mid && right<=high){
        if(v[left]<=v[right])a[k++]=v[left++];
        else a[k++]=v[right++];
    }

    while(left<=mid)a[k++]=v[left++];
    while(right<=high)a[k++]=v[right++];

    for(int i=low;i<=high;i++){
        v[i]=a[i-low];
    }
    
}

void mergeSort(vector<int>&v,int low,int high){
    if(low==high){
    return;
    }
        int mid = (low +high)/2;
        mergeSort(v,low,mid); 
        mergeSort(v,mid+1,high);
        merge(v,low,mid,high); 
    
}

int main(){
    vector<int>v;
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(1);
    v.push_back(3);
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    
    mergeSort(v,0,7);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}

