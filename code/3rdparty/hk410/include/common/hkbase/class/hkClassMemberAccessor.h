/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */
#ifndef HK_BASE_CLASS_MEMBER_ACCESSOR_H
#define HK_BASE_CLASS_MEMBER_ACCESSOR_H

class hkClass;
class hkClassMember;
class hkClassAccessor;

	/// Access a data block generically through its hkClass.
	/// This class is used by the versioning code which needs
	/// to access class members from old versions without
	/// seeing the compile-time class definition.
class hkClassMemberAccessor
{
	public:

		HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR( HK_MEMORY_CLASS_HKCLASS, hkClassMemberAccessor );

		/// 
		typedef void* Pointer;
		/// 
		typedef char* Cstring;

			///
		struct SimpleArray
		{
			void* data;
			int size;
		};


			/// Access the given member. Always succeeds.
		hkClassMemberAccessor( void* object, const hkClassMember* member );

			/// Access the named member. Check for success with isOk().
		hkClassMemberAccessor(hkVariant& v, const char* memberName);

			/// Access the named member. Check for success with isOk().
		hkClassMemberAccessor(void* object, const hkClass& klass, const char* memberName);

			/// Return false if not connected to a member.
		hkBool isOk() const;

			/// Get the member that the accessor references. Check isOk() before calling. 
		const hkClassMember& getClassMember() const;

			/// Return the raw memory location of this member.
		void* asRaw() const; //XXX rename to getAddress
		void* getAddress() const;

			/// Access this member as a pointer.
		Pointer& asPointer(int index=0) const;

			/// Access this member as a c-style string.
		Cstring& asCstring(int index=0) const;

			/// Access this member as an hkBool.
		hkBool& asBool(int index=0) const;

			/// Access this member as an hkReal.
		hkReal& asReal(int index=0) const;

			/// Access this member as a 32 bit integer.
		hkInt32& asInt32(int index=0) const;

			/// Access this member as a 16 bit integer.
		hkInt16& asInt16(int index=0) const;

			/// Access this member as an 8 bit integer.
		hkInt8& asInt8(int index=0) const;
			/// Access this member as a 8 bit unsigned integer.
		hkUint8& asUint8(int index=0) const;

			/// Access this member as a void*, int pair.
		SimpleArray& asSimpleArray(int index=0) const;

			/// Access this member as a hkVariant.
		hkVariant& asVariant(int index=0) const;
		
		struct Vector4
		{
			void setCross( const Vector4& v1, const Vector4& v2)
			{
				r[0] = v1.r[1]*v2.r[2] - v1.r[2]*v2.r[1];
				r[1] = v1.r[2]*v2.r[0] - v1.r[0]*v2.r[2];
				r[2] = v1.r[0]*v2.r[1] - v1.r[1]*v2.r[0];
				r[3] = 0;
			}
			hkReal r[4];
		};

			/// Access this member as a hkVector4.
		Vector4& asVector4(int index=0) const;
		
		struct Matrix3 { Vector4 v[3]; };

			/// Access this member as a hkMatrix3.
		Matrix3& asMatrix3(int index=0) const;

		struct Transform { Vector4 r[3]; Vector4 t; };

		/// Access this member as a hkMatrix3.
		Transform& asTransform(int index=0) const;

		typedef Matrix3 Rotation;

		/// Access this member as a hkRotation.
		Rotation& asRotation(int index=0) const;

			///XXX fixme name
		hkClassMemberAccessor member(const char* name) const;

			///XXX fixme name
		hkClassAccessor object() const;

	private:

		void connect( void* object, const hkClassMember* member );

		void connect( void* object, const hkClass& klass, const char* memberName );

	private:

			// the address of the member
		void* m_address;
			// the corresponding class member
		const hkClassMember* m_member;
};

	/// Access a data block generically through its hkClass.
	/// This class is used by the versioning code which needs
	/// to access class members from old versions without
	/// seeing the compile-time class definition.
class hkClassAccessor
{
	public:

			/// Create a class accessor.
		hkClassAccessor(void* object, const hkClass* klass);

			/// Create a class accessor.
		hkClassAccessor(hkVariant& v);

			/// Access a member by name.
		inline hkClassMemberAccessor member(const char* memberName) const;

			/// Access a member explicitly.
		inline hkClassMemberAccessor member(const hkClassMember* mem) const;

			/// Get the class of this object.
		inline const hkClass& getClass() const;

			/// Get the address of this object.
		inline void* getAddress() const;

	private:

			///
		void* m_object;
			///
		const hkClass* m_class;
};

hkClassMemberAccessor hkClassAccessor::member(const char* memberName) const
{
	return hkClassMemberAccessor(m_object, *m_class, memberName);
}

hkClassMemberAccessor hkClassAccessor::member(const hkClassMember* mem) const
{
	return hkClassMemberAccessor(m_object, mem);
}

const hkClass& hkClassAccessor::getClass() const
{
	return *m_class;
}

void* hkClassAccessor::getAddress() const
{
	return m_object;
}

#endif // HK_BASE_CLASS_MEMBER_ACCESSOR_H

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
