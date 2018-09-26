#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "iostream"
#include "Menu.h"

using namespace std;
using namespace sf;

int main(int argc, char const *argv[]) {

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
  if(!font2.loadFromFile("Bafora Regular Demo.ttf")){
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


  /*Text text_max;
  text_max.setFont(font2);
  text_max.setString("frequency");
  text_max.setCharacterSize(50);
  text_max.setPosition(300,20);
  text_max.setFillColor(Color::Blue);
  text2.setStyle(Text::Style::Bold | Text::Style::Underlined);
  text2.setOutlineColor(Color::Cyan);
  text2.setOutlineThickness(-10);*/
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



                    break;
                  case 1:


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
