/*
© 2019, Dark Orb.

The license version - 1.0

This license is hereby grants to any person who obtained a copy of this software the next rights to:
1. Use and do reverse-engineering of compiled version of this software at no cost, without any restrictions, in non-commercial and commercial purposes
2. Use source codes of this software at no cost but with the limitations - source codes available only for non-commercial, academic and / or scientific purposes
3. Copy and distribute without any fee
4. Create a copy of the original repository and / or create own derivative software for non-commercial,  academic and / or scientific purposes only

This license is require to:
1. Keep the full license text without any changes
2. The license text must be included once in a file called 'License' which placed in the root directory of the software and in all source files of the software

This license is deny to:
1. Change license of the derivative software
2. Use the copyright holder name and name of any contributor of this software for advertising derivative software without legally certified permission
3. Sell this software without an author legally certified permission

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <string>

using std::string;

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
    static inline bool fSort( vector<T> &_Collection ) {
      if( _Collection.empty() )
        return false;

      size_t vPosition = 0;

      for( size_t c = 0; c < static_cast< size_t >( _Collection.size() ); c++ ) {
        long long vDifference = numeric_limits<T>::lowest();

        T vGetFirstValue = _Collection [ c ],
          vGetSecondValue;

        for( size_t b = c; b < static_cast< size_t >( _Collection.size() ); b++ ) {
          vGetSecondValue = _Collection [ b ];

          if( vDifference < vGetFirstValue - vGetSecondValue ) {
            vDifference = vGetFirstValue - vGetSecondValue;
            vPosition = b;
          }
        }

        swap( _Collection [ c ], _Collection [ vPosition ] );
      }

      return true;
    }

    template<typename T>
    static inline bool fSort( vector<T> &_Collection,
                              function<const bool( const long long, const T, const T )> _CheckCondition = [] ( const long long _Difference, const T _FirstValue, const T _SecondValue ) { return _Difference < _FirstValue - _SecondValue; },
                              function<const long long( const T, const T )> _AssignCondition = [] ( const T _FirstValue, const T _SecondValue ) { return _FirstValue - _SecondValue; } ) {
      if( _Collection.empty() || !_CheckCondition )
        return false;

      size_t vPosition = 0;

      for( size_t c = 0; c < static_cast< size_t >( _Collection.size() ); c++ ) {
        long long vDifference = numeric_limits<T>::lowest();

        T vGetFirstValue = _Collection [ c ],
          vGetSecondValue;

        for( size_t b = c; b < static_cast< size_t >( _Collection.size() ); b++ ) {
          vGetSecondValue = _Collection [ b ];

          if( _CheckCondition( vDifference, vGetFirstValue, vGetSecondValue ) ) {
            vDifference = _AssignCondition( vGetFirstValue, vGetSecondValue );
            vPosition = b;
          }
        }

        swap( _Collection [ c ], _Collection [ vPosition ] );
      }

      return true;
    }
  };
}
