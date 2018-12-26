#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Peticion{
    public:
        int num_cilindro;
        double tiempo_llegada;
        Peticion (int A,double B){
            num_cilindro=A;
            tiempo_llegada=B;
        }
};
class ListaPeticion{
    queue<Peticion> Peticiones;
    double tiempo_empleado;
    int cilindro_actual;
    double tiempo;
    list<int> list_distancias;
    public:
        ListaPeticion(int A,int C,queue<Peticion> B){
            Peticiones = B;
            cilindro_actual=A;
            tiempo_empleado=C;
            tiempo=0;
        }
        void add_peticion(Peticion P){
            Peticiones.push(P);
        }
        void SSTF(){
            int distancia_entre_dos;
            distancia_entre_dos=abs(cilindro_actual-(Peticiones.front()).num_cilindro);
            cout<<tiempo<<endl;
            //cout<<distancia_entre_dos;
            list_distancias.push_back(distancia_entre_dos);
            tiempo+=0.1;

            while (!Peticiones.empty()) 
               { 
                    if((Peticiones.front()).tiempo_llegada==tiempo){
                    cout<<tiempo<<" llega "<<(Peticiones.front()).num_cilindro<<endl;
                    Peticiones.pop(); 
                    }
                Peticiones.pop();
                cout<<tiempo<<endl;
                tiempo+=0.1;
                } 
                 
                
            
        }
        
};
/*class Rendimiento{
    private:
        vector<int> R;
        list<int> distancias;
        int num;
    public:
        Rendimiento(vector<int> A,int B){
            R=A;
            num=B;
        }
        void FIFO(){
            queue<int> Cola;
            int distancia_entre_dos;
            vector<int>::iterator it;
            for(it = R.begin();it!=R.end();it++){
                Cola.push(*it);
            }
            int front=Cola.front();
            distancia_entre_dos=abs(num-front);
            while(!Cola.empty()){

            }
            cout<<distancia_entre_dos;
        }

        void showq(queue <int> gq) 
        { 
            queue <int> g = gq; 
            while (!g.empty()) 
            { 
                cout << '\t' << g.front(); 
                g.pop(); 
            } 
            cout << '\n'; 
        } 

};*/



int main(){
    Peticion A(8,0.2);
    Peticion B(9,0.3);
    Peticion C(11,0.4);
    queue<Peticion> list_P;
    list_P.push(A);
    list_P.push(B);
    list_P.push(C);
    ListaPeticion Manejo(40,0.2,list_P);
    Manejo.SSTF();
    return 0;
}