


#include "matrix.hh"

namespace oct::nums::v0
{

template<> float matrix<int,1,1,float>::det() const
{
    return Sequence<Sequence<int,1>,1>::data[0][0];
}
template<> float matrix<int,2,2,float>::det() const
{
    float d = 0;
    d = Sequence<Sequence<int,2>,2>::data[0][0] * Sequence<Sequence<int,2>,2>::data[1][1];
    d -= Sequence<Sequence<int,2>,2>::data[0][1] * Sequence<Sequence<int,2>,2>::data[1][0];

    return d;
}


}

