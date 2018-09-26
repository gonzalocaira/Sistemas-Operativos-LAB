#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "iostream"
#include "time.h"
#include "Menu.h"


using namespace std;
using namespace sf;

#include <time.h>
//#include "persona.h"
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
        int tiemp;
        RectangleShape *duracion;
        RectangleShape *duracion1;
        RectangleShape *duracion2;
        RectangleShape *duracion3;
        RectangleShape *duracion4;
        RectangleShape *duracion5;
        RectangleShape *duracion6;
    public:
       Lista_D():m_pHead(0),m_pTail(0){
         tiemp= 1;
         duracion = new RectangleShape({456,32});
         duracion->setFillColor(Color::Red);
         duracion->setPosition(370,150);
         duracion1 = new RectangleShape({440,32});
         duracion1->setFillColor(Color::Cyan);
         duracion1->setPosition(370,190);
         duracion2 = new RectangleShape({410,32});
         duracion2->setFillColor(Color::Cyan);
         duracion2->setPosition(370,230);
         duracion3 = new RectangleShape({400,32});
         duracion3->setFillColor(Color::Cyan);
         duracion3->setPosition(370,270);
         duracion4 = new RectangleShape({430,32});
         duracion4->setFillColor(Color::Cyan);
         duracion4->setPosition(370,310);
         duracion5 = new RectangleShape({400,32});
         duracion5->setFillColor(Color::Cyan);
         duracion5->setPosition(370,350);
         duracion6 = new RectangleShape({460,32});
         duracion6->setFillColor(Color::Cyan);
         duracion6->setPosition(370,390);
       };
       RectangleShape getShape(){return *duracion;}
       RectangleShape getShape1(){return *duracion1;}

       RectangleShape getShape2(){return *duracion2;}
       RectangleShape getShape3(){return *duracion3;}
       RectangleShape getShape4(){return *duracion4;}

       RectangleShape getShape5(){return *duracion5;}
       RectangleShape getShape6(){return *duracion6;}

       bool IsEmpty(){
         return !m_pHead;
       }

       bool AddDato(T d){
         Nodo<T> * pNuevo = new Nodo<T>(d);
         return true;
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

int main(int argc, char const *argv[]) {
  Lista_D<int> Lista_D;
    //Nodo<int> *tmp=Lista_D.top;
/*  Lista_D.insertar(10,8);
  //Lista_D.imprimir();
  Lista_D.restar();
  Lista_D.insertar(18,14);
  Lista_D.corto();
  Lista_D.restar();
  //Lista_D.imprimir();
  Lista_D.insertar(8,6);
  Lista_D.corto();
  Lista_D.restar();*/
  RenderWindow window(VideoMode(900,480),"Sistemas Operativos :D");
  window.setVerticalSyncEnabled(true);
  Menu menu(window.getSize().x,window.getSize().y);

  sf::Texture textura;

	// Cargamos la textura desde un archivo
	if(!textura.loadFromFile("menu.png"))
	{
		// Si hay un error salimos
		return EXIT_FAILURE;
	}

	// Creamos un sprite
	sf::Sprite sprite;
	// Asignamos la textura al sprite
	sprite.setTexture(textura);
	// Seleccionamos solo un rectangulo de la textura
  Font font2;
  if(!font2.loadFromFile("Echomotors Script Demo.ttf")){
    cout<<"Error loading file"<<endl;
  }

  String playerInput;
  Text playerText;
  playerText.setPosition(60,300);
  playerText.setFillColor(Color::Red);


  //string q="hola";
  Text text2;
  text2.setFont(font2);
  text2.setString("Sistemas de Planificacion");
  text2.setCharacterSize(100);
  text2.setPosition(40,12);
  text2.setFillColor(Color::Blue);

  string q;
  Text text3;
  text3.setFont(font2);


  while(window.isOpen()){
    Event event;
		//window.draw(menu.get_sprite());
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::TextEntered){
          if(event.text.unicode < 128){
             playerInput +=event.text.unicode;
             playerText.setString(playerInput);
          }
        }

        //window.display();
      switch (event.type) {
        case Event::KeyReleased:
           switch (event.key.code) {
             case Keyboard::Up:
                menu.MoveUp();
                break;
             case Keyboard::Down:
                menu.MoveDown();
                break;
             case Keyboard::Return:
                switch (menu.GetPressedItem()) {
                  case 0:
                    /*int prioridad,t_ejecucion;
                    cout<<"Prioridad :";
                    cin>>prioridad;
                    cout<<"Tiempo de ejecucion : ";
                    cin>>t_ejecucion;
                    Lista_D.insertar(prioridad,t_ejecucion);
                    cout<<endl;*/
                    //window.clear();
                    //window.display();

                    Lista_D.AddE(1,7);
                    Lista_D.AddE(5,6);
                    Lista_D.AddE(3,4);
                    Lista_D.AddE(8,9);
                    Lista_D.AddE(10,2);
                    Lista_D.AddE(14,1);
                    Lista_D.AddE(6,6);
                    //Lista_D.AddE(9,2);
                    Lista_D.tiempo(1);
                    window.draw(Lista_D.getShape());
                    window.draw(Lista_D.getShape1());
                    window.draw(Lista_D.getShape2());
                    window.draw(Lista_D.getShape3());
                    window.draw(Lista_D.getShape4());
                    window.draw(Lista_D.getShape5());
                    //window.draw(Lista_D.getShape6());
                    //window.draw(Lista_D.top->sig->get_Shape());
                    //window.draw(Lista_D.getShape());
                    window.display();

                    break;
                  case 1:
                    Lista_D.print_R(Lista_D.m_pHead,3);
                    //Lista_D.tiempo_mostrar(1,0);

                    break;
                  case 2:
                    window.close();
                    break;
                }
           }
           break;
        case Event::Closed:
          window.close();
          break;
      }
    }

    window.clear();
    window.draw(playerText);
    window.draw(sprite);
    window.draw(text2);
    //window.draw(text3);
    menu.draw(window);
    window.display();
  }
  return 0;
}
