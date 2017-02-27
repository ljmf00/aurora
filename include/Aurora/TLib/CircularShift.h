// <Aurora/Lib/CircularShift.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/*
** @contains: Circular Shift operations Header file
** @description:
** Shift operations in C are only defined for shift values which are
** not negative and smaller than sizeof(value) * CHAR_BIT.
** The mask, used with bitwise-and (&), prevents undefined behaviour
** when the shift count is 0 or >= the width of unsigned int.
*/

#include <Aurora/Lib/Target.h>
#include <Aurora/Lib/Type.h> // for uint32_t, to get 32bit-wide rotates, regardless of the size of int.  
#include <Aurora/Lib/Limits.h> // for CHAR_BIT

#ifdef AURORA_TARGET_CXX
	namespace Ar
	{
		template <typename intT>
		#if __cplusplus > 201100L
			constexpr
		#endif
		intT rotl(intT val, size_t len)
		{
			#if __cplusplus > 201100L && _wp_force_unsigned_rotate
				static_assert(std::is_unsigned<intT>::value, "Rotate Left only makes sense for unsigned types");
			#endif
			return (val << len) | ((unsigned) val >> (-len & (sizeof(intT) * CHAR_BIT - 1)));
		}
		template <typename intT>
		#if __cplusplus > 201100L
			constexpr
		#endif
		intT rotr(intT val, size_t len)
		{
			#if __cplusplus > 201100L && _wp_force_unsigned_rotate
				static_assert(std::is_unsigned<intT>::value, "Rotate Right only makes sense for unsigned types");
			#endif
			return (val >> len) | ((unsigned) val << (-len & (sizeof(intT) * CHAR_BIT - 1)));
		}
#endif
	extern inline uint32_t rotl32 (uint32_t value, unsigned int count);
	extern inline uint32_t rotr32 (uint32_t value, unsigned int count);
#ifdef AURORA_TARGET_CXX
	}
#endif