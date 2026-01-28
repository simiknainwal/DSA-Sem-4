#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int exercise(int* arr,int N,int E){
    int min=INT_MAX,s=0;
    for(int i=0;i<N;i++){
        if(arr[i]>=E){
            if(min>arr[i])min=E;
        }else if(arr[i]<E){
            s+=arr[i];
        }
    }
    if(min!=INT_MAX){

        if(s>=E){
            
        }
    }
}