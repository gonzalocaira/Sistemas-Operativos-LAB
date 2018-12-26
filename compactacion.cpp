#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Proceso{
    public:
        int tam;
        int tiempo;
    public:
        Proceso(int tam_,int tiempo_){
            tam = tam_;
            tiempo = tiempo_;    
        }
};

class Memoria{
    public:
        int tam_mem;
        int mem_libre;
        vector<int> particiones_;
    public:
        Memoria(){};
        Memoria(int tam_mem_){
            tam_mem = tam_mem_;
            mem_libre = tam_mem_;
        }        
};


class Gestionar{
    public:
        Memoria A;
        list<Proceso> procesos;
    public:
        Gestionar(Memoria A_){
            A = A_;
        }

        void agregar(Proceso p){
            if ( A.mem_libre >= p.tam ){
                procesos.push_back(p);
                A.mem_libre = A.mem_libre - p.tam;
            }
            else{
                return;
            }
        }

        void print(){
            list<Proceso>::iterator it;
            for(it = procesos.begin();it!=procesos.end();it++){
                cout<<(*it).tam<<endl;
            }
        }

        void tiempo(){
            int seg = 0;
            list<Proceso>::iterator it;
            while (!procesos.empty()){              
                for(it = procesos.begin();it!=procesos.end();it++){
                    if (seg == (*it).tiempo) {
                        A.mem_libre = A.mem_libre + (*it).tam;
                        cout<<"Tiempo proceso "<<(*it).tiempo<<" Memoria Usada "<<(*it).tam<<endl;
                        procesos.erase(it);
                        break; 
                    }
                }
                cout<<"Segundo: "<<seg<<" Memoria Libre: "<<A.mem_libre<<endl;/*" Tiempo del proceso " <<(*it).tiempo<<" Memoria de proceso "<<(*it).tam<<endl;*/
                seg = seg + 1;
                
            } 
        }
};


int main(){
    Memoria A(50);
    Gestionar G(A);
    Proceso p1(8,1);
    Proceso p2(10,4);
    Proceso p3(20,1);
    Proceso p4(8,2);
    G.agregar(p1);
    G.agregar(p2);
    G.agregar(p3);
    G.agregar(p4);
    G.tiempo();
    return 0;
}