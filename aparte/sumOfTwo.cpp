#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> nums(N, -1);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int T; cin >> T;

    while(T--){
        int k; cin >> k;
        
        int l = 0;
        int r = N-1;

        while(nums[l] + nums[r] != k){
            int suma = nums[l] + nums[r];
            if(suma > k){
                --r;
            }else{
                ++l;
            }
        }

        cout << l+1 << " " << r+1 << "\n";
    }



}