#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;


int busquedaBinaria(int n, int item){
    vector<int> numbers;
    while(n--) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    int l = 0;
    int r = n-1;
    
    while(l <= r){
        int med = (l+r) / 2;
        if(numbers[med] == item){
            return med;
        }else if(numbers[med] < item){
            l = med + 1;
        }else {
            r = med - 1;
        }
    }

    
    // Segunda forma para obtener la primera aparición:

    /*
        v[0...l] < B
        v[r...N) >= B
    */

   while(l+1 < r){
        /*
            Se cumplen las invariantes:
                -> v[0...l] < B
                -> v[r...N] >= B
        */

        int m = (l+r)/2;
        if(numbers[m] < item){
            l = m;
        }else{
            r = m;
        }
   }

    if(r < n && numbers[r] == item) { // Si el item buscado es mayor que el máximo de la lista entonces r será n
        cout << r << "\n";
    }else{
        cout << l << "\n";
    }

    /*
        Si cambiamos los invariantes del bucle a:
            -> v[0...l]<= B
            -> v[r...N] > B
        Entonces obtendrá el valor cuyo índice sea mayro.
    */

   cout << "Esta por primera vez en " << r << "\n";
   l = 0;
   r = n;

      while(l+1 < r){

        /*
            Se cumplen las invariantes
                -> v[0...l] <= B
                -> v[r...N] > B
        */

        int m = (l+r)/2;
        if(numbers[m] <= item){
            l = m;
        }else{
            r = m;
        }
   }

   cout << "Está por última vez en " << l << "\n";
}

int raizArcaica(int n, int item){
    
    int l = 1;
    int r = n+1;

    while(l+1 < r){
        /*
            Cumplimos las invariantes de:
                -> l^2 <= 150
                -> r > n+1
        */

       ll mid = (l+r)/2;

       if(mid*mid <= item){
        l = mid;
       }else{
        r = mid;
       }
    }

    cout << "raíz: " << l << "\n";

}

int N, V;
vector<int> pesos;

bool sepuede(int m){ // las obras no se pueden partir
    int viajes = 0;
    int peso = 0;
    for(int i=0;i<N;i++){
        if(peso + pesos[i] <= m) {
            peso += pesos[i];
        }else{ // El i se va en otro viaje.
            ++viajes;
            peso = pesos[i];
            if(peso > m) return false;
            
        }
    }
}

void exposicionArte(){
    while(cin >> N){
        if(N == 0) break;
        pesos.assign(N, 0);
        cin >> V;
        int sumaPesos = 0;
        for(int & x : pesos) {
            cin >> x;
            sumaPesos += x;
        }

        int l=0, r=sumaPesos;
        // con un camión que soporte l NO podemos hacer la mudanza en V viajes
        // Con un camión que soporte r, SÍ.

        while(l+1 < r){
            int m = (l+r)/2;
            if(sepuede(m)){
                r = m;
            }else{
                l = m;
            }
        }

        cout << r << "\n";

    }
}

int main(){
    exposicionArte();
}