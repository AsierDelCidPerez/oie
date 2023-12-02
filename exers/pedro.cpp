
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> nums;
int n, k;

void pedro(){
    deque<int> q;
    int i=0;
    for(;i<k;i++){
        while(!q.empty() && nums[i] >= nums[q.back()]) // Quedarnos al frente con el mayor.
        {
            q.pop_back();
        }
        q.push_back(i); // Nos quedamos al frente con el mayor y a la derecha con todos los menores que son posteriores en index a este.
    }

    for(;i<n;i++){

        cout << nums[q.front()] << " ";

        while(!q.empty() && q.front() <= i-k) // Borrado de información que no nos interesa, estamos interesados en (i-k, i]. Ten en cuenta que al salir del bucle for; i = k-1
        {
            q.pop_front();
        }

        while(!q.empty() && nums[i] >= nums[q.back()]){ // Nos quedamos al frente con el numero mayor del intervalo (i-k, i]
            q.pop_back();
        }

        q.push_back(i);

    }

    cout << nums[q.front()] << "\n"; // Imprimos el último trabajo. Ten en cuenta que en el punto en que i = n-1 no se imprime en el bucle.

}

int main(){
    while(cin >> n >> k){
        if(n == 0 && k == 0) break;
        for(int i=0;i<n;i++){
            int c; cin >> c;
            nums.push_back(c);
        }
        pedro();
    }
}
