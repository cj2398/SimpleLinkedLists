#include <iostream>
using namespace std;
template <typename T>
class Punto;

template<class T>
ostream& operator<<(ostream& o,const Punto<T>& p);

template <typename T>
class Punto{
T a,b;
public:
    Punto(T x=0,T y=0):a(x),b(y){}
    T getA(){return a;}
    T getB(){return b;}
    bool operator>(const Punto<T>& p){
        return (a+b>p.a+p.b)?true:false;
    }
    bool operator<(const Punto<T>& p){
        return (a+b<p.a+p.b)?true:false;
    }
    friend ostream& operator<<<T>(ostream& o,const Punto<T>& p);

};
template <class T>
ostream& operator<<(ostream& o,const Punto<T>& p){
        o<<"("<<p.a<<","<<p.b<<")";
        return o;
}
