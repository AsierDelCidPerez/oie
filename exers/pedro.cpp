
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void pedro(vector<int> & nums, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for(int i=0;i<nums.size()/k;i++){
        int max = nums[i];
        for(int j=i*k;j< k*(i+1);j++){
            if(nums[j] > max){
                if(j != i){
                    q.push({j, nums[j]});
                }
            }
        }
    }
}

int main(){
    int n, k;
    while(cin >> n >> k){
        vector<int> nums(n, -1);
        for(int i=0;i<n;i++){
            int c;
            cin >> c;
            nums[i] = c; 
        }

        pedro(nums, k);

    }
}