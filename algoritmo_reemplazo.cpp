#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//un vector para leer


//para insertar usar un iterator que me diga si es el mismo
//numero , en caso que lo fuera no lo agrega y no es el 
//mismo lo agrega
//stack
class Marco{
    public:
        int num_marcos;
    //private:
    Marco(){}
    Marco(int d):num_marcos(d){}
};


//vector<int>::iterator it;
class Reemplazo{
    public:
        Marco A;
        list<queue<int>> list_reemplazos;
        vector<int> secuencia;
    
        Reemplazo(Marco Copia){
            A = Copia;
        }
        bool repite(queue<int> B,int x){
            queue<int> A=B;
            int C=0;
            while(!A.empty()){
                if(A.front()==x)C++;
                //cout<<"\t"<< copia.front();
                A.pop();
            }
            if(C==0){return false;}
            if(C>0){return true;}
        }
        void agregar(vector<int> vect){
            vector<int>::iterator it;
            int tam=0;
            queue<int> Cola;
            for(it = vect.begin();tam<A.num_marcos;it++,tam++){
                
               // if(repite(Cola,*it))
                 Cola.push(*it);
                //cout<<(*it)<<endl;
                //imprimir(Cola);
                if(tam>=A.num_marcos){
                    Cola.pop();
                    //if(repite(Cola,*it))
                    Cola.push(*it);
                    cout<<"\t FALLO \t"<<endl;
                }
                list_reemplazos.push_back(Cola);
                //imprimir(Cola);
                cout<<endl;
            }
        }
        void imprimir_lista(){
            list <queue<int>> :: iterator it; 
            for(it = list_reemplazos.begin(); it != list_reemplazos.end(); ++it) 
              while(!(*it).empty()){
                cout<<"\t"<< (*it).front();
                (*it).pop();
            }   
            cout << '\n'; 

        }
        void imprimir(queue<int> C){
            queue<int> copia=C;
            while(!copia.empty()){
                cout<<"\t"<< copia.front();
                copia.pop();
            }
        }

};



int main(){
    Marco M(4);
    vector<int> v = { 2 ,3,2,1,5,2,4,5,3,2,5,2};
    Reemplazo R(M);
    R.agregar(v);
    R.imprimir_lista();
    
    return 0;
}