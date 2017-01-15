#ifndef NG_GRAPHICS_UI_SELECTION_MENU_HPP_INCLUDED
#define NG_GRAPHICS_UI_SELECTION_MENU_HPP_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

namespace ng
{
  namespace Graphics
  {
    namespace UI
    {
      /// UI element representing an auto-resizing menu with a movable cursor
      /// to select a given menu item.
      class SelectionMenu : public sf::Drawable, public sf::Transformable {
      public:
        /// \brief Default constructor
        ///
        /// \param font The font to use for menu text.
        SelectionMenu(sf::Font font);

        /// \brief Add an item to the bottom of the menu with the given text.
        ///
        /// \param text Text for new menu item.
        void addItem(const std::string& text);

        /// \brief Compute component positions and make the menu visible.
        void show();

        /// \brief Do no draw menu
        void hide();

        /// \brief Get the number of items in the menu.
        ///
        /// \return Number of items in the menu.
        std::size_t getItemCount() const;

        /// \brief Set the index of the item the cursor points to.
        ///
        /// \param index The index of the cursor in range [1 .. getItemCount()]
        void setCursorIndex(std::size_t index);

        /// \brief Draw the menu onto the given target.
        ///
        /// \param target Render target to draw menu onto.
        /// \param states States for rendering
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const;
      private:
        /// Member variables

        sf::RectangleShape    background_; ///< Background of menu.
        sf::Font              font_;       ///< Font for menu text.
        std::vector<sf::Text> items_;      ///< The menu items.
        sf::CircleShape       cursor_;     ///< Cursor for the menu.
        bool                  visible_;    ///< Should the menu be drawn?

        /// Constants

        static const std::size_t kFontSize; ///< The size of the menu font.
        static constexpr float ITEM_X_OFFSET = 60.0f;
        static constexpr float ITEM_SPACING  = 20.0f;
      };
    }
  }
}

#endif // NG_GRAPHICS_UI_SELECTION_MENU_HPP_INCLUDED
