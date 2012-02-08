/*
Soft_Math, January 22th, 2012

Copyright (C) 2012 Marek Gaik

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

Marek Gaik
marek.gaik@gmail.com
http://github.com/marog/Soft_Math/
*/

#include "soft_div.h"

#ifdef ARM_CLZ
    #define CLZ(val) arm_clz(val)
#else
    #define CLZ(val) soft_clz(val)
#endif

#ifdef ARM_CLZ //check for GCC + and ARM arch (clz is 1cycle instruction available in ARMv5 and above)
unsigned inline static arm_clz( unsigned val )
{
    unsigned position;
    __asm__ ( "clz %[result], %[value]" : [result] "=r" (position) : [value] "r" (val) );
    return position;
}
#else
unsigned static soft_clz( unsigned val )
{
    unsigned mask = 0x80000000U;
    unsigned i = 0;

    if( val != 0 )
    {
        while( !(mask&val) )
        {
            mask >>= 1;
            ++i;
        }
    }
    else
    {
        return 32;
    }

    return i;
}
#endif

unsigned div_clz( unsigned val, const unsigned div )
{
    unsigned divres = 0;

    if( div >= 1 )
    {
        while( val >= div )
        {
            unsigned clzdiff = CLZ(div)-CLZ(val);
            if( ( div << clzdiff) > val )
            {
                --clzdiff;
            }
            divres += (1U<<clzdiff);
            val -= div<<clzdiff;
        }
    }
    else
    {
        return divres;
    }

    return divres;
}