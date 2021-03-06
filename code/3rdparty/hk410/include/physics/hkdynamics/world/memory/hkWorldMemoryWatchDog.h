/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HK_DYNAMICS2_WORLD_MEMORY_WATCH_DOG_H
#define HK_DYNAMICS2_WORLD_MEMORY_WATCH_DOG_H

class hkWorld;
class hkStepInfo;
#include <hkbase/monitor/hkMonitorStream.h>
#include <hkbase/memory/hkMemory.h>

/// You should use this class to remove objects from your game, if memory is running low.
class hkWorldMemoryWatchDog : public hkReferencedObject
{
	public:

		HK_DECLARE_REFLECTION();

			/// Constructor takes a memory limit threshold above which freeMemory() will be called.
		inline hkWorldMemoryWatchDog( hkInt32 memoryLimit );

			/// A utility function to ask the memory manager how much memory is used.
		static HK_FORCE_INLINE hkInt32 HK_CALL getMemoryUsed();

			/// A utility function to check how much memory is being used. This calls freeMemory() if
			/// the memory usage exceeds the memory limit.
		HK_FORCE_INLINE void watchMemory( hkWorld* world );

			/// This function is called when the memory limit is exceeded. You should derive
			/// from this class and implement this function. Typically, you should remove
			/// unimportant rigid bodies from the world in this function to reduce the memory
			/// consumption of the engine.
		virtual void freeMemory( hkWorld* world ) = 0;

	public:

			// Once the used memory breaches this limit, the watchdog should start to delete hkWorldObjects
		hkInt32 m_memoryLimit;

};

#include <hkdynamics/world/memory/hkWorldMemoryWatchdog.inl>

#endif // HK_DYNAMICS2_WORLD_MEMORY_WATCH_DOG_H

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
