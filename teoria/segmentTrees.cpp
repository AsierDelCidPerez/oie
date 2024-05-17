#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

inline int IZQD(int n) {return 2*n; };
inline int DECHA(int n) {return 2*n+1;}

struct segmentTree {
    vector<int> st;
    vector<int> pending;
    int numElems;

    segmentTree(int n): numElems(n), st(4*n, 0), pending(4*n, 0) {

    }
    segmentTree(const vector<int> & v): numElems(v.size()), st(4*v.size()), pending(4*v.size(), 0) {
        init(1, 0, numElems-1, v);
    }

    int query(int a, int b){

    }

    void update(int pos, int val){

    }

    void update(int pos, int val){
        update(1, 0, numElems-1, pos, val);
    }

    void update(int node, int l, int r, int pos, int val){
        assert((l <= pos) && (pos <= r));

        if(l == r){
            st[node] = val;
        }

        // Caso recursivo

        int m = (l+r)/2;

        if(pos <= m){
            // La actualización implica al hijo izqd
            update(IZQD(node), l, m, pos, val);
        }else{
            update(DECHA(node), m+1, r, pos, val);
        }

        st[node] = st[IZQD(node)] + st[IZQD(node)];

    }

    int query(int node, int l, int r, int a, int b){
        // Sanity check; [a..b] está en [l...r]
        assert((l<=b) && (a <= r));

        // Resolvemos la operación pendiente
        solvePendingUpdates(node, l, r);


        if((a<=l) && (r<=b)){
            return st[node];
        }

        int m = (l+r)/2;
        int izqd, dcha;
        if(a <= m){
            izqd = query(IZQD(node), l, m, a, b);
        }else{
            dcha = query(DECHA(node), m+1, r, a, b);
        }

        if(b <= m){
            return izqd;
        }else{
            return dcha;
        }
        return izqd + dcha;

    }

    void updateRange(int a, int b, int val){
        updateRange(1, 0, numElems-1, a, b, val);
    }


    void updateRange(int node, int l, int r, int a, int b, int val){
        solvePendingUpdates(node, l, r);

        if((b < l) || (r < a)){
            // La actualización no nos afecta
            return;
        }

        if((a <= l) && (r <= b)){
            // La actualización nos afecta por completo
            addPendingUpdate(node, l, r, val);
            solvePendingUpdates(node, l, r);
            return;
        }

        // Caso recursivo

        int m = (l+r) / 2;

        updateRange(IZQD(node), l, m, a, b, val);
        updateRange(DECHA(node), l, m, a, b, val);

        st[node] = st[IZQD(node)] + st[DECHA(node)];

    }

    void addPendingUpdate(int node, int l, int r, int val){
        pending[node] += val;

    }

    void solvePendingUpdates(int node, int l, int r){
        if(pending[node] == 0) { //OP
            return;
        }

        st[node] += (r-l+1) * pending[node];

        // Trasladar la operación pendiente a los hijos
        if(l != r){
            int m = (l+r) / 2;
            addPendingUpdate(IZQD(node), l, m, pending[node]);
            addPendingUpdate(DECHA(node), l, m, pending[node]);
        }

        // Borramos la operación pendiente
        pending[node] = 0;

    }

    void init(const vector<int> &v, int node, int l, int r){
        if(l == r){
            st[node] = v[l];
            return;
        }

        int m = (l+r)/2;
        init(v, IZQD(node), l, m);
        init(v, DECHA(node), m+1, r);

        st[node] = st[IZQD(node)] + st[DECHA(node)];
    }

};

int main(){
    
}