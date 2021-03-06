/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

hkSimpleContactConstraintData::~hkSimpleContactConstraintData()
{
	if ( m_atom )
	{
		hkSimpleContactConstraintAtomUtil::deallocateAtom(m_atom);
	}
}

inline int hkSimpleContactConstraintData::getNumContactPoints()
{
	return m_atom->m_numContactPoints;
}

const hkContactPointId hkSimpleContactConstraintData::getContactPointIdAt( int id )
{
	int rid = m_idMgrA.indexOf( id );
	return hkContactPointId( rid ); 

}

inline hkContactPoint& hkSimpleContactConstraintData::getContactPoint( hkContactPointId id )
{
	return m_atom->getContactPoints()[m_idMgrA.m_values[id]]; 
}


inline hkContactPointProperties& hkSimpleContactConstraintData::getContactPointProperties( hkContactPointId id )
{
	return m_atom->getContactPointProperties()[m_idMgrA.m_values[id]];
}



/*
* Havok SDK - CLIENT RELEASE, BUILD(#20060902)
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
