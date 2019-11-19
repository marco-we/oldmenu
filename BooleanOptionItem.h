#ifndef _BOOLEANOPTIONITEM__H_
#define _BOOLEANOPTIONITEM__H_

#include "MenuItem.h"

/*!
 *  \class BooleanOptionItem
 */
class BooleanOptionItem :
	public MenuItem
{
public:

	//! Constructor
	BooleanOptionItem( const std::string &name );

	//! Destructor
	~BooleanOptionItem();

	//! Processes input
	void process_input( int key );

	//! Processes input
	void process_input( unsigned char key );

	//! Returns entered number
	bool get_value( void );

	//! Sets the live-variable
	void set_live_variable( bool *live_var );

	//! Sets value
	void set_value( bool val );

	//! Returns name of item
	std::string get_name( void );

	//! Returns wether item is selectable or not
	bool selectable( void );

protected:

	bool m_value;
	bool *m_pLive_variable;

};

#endif