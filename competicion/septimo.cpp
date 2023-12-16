#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;


struct pila {

    int pos, ident;

};


bool operator<(const pila &a, const pila &b) {

    return a.ident > b.ident;

}


int main() {

    int T;

    cin >> T;


    while(T--) {

        int N;

        cin >> N;


        priority_queue<pila, vector<pila>, greater<pila>> heap;


        for(int i = 0; i < N; i++) {

            int K;

            cin >> K;


            for(int j = 0; j < K; j++) {

                int id;

                cin >> id;

                heap.push({j, id});

            }

        }


        int cola = 0;

        while(heap.size() > 1) {

            pila peek1 = heap.top(); heap.pop();

            pila peek2 = heap.top(); heap.pop();


            if(peek1.ident < peek2.ident) {

                cola += peek1.pos + 1;

                heap.push({peek1.pos, peek2.ident});

            } else {

                cola += peek2.pos + 1;

                heap.push({peek2.pos, peek1.ident});

            }

        }


        cout << cola << endl;

    }


    return 0;

}