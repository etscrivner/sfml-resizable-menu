#include <cassert>
#include <iostream>

#include "Graphics/UI/SelectionMenu.hpp"

const std::size_t ng::Graphics::UI::SelectionMenu::kFontSize = 30.0f;
const float       ng::Graphics::UI::SelectionMenu::kItemXOffset = 60.0f;
const float       ng::Graphics::UI::SelectionMenu::kItemSpacing = 20.0f;

///////////////////////////////////////////////////////////////////////////////

ng::Graphics::UI::SelectionMenu::SelectionMenu(sf::Font font)
  : background_(sf::Vector2f(20, 20)),
    font_(font),
    cursor_(10, 3),
    visible_(false)
{
  background_.setFillColor(sf::Color::Blue);
  background_.setOutlineThickness(10);
  background_.setOutlineColor(sf::Color::White);

  // Move down and right to compensate for outline
  background_.move(sf::Vector2f(10, 10));

  cursor_.rotate(90);
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::UI::SelectionMenu::addItem(const std::string& text)
{
  // Initialize a new item.
  sf::Text item;
  item.setFont(font_);
  item.setCharacterSize(kFontSize);
  item.setColor(sf::Color::White);
  item.setString(text);

  // Add the item to the back of the list of items
  items_.push_back(item);
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::UI::SelectionMenu::show()
{
  sf::Vector2f offset(kItemXOffset, kItemSpacing);
  float largestItemWidth = 1;

  for (auto& item : items_) 
  {
    auto origin = getOrigin();
    origin -= offset;
    item.setOrigin(origin);

    offset.y += item.getLocalBounds().height;
    largestItemWidth = std::max(
      largestItemWidth, item.getLocalBounds().width
    );

    /// Add spacing after each item
    offset.y += kItemSpacing;
  }

  // Add left and right padding of kItemXOffset
  background_.setSize(
    sf::Vector2f(largestItemWidth + kItemXOffset * 2, offset.y)
  );

  visible_ = true;
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::UI::SelectionMenu::hide()
{
  visible_ = false;
}

///////////////////////////////////////////////////////////////////////////////

std::size_t ng::Graphics::UI::SelectionMenu::getItemCount() const
{
  return items_.size();
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::UI::SelectionMenu::setCursorIndex(std::size_t index)
{
  assert(index > 0 && index <= getItemCount());

  sf::Vector2f offset(0.75 * kItemXOffset, kItemSpacing);

  // Offset for each item in the menu, accounting for item spacing
  for (std::size_t i = 1; i < index; i++)
  {
    offset.y += items_[i].getLocalBounds().height;

    // Add spacing to additional items after the first
    offset.y += kItemSpacing;
  }

  // First move to the top of the select item
  auto origin = getOrigin();
  origin += offset;

  // Now move half-way down the item so cursor points at its center
  origin.y += items_[index - 1].getLocalBounds().height * 0.5;

  cursor_.setPosition(origin);
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::UI::SelectionMenu::draw(sf::RenderTarget& target,
                                           sf::RenderStates states) const
{
  states.transform *= getTransform();

  if (visible_)
  {
    target.draw(background_, states);

    for (auto item : items_) {
      target.draw(item, states);
    }

    if (items_.size() > 0) {
      target.draw(cursor_, states);
    }
  }
}
