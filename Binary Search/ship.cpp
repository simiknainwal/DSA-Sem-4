class Solution {
public:
    int canShip(int wt,vector<int>w,int d,int n){
        int total=0;
        // while(d--){
            for(int i=0;i<n;i++){
            total+=w[i];
            if(total>wt){
                d--;
                total=0;
                i--;
                // break;
            
            }else if(total<=wt && i==n-1){
                d--;
                total=0;
            }
            
            }
            if(d==0){
                return 1;
            }
            return 0;
        // }
        // if(total==sum)return 1;
        // return 0;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int max=INT_MIN;
        for(int i=0;i<weights.size();i++){
            if(max<weights[i]){
                max=weights[i];
            }
            sum+=weights[i];
        }
        int n=weights.size();
        for(int i=max;i<sum;i++){
            if(canShip(i,weights,days,n)){
                return i;
            }
        }
        return -1;
    }
};