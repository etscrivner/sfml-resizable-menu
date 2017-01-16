#ifndef NG_GRAPHICS_ROUNDED_RECTANGLE_SHAPE_HPP_INCLUDED
#define NG_GRAPHICS_ROUNDED_RECTANGLE_SHAPE_HPP_INCLUDED

#include <SFML/Graphics/Shape.hpp>

namespace ng
{
  namespace Graphics
  {
    /// Shape representing a super-ellipse or rounded rectangle. Information
    /// used to construct this interface acquired from:
    ///
    ///   - <a href="https://en.wikipedia.org/wiki/Squircle">Squircle (Wikipedia)</a>
    ///   - <a href="http://mathworld.wolfram.com/Superellipse.html">Superellipse (Wolfram Mathworld)</a>
    class RoundedRectangleShape : public sf::Shape {
    public:
      /// \brief Default Constructor
      ///
      /// \param size       Width and height of the rounded rectangle.
      /// \param radius     Radius of the corners (larger is more rectangular).
      /// \param pointCount Number of points composing the rounded rectangle.
      RoundedRectangleShape(const sf::Vector2f& size,
                            const float& radius = kDefaultRadius,
                            const std::size_t& pointCount = kDefaultPointCount);

      /// \brief Set the size of the rounded rectangle.
      ///
      /// \param size Width and height of the rounded rectangle.
      void setSize(const sf::Vector2f& size);

      /// \brief Get the size of the rounded rectangle.
      ///
      /// \return Size of the rounded rectangle.
      ///
      /// \see setSize
      const sf::Vector2f& getSize() const;

      /// \brief Set the radius of the rounded rectangle corners.
      ///
      /// \param radius Radius of the rounded rectangle corners.
      void setRadius(const float& radius);

      /// \brief Get the radius of the rounded rectangle corners.
      ///
      /// \return Radius of the rounded rectangle corners.
      ///
      /// \see setRadius
      const float& getRadius() const;

      /// \brief Set number of points composing rounded rectangle.
      ///
      /// \param pointCount Number of points composing rounded rectangle.
      void setPointCount(const std::size_t& pointCount);

      /// \brief Return the number of points composing the rounded rectangle.
      ///
      /// \return Number of points composing the rounded rectangle.
      ///
      /// \see setPointCount
      virtual std::size_t getPointCount() const;

      /// \brief Get a point of the rounded rectangle.
      ///
      /// The returned point is in local coordinates, that is, the shape's
      /// transforms (position, rotation, scale) are not taken into account.
      /// The result is undefined if \a index is out of the valid range.
      ///
      /// \param index Index of the point to get in range [0..getPointCount() - 1]
      ///
      /// \return index-th point of the shape
      virtual sf::Vector2f getPoint(std::size_t index) const;
    private:
      /// Member variables

      sf::Vector2f size_;       ///< Width and height of the rectangle.
      float        radius_;     ///< The radius of the corners.
      std::size_t  pointCount_; ///< Number of points composing rounded rectangle.

      /// Static variables

      static const float kDefaultRadius;           ///< Default radius for corners
      static const std::size_t kDefaultPointCount; ///< Default point count
    };
  }
}

#endif // NG_GRAPHICS_ROUNDED_RECTANGLE_SHAPE_HPP_INCLUDED
