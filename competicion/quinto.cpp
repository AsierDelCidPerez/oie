#include <iostream>

#include <deque>

#include <vector>


using namespace std;


void bfs(int n, int m, int t) {

    deque<int> q;

    q.push_back(1);


    for (int i = 0; i < t; i++) {

        int s = q.size();

        while (s--) {

            int j = q.front();

            q.pop_front();

            if (j < m) {

                q.push_back(j + 1);

            } else {

                q.push_back(j - n + 1);

                q.push_back(j + 1);

            }

        }

    }


    cout << q.size() << "\n";

}


int main() {

    int t, n, m;

    while (cin >> n >> m >> t) {

        bfs(n, m, t);

    }


    return 0;

}