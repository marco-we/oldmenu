#ifndef _MULTIOPTIONITEM__H_
#define _MULTIOPTIONITEM__H_

#include "MenuItem.h"
#include <vector>

/*!
 *  \class MultiOptionItem 
 */
class MultiOptionItem :
	public MenuItem
{
public:

	//! Constructor
	MultiOptionItem( const std::string &name );

	//! Destructor
	~MultiOptionItem();

	//! Processes input
	void process_input( int key );

	//! Processes input
	void process_input( unsigned char key );

	//! Returns entered number
	std::string get_value( void );

	//! Sets the live-variable
	void set_live_variable( std::string *live_var );

	//! Sets value
	void add_option( const std::string &opt );

	//! Returns name of item
	std::string get_name( void );

	//! Returns wether item is selectable or not
	bool selectable( void );

protected:

	std::vector<std::string> m_options;
	std::string *m_pLive_variable;
	unsigned int m_active_item;
};

#endif
