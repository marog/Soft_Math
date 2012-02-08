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

#ifndef SOFT_DIV_H
#define SOFT_DIV_H

#ifdef __cplusplus
extern "C" {
#endif

/** \brief This function performs \a val / \a div operation in software. Does not require libc.
* \return val/div integer value.
*/
unsigned div_clz( unsigned val, const unsigned div );

#ifdef __cplusplus
}
#endif

#endif // SOFT_DIV_H