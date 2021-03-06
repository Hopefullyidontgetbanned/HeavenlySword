/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#include <hkbase/hkBase.h>
#include <hkbase/memory/hkStackTracer.h>

#if defined(HK_PLATFORM_WIN32) && defined(HK_COMPILER_MSVC) && (HK_COMPILER_MSVC_VERSION >= 1300)
#	include <hkbase/memory/impl/hkStackTracerWin32.cxx> // uses Imagehlp, does not compile in VC6 at the moment
#elif defined(HK_PLATFORM_UNIX) \
	|| (defined(HK_ARCH_PS2) && !defined(HK_COMPILER_MWERKS)) \
	|| defined( HK_PLATFORM_PSP )
	// backtrace does not work for mwerks HVK-1542
#	include <hkbase/memory/impl/hkStackTracerGnu.cxx>
#elif defined(HK_ARCH_IA32) // Xbox and VC6
#	include <hkbase/memory/impl/hkStackTracerIa32.cxx>
#elif defined (HK_PLATFORM_XBOX360)
#	include <hkbase/memory/impl/hkStackTracerXBox360.cxx>
#elif defined (HK_PLATFORM_PS3)
#	include <hkbase/memory/impl/hkStackTracerPs3.cxx>
#else
#	include <hkbase/memory/impl/hkStackTracerNull.cxx>
#endif

/*
* Havok SDK - PUBLIC RELEASE, BUILD(#20060902)
*
* Confidential Information of Havok.  (C) Copyright 1999-2006 
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
*
* Use of this software for evaluation purposes is subject to and indicates 
* acceptance of the End User licence Agreement for this product. A copy of 
* the license is included with this software and is also available from salesteam@havok.com.
*
*/
