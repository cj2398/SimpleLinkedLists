//bibliografia
//https://www.youtube.com/watch?v=6nISt4ZrsBY
//https://sourcemaking.com/design_patterns/iterator/cpp/1
#include<iostream>
using namespace std;
template <class T>

class ListaEnlazadaSimple{
    class Nodo;
public:


    ListaEnlazadaSimple(){
        primero=ultimo=NULL;
    }
    class Iterador;

    Iterador inicio(){
        return Iterador(primero);
    }
    Iterador last(){//como decir n-1
        return Iterador(ultimo);
    }
    Iterador fin(){
        return Iterador(NULL);
    }
    class Iterador{

        public:
            Iterador() : nodoActual(primero){ }
            Iterador(Nodo *n){
                nodoActual=n;
            }
            Iterador&  operator=(Nodo *pNode){
                this->nodoActual=pNode;
                return *this;
            }
            Iterador& operator++(){ //++i
                if(nodoActual) nodoActual= nodoActual->sig;
                return *this;
            }
            Iterador operator ++(int){//i++
                Iterador iterador=*this;
                ++*this;
                return iterador;
            }
            bool operator!=(const Iterador& iterador){
                return nodoActual != iterador.nodoActual;
            }
            bool operator==(const Iterador& iterador){
                return nodoActual == iterador.nodoActual;
            }
            T operator *(){
                return nodoActual->elemento;
            }

            private:
            Nodo *nodoActual;

    };
    bool vacio(){
        return (primero==NULL);
    }
    void insertarAlInicio(T elemento)
    {
        Nodo *temp=new Nodo(elemento);
        if (vacio()){
            primero=ultimo=temp;
        }
        else{
            temp->sig=primero;
            primero=temp;
        }
    }
    void insertarAlFinal(T elemento)
    {
        Nodo *temp=new Nodo(elemento);
        if (vacio()){
            primero=ultimo=temp;
        }
        else{
            ultimo->sig=temp;
            ultimo=temp;
        }
    }
    void ordenarLista()
    {
         Nodo *actual , *siguiente;
         T temp;

         actual = primero;
         while(actual->sig != NULL)
         {
              siguiente = actual->sig;

              while(siguiente!=NULL)
              {
                   if(actual->elemento > siguiente->elemento)
                   {
                        temp = siguiente->elemento;
                        siguiente->elemento = actual->elemento;
                        actual->elemento = temp;
                   }
                   siguiente = siguiente->sig;
              }
              actual = actual->sig;
              siguiente = actual->sig;

         }

         cout<<"\n\n\tLista ordenada..."<<endl;
    }

    void borrarPrimerNodo()
    {
        if (vacio()){
            cout<<"Lista vacia!\n";
        }
        else{
            if (primero==ultimo){
                primero=ultimo=NULL;
                cout<<"elemento eliminado!\n";
            }
            else{
                Nodo *temp=primero;
                primero=primero->sig;
                delete temp;
                cout<<"elemento eliminado!\n";
            }
        }
    }
    void borrarUltimoNodo()
    {
        if (vacio()){
            cout<<"Lista vacia!\n";
        }
        else{
            if (primero==ultimo){
                primero=ultimo=NULL;
                cout<<"elemento eliminado\n";
            }
            else{
                Nodo *aux=primero;
                while(aux!=NULL){
                    if(aux->sig==ultimo){
                        Nodo *temp=ultimo;
                        ultimo=aux;
                        ultimo->sig=NULL;
                        delete temp;
                        cout<<"elemento eliminado\n";
                    }
                    aux=aux->sig;
                }
            }

        }
    }
    void mostrarLista(){
        if(vacio()){
            cout<<"No hay elementos en la lista\n";
        }
        else{
            Nodo *aux=primero;
            int i=0;
            cout<<"Los datos de la lista son los siguientes:\n";
            while(aux!=NULL){
                cout<<"El elemento "<<i<<" de la lista es: "<<aux->elemento<<endl;
                aux=aux->sig;
                i++;
            }
        }
    }
    private:
        class Nodo{
            T elemento;
            Nodo *sig;
            friend class ListaEnlazadaSimple;
        public:
            Nodo(T elemento){
                this->elemento=elemento;
                sig=NULL;
             }
        };
        Nodo *primero;
        Nodo *ultimo;
};



int main(){
    int a[6]={1,7,4,3,6,5};
    ListaEnlazadaSimple<int> le;
    for(int i=0;i<6;i++){
        le.insertarAlFinal(a[i]);
    }
    le.mostrarLista();
    le.ordenarLista();
    cout<<"con la funcion mostrar:\n";
    le.mostrarLista();
    le.borrarPrimerNodo();
    le.borrarUltimoNodo();
    cout<<"con el iterador: ";
    for ( ListaEnlazadaSimple<int>::Iterador it = le.inicio();
            it != le.fin(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}
