#include <cmath>
#include <iostream>

#include "Graphics/RoundedRectangleShape.hpp"
#include "Math/Utils.hpp"

ng::Graphics::RoundedRectangleShape::RoundedRectangleShape(
  const sf::Vector2f& size,
  const float& radius,
  const std::size_t& pointCount)
  : size_(size),
    radius_(radius),
    pointCount_(pointCount)
{
  update();
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::RoundedRectangleShape::setSize(const sf::Vector2f& size)
{
  size_ = size;
  update();
}

///////////////////////////////////////////////////////////////////////////////

const sf::Vector2f& ng::Graphics::RoundedRectangleShape::getSize() const
{
  return size_;
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::RoundedRectangleShape::setRadius(const float& radius)
{
  radius_ = radius;
  update();
}

///////////////////////////////////////////////////////////////////////////////

const float& ng::Graphics::RoundedRectangleShape::getRadius() const
{
  return radius_;
}

///////////////////////////////////////////////////////////////////////////////

void ng::Graphics::RoundedRectangleShape::setPointCount(
  const std::size_t& pointCount)
{
  pointCount_ = pointCount;
  update();
}

///////////////////////////////////////////////////////////////////////////////

std::size_t ng::Graphics::RoundedRectangleShape::getPointCount() const
{
  return pointCount_;
}

///////////////////////////////////////////////////////////////////////////////

sf::Vector2f ng::Graphics::RoundedRectangleShape::getPoint(
  std::size_t index) const
{
  static const float pi = 3.141592654f;

  float angle = index * 2 * pi / getPointCount() - pi / 2;

  float x = (
    pow(fabs(cos(angle)), 2.0/radius_) * size_.x *
    ng::Math::Utils::sgn(cos(angle))
  );
  float y = (
    pow(fabs(sin(angle)), 2.0/radius_) * size_.y * 
    ng::Math::Utils::sgn(sin(angle))
  );

  return sf::Vector2f(x + size_.x, y + size_.y);
}
