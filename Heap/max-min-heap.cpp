#include<iostream>
#include<queue>
using namespace std;

int main(){
    //Min heap
priority_queue<int,vector<int>,greater<int>>pq_min;
pq_min.push(10);
pq_min.push(80);
pq_min.push(20);
pq_min.push(30);
cout<<pq_min.top();

//Max heap
priority_queue<int>pq_max;
pq_max.push(10);
pq_max.push(80);
pq_max.push(20);
pq_max.push(30);
cout<<pq_max.top();
}