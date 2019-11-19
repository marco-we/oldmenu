#ifndef _INTEGERFIELDITEMS__H_
#define _INTEGERFIELDITEMS__H_

#include "MenuItem.h"

/*!
 *  \class IntegerFieldItem
 */
class IntegerFieldItem :
	public MenuItem
{
public:

	//! Constructor
	IntegerFieldItem( const std::string &name );

	//! Destructor
	~IntegerFieldItem();

	//! Processes input
	void process_input( int key );

	//! Processes input
	void process_input( unsigned char key );

	//! Returns entered number
	int get_value( void );

	//! Sets the live-variable
	void set_live_variable( int *live_var );

	//! Sets value
	void set_value( int );

	//! Returns name of item
	std::string get_name( void );

	//! Sets the minimum value
	void set_min_value( int min );

	//! Sets the maximum
	void set_max_value( int min );

	//! Returns wether item is selectable or not
	bool selectable( void );

protected:

	int m_value;
	int *m_live_variable;
	int m_min, m_max;
	
};

#endif

