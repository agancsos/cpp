#ifndef __GENERICS_ALL_H_INCLUDED__
#define __GENERICS_ALL_H_INCLUDED__
#include "map.h"
#include "mapelement.h"
#include "object.h"
#include "objectcollection.h"
#include "generic_types.h"
namespace amgcommon { 
    namespace generics {
        template <class T1, class T2> static bool instanceof(T2 a) {
            return typeid(a) == typeid(T1);
        }
    }
}
#endif
