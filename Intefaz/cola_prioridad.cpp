#include <time.h>
#include "persona.h"
#include <unistd.h>

using namespace std;

template<class T>
class Nodo
{
     public:
          T      m_Dato;
          T   m_prioridad;
          T   m_tiempo;
          Nodo<T> * m_pSig;
          Nodo<T> * m_pAnt;
     public:
         Nodo(int d, int p){
           m_pSig=0;
           m_pAnt=0;
           m_Dato=d;
           m_prioridad=p;
           m_tiempo=p;
         };//:m_Dato(d),m_pSig(0){};
};

template<class T>
class Lista_D
{
    public:
        Nodo<T> *  m_pHead;
        Nodo<T> *  m_pTail;
    public:
       Lista_D():m_pHead(0),m_pTail(0){};

       bool IsEmpty(){
         return !m_pHead;
       }

       bool AddDato(T d){
         Nodo<T> * pNuevo = new Nodo<T>(d);
       }

       bool find_R(T  d, Nodo<T> * & p)
       {
              if(!p){return false;}
              if (p->m_Dato == d) {return true;}
              return find_R(d,p->m_pSig);

       }


       void Add_R(T  d, Nodo<T> * &  p)
       {
              if(!p){p = new Nodo<T>(d); return; }
              return Add_R(d,p->m_pSig);

       }
       void Add(T d)
       {
               Add_R(d,m_pHead);
       }
       void print_R(Nodo<T> *  p, int i)
       {
              if(!p||i==1){return ;}
              cout<<p->m_Dato<<"  "<<p->m_prioridad<<"  "<<p->m_tiempo<<endl;
              //os<<p->m_Dato<<endl;
              return print_R(p->m_pSig,i);

       }

       void Add_I(T d)
       {
            Nodo<T> * pNuevo = new Nodo<T>(d);
            if(!m_pHead)
         {
            m_pHead = pNuevo;
            return;
         }
         Nodo<T> * tmp = m_pHead;
         for( ; tmp->m_pSig; tmp=tmp->m_pSig);
         tmp->m_pSig = pNuevo;


       }

       bool find(T d, Nodo<T>  ** & p)
       {
               p = &m_pHead;
               while(*p)
               {
                   if ((**p).m_Dato == d) return true;
                   if ((*p)->m_Dato > d) return false;
                   p = &((*p)->m_pSig);
               }

               return false;
       }

       //void pros_none(){
      //}


       void tiempo(T dis){
         m_pHead->m_tiempo=m_pHead->m_tiempo-dis;
         //cout<<"tiempo "<<m_pHead->m_tiempo<<endl;
         //if (m_pHead->m_tiempo==0){
           //Nodo <T> aux=m_pHead;
           //m_pHead=m_pHead->m_pSig;
          // delete aux;
         //}
       }
       void tiempo_mostrar(T dis, T i){
         m_pHead->m_tiempo=m_pHead->m_tiempo-dis;
         unsigned int microseconds;
        usleep(microseconds);
        //int i=0;
         while (i!=1){
           m_pHead->m_tiempo=m_pHead->m_tiempo-dis;
           cout<<"procesos realizados "<<endl;
         print_R(m_pHead,i);
         if (m_pHead->m_tiempo==0) m_pHead=m_pHead->m_pSig;
         usleep(1000000);
       }}
      bool AddE(T d,T p)
      {
            Nodo<T>  ** q;
            if(find(d,q)){
              //revisar la segunda prioridad - esta fallando -
              if(find(p,q))return false;
                Nodo<T> * tmp = *q;
                *q = new Nodo<T>(d,p);
                (*q)->m_pSig = tmp;
                return true;

            }
            Nodo<T> * tmp = *q;
            *q = new Nodo<T>(d,p);
            (*q)->m_pSig = tmp;
            return true;
        }
};
int main()
{
      Lista_D <int>  A;
      //int pros_new=rand()%10;
      int menu=5;
      int pros, prio;
      while(menu!=4){
      //while (menu==2){
        //  A.tiempo(1);
          //A.print_R(A.m_pHead);
        //}
        //cout<<"1. Ingresa proceso: "<<endl;
        if (A.m_pHead==0) cout<<"No procesos"<<endl;
        cin>>menu;
      switch (menu) {
        case 1:
            cout<<"1. Ingresa proceso: "<<endl;
            cin>>pros>>prio;
            A.AddE(pros,prio);
            A.tiempo(1);
          break;
        case 2:
            A.print_R(A.m_pHead,menu);
            A.tiempo_mostrar(1,menu);
            break;
        case 3:
            A.tiempo(1);
            break;
      }
    }

      /*A.AddE(1,23);
      A.AddE(2,25);
      A.AddE(3,4);
      A.AddE(4,65);
      A.AddE(5,65);
      A.print_R(A.m_pHead);*/
  return 0;
}
