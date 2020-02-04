/*
© 2019, Serge Page.

This license is hereby grants to any person who obtained a copy of this product or the product source files the next rights to:

- Use a compiled version of this product at no cost, without any restrictions, in non-commercial and commercial purposes
- Do reverse-engineering of this product in non-commercial purposes only
- Use source codes of this product at no cost but with the limitations - source codes available only for non-commercial, academic and / or scientific purposes
- Copy and distribute without any fee
- Copy of the original repository and / or create own derivative product for non-commercial,  academic and / or scientific purposes only
- Link the product source code with an another product source code which licensed under any of Dark Orb licenses or one of these licenses:
  - MIT License
  - Microsoft Public License
  - Beerware License
  - Academic Free License
  - WTFPL
  - Unlicense
  - Original BSD license
  - Modified BSD License
  - Simplified BSD License
  - Zero Clause BSD
- Link the product source code with an another product source code if between them no any patent collision

This license is require to:

- Keep the full license text without any changes
- The license text must be included once in a file called 'License' which placed in the root directory of the product and in all source files of the product

This license is deny to:

- Change license of the derivative product
- Use the product’s author name and name of any contributor of this product for advertising derivative software without legally certified permission
- Resell this product
- Use the product or the product source code for any purpose which refers to any government of any country

The product is an original source codes and original compiled files which made by the original author and provided only under the grants and restrictions of this license. All damages which can be happen after and while using the product will not be compensate.
*/

#pragma once

#include <string>

using std::u32string;

#include <vector>

using std::vector;
using std::pair;

#include <limits>

using std::numeric_limits;

#include <utility>

using std::swap;

#include <functional>

using std::function;

namespace DAS {
  class Algorithm {
    public:
    template<typename T>
    static inline bool FSort( vector<T> &_Collection ) {
      if( _Collection.empty() )
        return false;

      uint32_t VPosition = 0;

      for( uint32_t c = 0; c < static_cast< uint32_t >( _Collection.size() ); c++ ) {
        long long VDifference = numeric_limits<T>::lowest();

        T VGetFirstValue = _Collection [ c ],
          VGetSecondValue;

        for( uint32_t b = c; b < static_cast< uint32_t >( _Collection.size() ); b++ ) {
          VGetSecondValue = _Collection [ b ];

          if( VDifference < VGetFirstValue - VGetSecondValue ) {
            VDifference = VGetFirstValue - VGetSecondValue;
            VPosition = b;
          }
        }

        swap( _Collection [ c ], _Collection [ VPosition ] );
      }

      return true;
    }

    template<typename T>
    static inline bool FSort( vector<T> &_Collection,
                              function<const bool( const long long, const T, const T )> _CheckCondition = [] ( const long long _Difference, const T _FirstValue, const T _SecondValue ) { return _Difference < _FirstValue - _SecondValue; },
                              function<const long long( const T, const T )> _AssignCondition = [] ( const T _FirstValue, const T _SecondValue ) { return _FirstValue - _SecondValue; } ) {
      if( _Collection.empty() || !_CheckCondition )
        return false;

      uint32_t VPosition = 0;

      for( uint32_t c = 0; c < static_cast< uint32_t >( _Collection.size() ); c++ ) {
        long long VDifference = numeric_limits<T>::lowest();

        T VGetFirstValue = _Collection [ c ],
          VGetSecondValue;

        for( uint32_t b = c; b < static_cast< uint32_t >( _Collection.size() ); b++ ) {
          VGetSecondValue = _Collection [ b ];

          if( _CheckCondition( VDifference, VGetFirstValue, VGetSecondValue ) ) {
            VDifference = _AssignCondition( VGetFirstValue, VGetSecondValue );
            VPosition = b;
          }
        }

        swap( _Collection [ c ], _Collection [ VPosition ] );
      }

      return true;
    }
  };
}
