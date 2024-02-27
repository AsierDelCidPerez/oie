#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> nums;
    for(int i=0;i<N;i++){
        int c; cin >> c;
        nums.push_back({c, i});
    }

    sort(nums.begin(), nums.end());

    int T; cin >> T;

    while(T--){
        int k; cin >> k;
        
        int l = 0;
        int r = N-1;

        while(nums[l].first + nums[r].first != k){
            int suma = nums[l].first + nums[r].first;
            if(suma > k){
                --r;
            }else{
                ++l;
            }
        }

        cout << nums[l].second+1 << " " << nums[r].second+1 << "\n";
    }
}