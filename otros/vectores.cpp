#include <iostream>
#include <cmath>

using namespace std;

struct V3d{
    int x, y, z;
    V3d(int a, int b, int c) : x(a), y(b), z(c){}

    V3d operator + (V3d a){
        return V3d(a.x + x, a.y + y, a.z + z);
    }

    V3d operator * (int k){
        return V3d(x * k, y * k, z*k);
    }

    V3d operator - (V3d a){
        return V3d(x, y, z) + a * (-1);
    }
    
    void operator *= (int k){x *= k; y *= k; z *= k;}
    void operator += (V3d a){x += a.x; y += a.y; z += a.z;}
    void operator -= (V3d a){x -= a.x; y -= a.y; z -= a.z;}

    int operator * (V3d a){
        return a.x * x + a.y * y + a.z * z;
    }

    V3d operator ^ (V3d c){ // Producto vectorial
        return V3d(y * c.z - c.y * z, c.x * z - x*c.z, x * c.y - c.x * y);
    }

    int modulo(){
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
    
    void print(bool espacio=false){
        cout << "(" << x << ", " << y << ", " << z << ")" << ((espacio) ? "\n" : ""); 
    }
};

V3d operator * (int k, V3d a){
    return V3d(a.x * k, a.y * k, a.z*k);
}