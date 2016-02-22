//
// Copyright 2016 nfactorial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef NGEN_STATE_VALUE_H
#define NGEN_STATE_VALUE_H


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    template < typename TType > class StateValue {
    public:
        StateValue();
        ~StateValue();

        void invalidate();
        bool isValid() const;

        const StateValue< TType >& operator=( const TType &newValue );
        const StateValue< TType >& operator=( const StateValue< TType > &newValue );

        bool operator==( const StateValue< TType > &other ) const;
        bool operator!=( const StateValue< TType > &other ) const;

        bool operator==( const TType &otherValue ) const;
        bool operator!=( const TType &otherValue ) const;

    private:
        bool m_isValid;
        TType m_value;
    };


    template < typename TType >
    inline StateValue< TType >::StateValue()
    : m_isValid( false )
    {
    }

    template < typename TType >
    inline StateValue< TType >::~StateValue()
    {
    }

    template < typename TType >
    inline void StateValue< TType >::invalidate() {
        m_isValid = false;
        return *this;
    }

    template < typename TType >
    inline const StateValue< TType >& StateValue< TType >::operator=( const TType &newValue ) {
        if (!m_isValid || newValue != m_value) {
            m_value = newValue;
            m_isValid = true;
        }

        return *this;
    }

    template < typename TType >
    inline const StateValue< TType >& StateValue< TType >::operator=( const StateValue< TType > &newValue ) {
        m_isValid = newValue.m_isValid;
        m_value = newValue.m_value;

        return *this;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_STATE_VALUE_H
