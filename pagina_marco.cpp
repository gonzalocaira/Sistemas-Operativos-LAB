#include "iostream"
#include "fstream"

using namespace std;

template <typename T>
class Marco{
public:
    T m_dato;
    T capacidad;
    string name_P;
    bool activar;
    Marco<T> *m_pSig;
  public:
    Marco(T d,T e,string f):m_dato(d),m_pSig(0),capacidad(e),name_P(f),activar(false){}
};

template <typename T>
class Pagina{
private:
  Marco<T> *m_pHead;
  Marco<T> *m_pTail;
  T tam_total;
public:
  Pagina(){
    m_pHead=NULL;
    m_pTail=NULL;
  }
  bool isEmpty();
  bool find_R(T d,Marco<T> *&p);
  void add_R(T d,T e,string f,Marco<T> *&p);
  void add(T d,T e,string f);
  void print_R();
  void add_I(T d);
  bool find(T d,Marco<T> **&p);
  bool add_E(T d);
  void add_R_again(T d,T e,string f,Marco<T> *&p);
  void add_again(T d,T e,string f);
};
template <typename T>
bool Pagina<T>::isEmpty(){
  if(m_pHead==NULL)return true;
  return false;
}

template <typename T>
bool Pagina<T>::find_R(T d,Marco<T> *&p){
  if(!p){return false;}
  if(p->m_dato==d)return true;
  return find(d,p->m_pSig);
}

template<typename T>
void Pagina<T>::add_R(T d,T e,string f,Marco<T> *&p){
  if(!p){
    T tmp=d;
    while(tmp>e){
      T tmp=d-e;
      d=tmp;
      p=new Marco<T>(tmp,e,f);
      return add_R(d,e,f,p->m_pSig);
    }
    p=new Marco<T>(d,e,f);
    return;
  }
  return add_R(d,e,f,p->m_pSig);
}
template <typename T>
void Pagina<T>::add_R_again(T d,T e,string f,Marco<T> *&p){
  if(!p){
    if(p->activar==false){
      p->activar=true;
      T tmp=d;
      while(tmp>e){
        T tmp=d-e;
        d=tmp;
        p=new Marco<T>(tmp,e,f);
        return add_R(d,e,f,p->m_pSig);
      }
    }
    p=new Marco<T>(d,e,f);
    return;
  }
  return add_R(d,e,f,p->m_pSig);
}

template <typename T>
void Pagina<T>::add(T d,T e,string f){
  add_R(d,e,f,m_pHead);
}
template <typename T>
void Pagina<T>::add_again(T d,T e,string f){
  add_R_again(d,e,f,m_pHead);
}
template <typename T>
void Pagina<T>::print_R(){
  Marco<T> *p=m_pHead;
  cout<<"PROCESOS"<<"\t"<<"Disminucion"<<"\t"<<"Bytes"<<"\t"<<"TAMAÑO"<<endl;
  while(p!=NULL){
    //if(p->activar==false){
      //cout<<p->name_P<<"\t"<<"------"<<"\t"<<p->capacidad<<endl;
    //}else{
    if(p->m_dato==0){
      cout<<p->name_P<<"\t"<<p->m_dato<<"\t\t"<<"0"<<"\t"<<p->capacidad<<endl;//}
    }else{
    cout<<p->name_P<<"\t"<<p->m_dato<<"\t\t"<<p->capacidad<<"\t"<<p->capacidad<<endl;}
    p=p->m_pSig;

  }
}

int main(int argc, char const *argv[]) {
  Pagina<int> Registro;
  for(int i=0;i<30;i++){
    Registro.add(0,3,"Proceso NULL");
  }
  Registro.add_again(6,3,"Proceso 1");
  Registro.add_again(9,3,"Proceso 2");
  Registro.add_again(12,3,"Proceso 3");
  Registro.print_R();
  return 0;
}
