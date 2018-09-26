#include <iostream>

using namespace std;

class Nodo{
private:
    int info;
    Nodo *sig;
    friend class ListaEnlazada;
};
class ListaEnlazada{
    Nodo *head;
    Nodo *tail;
  public:
    ListaEnlazada();
    bool isEmpty();
    void insertar(int dato);
    void imprimir();
    void insertarIncio(int dato);
    int tam();
    void insertarPos(int dato,int pos);
    void buscarValor(int dato);
    void buscarPos(int pos);
    void eliminarValor(int dato);
    void eliminarPos(int pos);
    void ordenar();
};
ListaEnlazada::ListaEnlazada(){
  head=NULL;
  tail=NULL;
}
bool ListaEnlazada::isEmpty(){
  if(head==NULL)
    return true;
  return false;
}
void ListaEnlazada::insertar(int dato){
  Nodo *nuevo=new Nodo;
  nuevo->info=dato;
  nuevo->sig=NULL;
  if(isEmpty()){
    head=nuevo;
    tail=nuevo;
  }
  else{
    tail->sig=nuevo;
    tail=nuevo;
  }
  //ordenar();
}
void ListaEnlazada::insertarIncio(int dato){
    Nodo *nuevo=new Nodo;
    nuevo->info=dato;
    if(isEmpty()){
        head=nuevo;
    }
    else{
        nuevo->sig=head;
        head=nuevo;
    }
    ordenar();
}

void ListaEnlazada::imprimir(){
  Nodo *aux=head;
  while(aux!=NULL){
      cout<<aux->info<<"-";
      aux=aux->sig;
    }
  cout<<endl;
}
int ListaEnlazada::tam(){
  int cant=0;
  Nodo *tmp;
  tmp=head;
  while(tmp!=NULL){
    cant++;
    tmp=tmp->sig;
  }
  return cant;
}
void ListaEnlazada::insertarPos(int dato,int pos){
  Nodo *nuevo=new Nodo;
  nuevo->info=dato;
  Nodo *aux=head;
  for(int i=0;i<pos;i++){
  /*  if(pos==0){
      insertarIncio(dato);
    }*/
    if(i==pos-1 ){
      nuevo->sig=aux->sig;
      aux->sig=nuevo;
    }
    aux=aux->sig;
  }
  ordenar();
}
void ListaEnlazada::buscarValor(int dato){
  Nodo *aux;
  aux=head;
  for(int i=0;i<tam();i++){
    if(aux->info==dato){
      cout<<"Se encuentra el la posicion : "<<i;
    }
    aux=aux->sig;
  }
}
void ListaEnlazada::buscarPos(int pos){
  Nodo *aux;
  aux=head;
  for(int i=0;i<tam();i++){
    if(i==pos-1){
      cout<<"EL valor en la pos: "<<pos<<" es "<<aux->info;
    }
    aux=aux->sig;
  }
}
void ListaEnlazada::eliminarValor(int dato){
  Nodo *aux,*aux2;
  aux=head;
  aux2=head;
  for(int i=0;i<tam();i++){
    if(aux->info==dato){
        Nodo *tmp;
        tmp=aux;
        aux2->sig=aux->sig;
        aux=aux->sig;
        if(i==0) head=aux;
        delete tmp;
    }else{
      if(aux!=head)aux2=aux2->sig;
      aux=aux->sig;
  }
  }
}
void ListaEnlazada::eliminarPos(int pos=0){
  Nodo *aux,*aux2;
  aux=head;
  aux2=head;
  for(int i=0;i<tam();i++){
    if(i==pos){
      Nodo *tmp;
      tmp=aux;
      aux2->sig=aux->sig;
      aux=aux->sig;
      if(i==0) head=aux;
      if(i==tam()-1) tail=aux2;
      delete tmp;
    }else{
      if(aux!=head)aux2=aux2->sig;
      aux=aux->sig;
    }
  }
}

void ListaEnlazada::ordenar(){
  Nodo *aux,*aux2;
  aux=head;
  int tmp;
  while(aux->sig!=NULL){
    aux2=aux->sig;
    while(aux2!=NULL){
      if(aux->info>aux2->info){
        tmp=aux2->info;
        aux2->info=aux->info;
        aux->info=tmp;
      }
      aux2 = aux2 -> sig;
    }
    aux = aux -> sig;
    aux2 = aux -> sig;
  }
}
int main(int argc, char const *argv[]) {
  ListaEnlazada lista;
  lista.insertar(100);
  lista.insertar(20);
  lista.insertar(35);
  lista.insertar(44);
  lista.imprimir();
  lista.eliminarPos();
  lista.imprimir();
  lista.eliminarPos();
  lista.imprimir();
  lista.eliminarPos();
  lista.imprimir();
  lista.eliminarPos();
  lista.imprimir();

  return 0;
}
