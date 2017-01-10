
#include <iostream>
#include "friend.h"

static Base* Base::getinstance()
{
    ptr = new Base;
    return ptr;
}

