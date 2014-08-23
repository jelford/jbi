#ifndef JBI_PRECONDITIONS_HPP
#define JBI_PRECONDITIONS_HPP

#include <exception>

namespace jbi_preconditions {

class PreconditionViolated : public std::runtime_error
{
    public:
    PreconditionViolated(char const * const message) : std::runtime_error(message)
    {
    }
};


template <typename M, typename Key>
auto get(M& m, Key k) -> decltype(m[k])
{
    if (m.find(k) == m.end())
    {
        throw PreconditionViolated("Key Error - can't find key in map");
    }
   
    return m[k];
}

}

#endif
