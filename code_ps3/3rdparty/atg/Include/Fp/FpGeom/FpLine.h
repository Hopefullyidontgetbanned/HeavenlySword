//--------------------------------------------------------------------------------------------------
/**
	@file		

	@brief		

	@note		(c) Copyright Sony Computer Entertainment 2005. All Rights Reserved.
**/
//--------------------------------------------------------------------------------------------------

#ifndef FP_LINE_H
#define FP_LINE_H

//--------------------------------------------------------------------------------------------------
//  INCLUDES
//--------------------------------------------------------------------------------------------------

#include	<Fw/FwMaths/FwVector.h>

//--------------------------------------------------------------------------------------------------
//  SWITCHES
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//  MACRO DEFINITIONS
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//  DECLARATIONS
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//  CLASS DEFINITIONS
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
/**
	@class			FpLine

	@brief			Class describing a line (infinite)
**/
//--------------------------------------------------------------------------------------------------

class FpLine
{
public:

	// constructors
	FpLine() {}
	FpLine( const FpLine& rhs );
	FpLine( FwPoint_arg p, FwVector_arg d );

	// setting methods
	FpLine&			operator = ( const FpLine& rhs );
	void			Set( FwPoint_arg p, FwVector_arg d );
	void			SetPoint( FwPoint_arg p );
	void			SetDirection( FwVector_arg d );

	// access
	const FwPoint&	GetPoint() const;
	const FwVector&	GetDirection() const;

protected:

	FwPoint			m_point;							//!< a point on the line
	FwVector		m_direction;						//!< the line's direction

};

//--------------------------------------------------------------------------------------------------
//  INLINE FUNCTION DEFINITIONS
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
/**
	@brief			FpLine constructor

	@param			rhs				-	
**/
//--------------------------------------------------------------------------------------------------

inline FpLine::FpLine( const FpLine& rhs )
: m_point( rhs.m_point )
, m_direction( rhs.m_direction )
{
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			FpLine constructor

	@param			p				-	
	@param			d				-	
**/
//--------------------------------------------------------------------------------------------------

inline FpLine::FpLine( FwPoint_arg p, FwVector_arg d )
: m_point( p )
, m_direction( d )
{
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			

	@param			rhs				-	

	@return			
**/
//--------------------------------------------------------------------------------------------------

inline FpLine&	FpLine::operator = ( const FpLine& rhs )
{
	m_point = rhs.m_point;
	m_direction = rhs.m_direction;
	return *this;
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			

	@param			p				-	
	@param			d				-	
**/
//--------------------------------------------------------------------------------------------------

inline void	FpLine::Set( FwPoint_arg p, FwVector_arg d )
{
	m_point = p;
	m_direction = d;
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			

	@param			s				-	
**/
//--------------------------------------------------------------------------------------------------

inline void	FpLine::SetPoint( FwPoint_arg p )
{
	m_point = p;
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			

	@param			d				-	
**/
//--------------------------------------------------------------------------------------------------

inline void	FpLine::SetDirection( FwVector_arg d )
{
	m_direction = d;
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			

	@return			
**/
//--------------------------------------------------------------------------------------------------

inline const FwPoint&	FpLine::GetPoint() const
{
	return m_point;
}

//--------------------------------------------------------------------------------------------------
/**
	@brief			

	@return			
**/
//--------------------------------------------------------------------------------------------------

inline const FwVector&	FpLine::GetDirection() const
{
	return m_direction;
}

#endif // FP_LINE_H