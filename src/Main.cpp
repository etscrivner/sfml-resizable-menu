#include <SFML/Graphics.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

#include "Graphics/UI/SelectionMenu.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(640, 480), "UI Demo");

  sf::Font font;
  if (!font.loadFromFile("pixel_azure_bonds.otf"))
  {
    std::cerr << "Error: Could not load font" << std::endl;
    window.close();
    return 1;
  }
    
  ng::Graphics::UI::SelectionMenu menu(font);
  menu.addItem("Status");
  menu.addItem("herp");
  menu.addItem("Equip");
  menu.addItem("Items");
  menu.addItem("Junction");
  menu.addItem("Exit");

  int cursorPos = 1;
  menu.setCursorIndex(cursorPos);
  menu.show();

  sf::Event event;
  while (window.isOpen())
  {
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      if (event.type == sf::Event::Resized)
      {
        /// Resize everything in window when resized.
        window.setView(
          sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height))
        );
      }

      if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code) {
          case sf::Keyboard::Down:
          {
            cursorPos = (cursorPos % menu.getItemCount()) + 1;
            menu.setCursorIndex(cursorPos);
          }
          break;
          case sf::Keyboard::Up:
          {
            cursorPos--;
            if (cursorPos < 1) {
              cursorPos = menu.getItemCount();
            }

            menu.setCursorIndex(cursorPos);
          }
          break;
          case sf::Keyboard::Right:
          {
            menu.move(10, 0);
          }
          break;
          case sf::Keyboard::Left:
          {
            menu.move(-10, 0);
          }
          break;
          default: break;
        }
      }
    }

    window.clear();
    window.draw(menu);
    window.display();
  }

  return 0;
}
