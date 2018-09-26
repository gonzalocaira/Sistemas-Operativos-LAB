#include <iostream>

using namespace std;
template <typename X>
class Nodo {
public:
    X prioridad;
    X tiempo_ejecucion;
    Nodo *sig;
};
template <typename X>
class Cola {
private:
    Nodo<X> *top;
    Nodo<X> *fondo;
    int tiempo;
public:
    Cola();
    ~Cola();
    void insertar(X x,X y);
    X extraer();
    void imprimir();
    bool empty();
    X extraer_corto();
    void corto();
    void corto_menor();
    void restar();
    Cola<X>& operator+(Cola &a);
    Cola<X>& operator-(Cola &a);
};

template <typename X>
Cola<X>::Cola(){
    top = NULL;
    fondo = NULL;
    tiempo= 1;
}

template <typename X>
Cola<X>::~Cola(){
    Nodo<X> *reco = top;
    Nodo<X> *bor;
    while (reco != NULL){
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

template <typename X>
void Cola<X>::insertar(X x,X y){
    Nodo<X> *nuevo;
    nuevo = new Nodo<X>;
    nuevo->prioridad = x;
    nuevo->tiempo_ejecucion=y;
    nuevo->sig = NULL;
    if (empty()){
        top = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }

}

template <typename X>
X Cola<X>::extraer(){
    if (!empty()){
        int prioridadrmacion = top->prioridad;
        Nodo<X> *bor = top;
        if (top == fondo){
            top = NULL;
            fondo = NULL;
        }
        else{
            top = top->sig;
        }
        delete bor;
        return prioridadrmacion;
    }
    else
        return -1;
}
template <typename X>
void Cola<X>::restar(){
  Nodo<X> *aux,*aux2;
  //Nodo<X> **p;
  //p=&top;
  aux=top;
  int tmp;
  if(empty()){
    cout<<"Proceso Nulo"<<endl;
  }
  else{
    if(aux->tiempo_ejecucion>1)
        aux->tiempo_ejecucion-=1;
    else{

      top=top->sig;
      delete aux;
    }
}
}

//para la prioridad mas corta y el tiempo_ejecucion
template <typename X>
void Cola<X>::corto(){
  Nodo<X> *aux,*aux2;
  aux=top;
  int tmp,tmp2;

  while(aux->sig!=NULL){
    aux2=aux->sig;
    while(aux2!=NULL){
      if(aux->prioridad>aux2->prioridad){
        tmp=aux2->prioridad;
        tmp2=aux2->tiempo_ejecucion;
        aux2->prioridad=aux->prioridad;
        aux2->tiempo_ejecucion=aux->tiempo_ejecucion;

        aux->prioridad=tmp;
        aux->tiempo_ejecucion=tmp2;
      }
      /*if(aux->tiempo_ejecucion>aux2->tiempo_ejecucion){
        tmp=aux2->tiempo_ejecucion;
        tmp2=aux2->prioridad;
        aux2->tiempo_ejecucion=aux->tiempo_ejecucion;
        aux->tiempo_ejecucion=tmp;
      }*/

      aux2 = aux2 -> sig;
    }
    aux = aux -> sig;
    aux2 = aux -> sig;
  }
}
template <typename X>
void Cola<X>::corto_menor(){
  Nodo<X> *tmp=top;
  Nodo<X> *tmp2=top;
  Nodo<X> *aux3;
  int menor_prioridad=tmp->prioridad;
  int menor_tiempo=0;
  while((tmp->sig)=NULL)
  {
    if((tmp->sig)->prioridad<menor_prioridad)
      menor_prioridad=(tmp->sig)->prioridad;
      menor_tiempo=(tmp->sig)->tiempo_ejecucion;
    tmp=tmp->sig;
  }
  while(tmp2!=NULL){
    if(tmp2->prioridad==menor_prioridad)
        aux3=tmp2;
    tmp2=tmp2->sig;
  }
  int top_prioridad=tmp->prioridad;
  int top_tiempo=tmp->tiempo_ejecucion;
  int aux,aux2;
  aux=top_tiempo;
  aux2=top_prioridad;
  tmp->prioridad=menor_prioridad;
  tmp->tiempo_ejecucion=menor_prioridad;
  aux3->prioridad=aux2;
  aux3->tiempo_ejecucion=aux;
}


template <typename X>
void Cola<X>::imprimir(){
    Nodo<X> *reco = top;
    cout << "Listado de todos los procesos.\n";
    tiempo=1;

    while (reco != NULL){
        //if(reco->tiempo_ejecucion<=0)reco=reco->sig;
        cout <<"procesando.... "<<endl;
        cout <<"Tiempo " <<tiempo <<"\t";
        cout <<"Prioridad :"<< reco->prioridad << "\t";
        cout <<"Tiempo :"<< reco->tiempo_ejecucion <<endl;
        reco = reco->sig;
        tiempo++;
    }
    cout << "\n";

}

template <typename X>
bool Cola<X>::empty(){
    if (top == NULL)
        return true;
    else
        return false;
}
template <typename X>
Cola<X>& Cola<X>::operator+(Cola<X> &a){
    Cola<X> tmp;
    fondo->sig=a.top;
    fondo = a.fondo;
    Nodo<X> *aux1;
    Nodo<X> *aux2;
    Nodo<X> *aux3;
    aux1=top;
    aux2=top->sig;
    aux3=top;
    while(aux1!=fondo){
        while(aux2!=NULL){
            if(aux1->prioridad==aux2->prioridad){
                Nodo<X> *tmp;
                tmp=aux2;
                aux2=aux2->sig;
                aux3->sig=aux2;
                delete tmp;
            }else{
            if(aux2!=NULL){
                aux2=aux2->sig;
                aux3=aux3->sig;
            }}
        }

        aux1=aux1->sig;
        aux2=aux1->sig;
        aux3=aux1;

    }
    return *this;
}

template <typename X>
Cola<X>& Cola<X>::operator-(Cola<X> &a){
    Nodo<X> *aux1;
    Nodo<X> *aux2;
    Nodo<X> *aux3;
    aux1=top;
    aux3=top;
    aux2=a.top;
    int var=0;
    while(aux1!=NULL){
        while(aux2!=NULL){
            if(aux1->prioridad==aux2->prioridad){
                Nodo<X> *ptr;
                ptr=aux1;
                aux1=aux1->sig;
                aux3->sig=aux1;
                var=1;
                if(ptr==top){
                    aux3=aux1;
                    top=aux1;
                }
                delete ptr;
            }
            else{
                aux2=aux2->sig;
                var=0;
            }
        }
    if(fondo==NULL)fondo=aux3;
    if(var!=1){
        if(aux1!=top)aux3=aux3->sig;
        if(aux1!=NULL)aux1=aux1->sig;
    }
    aux2=a.top;
    }
    return *this;
}

int main(){
    Cola<int> cola1;
    cola1.insertar(10,8);
    //cola1.imprimir();
    cola1.restar();
    cola1.insertar(18,14);
    cola1.corto();
    cola1.restar();
    //cola1.imprimir();
    cola1.insertar(8,6);
    cola1.corto();
    cola1.restar();

    int op;
    cout<<"1)Crear Proceso o 2)Imprimir  ";
    //cout<<"2)imprimir:"<<endl;
    cin>>op;
    while(op!=0){

      if(op==1){
        int prioridad,t_ejecucion;
        cout<<"Prioridad :";
        cin>>prioridad;
        cout<<"Tiempo de ejecucion : ";
        cin>>t_ejecucion;
        cola1.insertar(prioridad,t_ejecucion);
        cout<<endl;
      }
      if(op==2){
        cola1.corto();
        //cola1.restar();
        cola1.imprimir();
        cola1.restar();
      }
      if(op==3){cola1.restar();}
      cout<<"1)Crear Proceso o 2)Imprimir ";
      //cout<<"2)imprimir:"<<endl;
      cin>>op;
    }


    return 0;
}
