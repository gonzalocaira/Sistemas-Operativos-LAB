#include<iostream>
#include"memoria2.cpp"
#include"paginacion.cpp"
#include"cola_prioridad.cpp"
#include<stdlib.h>


int main(){
    int var = 5;
    while(var!=0){
        cout<<"\t----PRESENTACION FINAL SO--------\n";
        cout<<"\t1.- Memoria \n";
        cout<<"\t2.- Paginacion\n";
        cout<<"\t3.- Procesos\n";
        cout<<"\t0.- Salir\n\n";
        int op;
        cout<<"\tIngrese opcion : ";
        cin>>op;
        //system("cls");
        switch(op){
            case 1: 
                memoria();
                //system("cls");
                    break;
            case 2:
                paginacion();
                //system("cls");
                break;
            case 3:
                prioridad();
                //system("cls");
        }
    }
    return 0;
}