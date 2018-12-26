#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Proceso{
    public:
        string nombre;
        int tam;
        int tiempo;
        int temp;
    public:
        Proceso(){};
        Proceso(string nombre_,int tam_,int tiempo_){
            nombre = nombre_;
            tam = tam_;
            tiempo = tiempo_;
            temp = tiempo;
        }
};

class Particion{
    public:
        int tam;
        bool libre;
        Proceso P;
        vector<Proceso> procesos;
    public:
        Particion(int tam_){
            tam = tam_;
            libre = true;
        }
        Particion(int tam_, Proceso P_){
            tam = tam_;
            P = P_;
            libre = true;
        }
};

bool compare_nocase(const Particion &p1,const Particion &p2){
    unsigned int i = 0;
    while (i< p1.tam && i< p2.tam){
        if((p1.tam) < (p2.tam) ){
            return true;
        }
        else if ((p1.tam) > (p2.tam)){
            return false;
        }
        i++;
    }
    return (p1.tam < p2.tam);
}

bool compare_nocase_2(const Particion &p1,const Particion &p2){
    unsigned int i = 0;
    while (i< p1.tam && i< p2.tam){
        if((p1.tam) > (p2.tam) ){
            return true;
        }
        else if ((p1.tam) < (p2.tam)){
            return false;
        }
        i++;
    }
    return (p1.tam > p2.tam);
}

class Memoria{
    public:
        int tam_mem;
        int mem_libre;
        bool lleno = false;
        list<Particion> particiones;
        list<Proceso> procesos;
        list<Proceso> procesos_;
        list<Proceso> procesos_ord;
    public:
        Memoria(){};
        Memoria(int tam_mem_){
            tam_mem = tam_mem_;
            mem_libre = tam_mem_;
        }
        //verifica si la memoria se lleno
        bool mem_llena(){
            if(mem_libre>0)return true;
            return false;
        }
        //funcion para agregar una particion
        void agregar_particion(int tam_particion, Proceso P){
            Particion p(tam_particion,P);
            p.libre = false;
            particiones.push_back(p);
        }
        //funcion para unir particiones libres
        void unir_particion(){
            int libre_;
            list<Particion>::iterator it;
            for(it = particiones.begin();it!=particiones.end();it++){
                if( (*it).libre == true ){
                    libre_ = libre_ + (*it).tam;
                    particiones.erase(it);
                }
            }
            /*Particion p(libre_);
            particiones.push_back(p);*/
        }

        bool vacio(){
            list<Particion>::iterator it;
            bool s;
            for(it = particiones.begin();it!=particiones.end();it++){
                if( (*it).libre == false ){
                    return false;
//                    s = false;
                }

            }
            //if (s == false) return false;
            return true;
        }

        //funcion para agregar procesos
        void agregar_proceso(Proceso A,int a,int b){
            //si ya no se pueden hacer partiones quiere decir que
            //la memoria ocupada y los procesos que no lograron
            //ser atendidos estan en una cola esperando a que una de
            //las particiones anteriormente hechas se desocupe
            Proceso P("Proceso",a,b);
            procesos_ord.push_back(P);
            if( lleno == false ){
                if ( mem_libre >= P.tam ){
                    procesos.push_back(P);
                    agregar_particion(P.tam,P);
                    mem_libre = mem_libre - P.tam;
                    }
                //si el tamaño del proceso es mayor a la memoria libre
                //se crea la ultima particion de tamaño de la memoria libre
                else{
                    Particion Part(mem_libre);
                    Part.libre = true;
                    particiones.push_back(Part);
                    procesos_.push_back(P);
                    lleno = true;
                }
            }
            else{
                procesos_.push_back(P);
            }

        }

        //mostrar el tamaño de los procesos y particiones
        void ver_particiones(){
            list<Proceso>::iterator it1;
            list<Proceso>::iterator it2;
            list<Particion>::iterator it3;
            //Procesos que generan las particiones
            cout<<"Procesos generadores: "<<endl;
            for(it1=procesos.begin();it1!=procesos.end();it1++){
                cout<<(*it1).nombre<<"    "<<(*it1).tam<<endl;
            }
            //Procesos que esperan por ser atendidos
            cout<<"Procesos en cola: "<<endl;
            for(it2=procesos_.begin();it2!=procesos_.end();it2++){
                cout<<(*it2).nombre<<"    "<<(*it2).tam<<endl;
            }
            //Particiones
            cout<<"Particiones: "<<endl;
            for(it3=particiones.begin();it3!=particiones.end();it3++){
                cout<<(*it3).libre<<"    "<<(*it3).tam<<endl;
            }
        }

        void tiempo(string estrategia){
            list<Particion>::iterator it1;
            list<Particion>::iterator it3;
            list<Proceso>::iterator it2;


            for(it1 = particiones.begin();it1!=particiones.end();it1++){
                if ( (*it1).libre == false ){
                    if ( (*it1).P.tiempo == 0 && (*it1).libre == false ) {
                        mem_libre = mem_libre + (*it1).P.tam;
                        (*it1).libre = true;
                        for (int i = 0;i < (*it1).P.temp;i++){
                            (*it1).procesos.push_back((*it1).P);
                        }
                        break;
                    }
                    cout<<"Proceso ejecutandose: "<<(*it1).P.nombre<<" Tiempo: "<<(*it1).P.tiempo<<endl;
                    (*it1).P.tiempo = (*it1).P.tiempo - 1;
                }
            }

            if (estrategia == "Primer_Ajuste" && !(procesos_.empty()) ){

                for(it3=particiones.begin();it3!=particiones.end();it3++){
                    if(!procesos_.empty()){

                        for(it2=procesos_.begin();it2!=procesos_.end();it2++){
                            if( (*it3).libre == true && (*it3).tam >= (*it2).tam ){
                                (*it3).libre = false;
                                (*it3).P = (*it2);
                                procesos_.erase(it2);
                                break;
                            }
                        }
                    }
                }
            }

            if (estrategia == "Segundo_Ajuste" && !(procesos_.empty()) ){

                for(it3=particiones.end();it3!=particiones.begin();it3--){
                    if(!procesos_.empty()){

                        for(it2=procesos_.begin();it2!=procesos_.end();it2++){
                            if( (*it3).libre == true && (*it3).tam >= (*it2).tam ){
                                (*it3).libre = false;
                                (*it3).P = (*it2);
                                procesos_.erase(it2);
                                break;
                            }
                        }
                    }
                }
            }

            if (estrategia == "Mejor_Ajuste" && !(procesos_.empty()) ){
                list<Particion> lista;
                list<Particion>::iterator l;
                for(it3=particiones.begin();it3!=particiones.end();it3++){
                    if(!procesos_.empty()){
                        for(it2=procesos_.begin();it2!=procesos_.end();it2++){
                            if( (*it3).libre == true && (*it3).tam >= (*it2).tam ){
                                Particion temp = *it3;
                                lista.push_back(temp);
                                break;
                            }
                        }
                    }
                }
                lista.sort(compare_nocase);
                    for(l = lista.begin();l!=lista.end();l++){
                    cout<<"LIbre: "<<(*l).tam<<endl;
                }
            }

            if (estrategia == "Peor_Ajuste" && !(procesos_.empty()) ){
                list<Particion> lista;
                list<Particion>::iterator l;
                for(it3=particiones.begin();it3!=particiones.end();it3++){
                    if(!procesos_.empty()){
                        for(it2=procesos_.begin();it2!=procesos_.end();it2++){
                            if( (*it3).libre == true && (*it3).tam >= (*it2).tam ){
                                Particion temp = *it3;
                                lista.push_back(temp);
                                break;
                            }
                        }
                    }
                }
                lista.sort(compare_nocase_2);
                    for(l = lista.begin();l!=lista.end();l++){
                    cout<<"LIbre: "<<(*l).tam<<endl;
                }
            }
        }
        void Estrategia(string estrategia){
            int seg = 0;
            while( !vacio() ){
                tiempo(estrategia);
            }
        }

        void mostrar(){
            list<Particion>::iterator it3;
            for(it3=particiones.begin();it3!=particiones.end();it3++){
                cout<<(*it3).tam<<"|";
                int tam = (*it3).procesos.size();
                for(int i = 0;i<tam;i++){
                    cout<<(*it3).procesos[i].nombre<<"-";
                }
                cout<<endl;
            }
        }
 };

void memoria(){
    cout<<"\t:::::::::MEMORIA:::::::::\n\n";
    int tam;
    cout<<"\tIngrese tamaño de memoria : ";cin>>tam;
    Memoria M(tam);
    int menu=6;
    int X,Y;
    string palabra;
    Proceso p;
    while(menu!=5){
        cout<<"\t1.- Añadir Proceso: "<<endl;
        cout<<"\t2.- Ver Particiones: "<<endl;
        cout<<"\t3.- Estrategia : "<<endl;
        cout<<"\t4.- Mostrar : "<<endl;
        cout<<"\t5.- Volver: "<<endl;
        cout<<"Opcion : ";
        cin>>menu;
      switch (menu) {
        case 1:
            cout<<"\tIngrese Tamaño : ";cin>>X;
            cout<<"\tIngrese Tiempo : ";cin>>Y;
            //Proceso p("P",X,Y);
            M.agregar_proceso(p,X,Y);
          break;
        case 2:
            M.ver_particiones();
            break;
        case 3:
            
            cout<<"\tEscribir la estrategia\n\n";
            cout<<"\tMejor_Ajuste\n\tPeor_Ajuste\n\tPrimer_Ajuste\n\tSegundo_Ajuste\n";
            cin>>palabra;
            M.Estrategia(palabra);
            break;
        case 4:
            M.mostrar();
            break;
      }
    }
}
/*
int main(){
    Memoria M(40);
    Proceso p1("p1",8,1);
    Proceso p2("p2",10,4);
    Proceso p3("p3",20,1);
    Proceso p4("p4",8,2);
    M.agregar_proceso(p1);
    M.agregar_proceso(p2);
    M.agregar_proceso(p3);
    M.agregar_proceso(p4);
    
    int s = 0;
    M.vacio(s);
    cout<<s;
    
    M.ver_particiones();
    M.Estrategia("Mejor_Ajuste");
    M.mostrar();
    return 0;
}*/
