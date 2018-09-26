#include "SFML/Graphics.hpp"

//#include "Text.hpp"
using namespace sf;

#define Max_NUMBER_OF_ITEMS 3

class Menu{
public:
  Menu(float width,float height);
  ~Menu();
  void draw(RenderWindow &window);
  void MoveUp();
  void MoveDown();
  int GetPressedItem(){return selectedItemIndex;}
private:
  int selectedItemIndex;
  Font font;
  Text menu[Max_NUMBER_OF_ITEMS];;
};
