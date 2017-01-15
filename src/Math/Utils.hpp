#ifndef NG_MATH_UTILS_HPP_INCLUDED
#define NG_MATH_UTILS_HPP_INCLUDED

namespace ng
{
  namespace Math
  {
    namespace Utils
    {
      /// Returns a single integer value indicating the sign of the given value.
      ///
      /// @param value The value to be checked
      /// @return -1 if value < 0. 0 if value == 0. 1 if value > 0.
      template<typename T>
      int sgn(const T& value)
      {
        if (value < 0)
        {
          return -1;
        }

        if (value > 0)
        {
          return 1;
        }

        return 0;
      }
    }
  }
}

#endif // NG_MATH_UTILS_HPP_INCLUDED
