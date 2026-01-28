#include<iostream>
#include<vector>
#include <cstdlib>
using namespace std;

int pivot(vector<int>&v,int low,int high){
    int x= rand()%(-low+high+1)+low;
    int t1=v[x];
    v[x]=v[low];
    v[low]=t1;
    int i=low,j=high,pivot=v[low];
    while(i<j){
        while(v[i]<=pivot && i<=high){
            i++;
        }
        while(v[j]>pivot && j>=low){
            j--;
        }
        if(i<j){
            int t=v[i];
            v[i]=v[j];
            v[j]=t;
        }
    }
    int t=v[low];
    v[low]=v[j];
    v[j]=t;
    return j;
}

void quick(vector<int>&v,int low,int high){
    if(low<high){
        int partition=pivot(v,low,high);
        quick(v,low,partition-1);
        quick(v,partition+1,high);
    }
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
    quick(v,0,7);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}

