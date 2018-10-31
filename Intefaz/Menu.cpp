#include "Menu.h"
using namespace sf;
Menu::Menu(float width,float height){

  if(!font.loadFromFile("Echomotors Script Demo.ttf"))

  {
    //handle error
  }
  menu[0].setFont(font);
  menu[0].setFillColor(sf::Color::Cyan);
  menu[0].setString("Insertar Proceso");
  menu[0].setCharacterSize(42);
  menu[0].setPosition(Vector2f(50,140));

  menu[1].setFont(font);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Mostrar");
  menu[1].setCharacterSize(42);
  menu[1].setPosition(Vector2f(50,225));

  menu[2].setFont(font);
  menu[2].setFillColor(sf::Color::White);
  menu[2].setString("Exit");
  menu[2].setCharacterSize(42);
  menu[2].setPosition(Vector2f(50,310));



  selectedItemIndex=0;
}
Menu::~Menu(){
}

void Menu::draw(RenderWindow &window){
  for(int i=0;i<Max_NUMBER_OF_ITEMS;i++){
    window.draw(menu[i]);
  }

}
void Menu::MoveUp(){
  if(selectedItemIndex - 1 >= 0){
    menu[selectedItemIndex].setFillColor(Color::White);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(Color::Cyan);
  }
}
void Menu::MoveDown(){
  if(selectedItemIndex + 1 < Max_NUMBER_OF_ITEMS){
    menu[selectedItemIndex].setFillColor(Color::White);
    selectedItemIndex++;
    menu[selectedItemIndex].setFillColor(Color::Cyan);
  }
}
