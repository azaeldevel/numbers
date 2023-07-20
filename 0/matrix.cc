


#include "matrix.hh"

namespace oct::nums::v0
{

template<> float matrix<int,1,1,float>::det() const
{
    return consecutive<consecutive<int,size_t,1>,size_t,1>::data[0][0];
}
template<> float matrix<int,2,2,float>::det() const
{
    float d = 0;
    d = consecutive<consecutive<int,size_t,2>,size_t,2>::data[0][0] * consecutive<consecutive<int,size_t,2>,size_t,2>::data[1][1];
    d -= consecutive<consecutive<int,size_t,2>,size_t,2>::data[0][1] * consecutive<consecutive<int,size_t,2>,size_t,2>::data[1][0];

    return d;
}


}

